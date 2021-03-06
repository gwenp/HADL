#include "CS_Connector.hpp"

CS_Connector::CS_Connector() {
	init_exit_signals();
}

CS_Connector::~CS_Connector() {

}

void CS_Connector::onInit() {

	std::cout << "+++++ INIT CONNECTOR ++++++" << std::endl;

	const std::string& client_server = getProperty("mode");

	int port = atoi( getProperty("port").c_str() );
	if ( port <= 0 ) {
		std::cout << "Bad properties (port)" << std::endl;
		return;
	}

	if ( client_server.compare("client") == 0 ) {

		const std::string& host = getProperty("host");

		if ( host.empty() ) {
			std::cout << "Bad properties (host)" << std::endl;
			return;		
		}

		_rolesRequired.clear();
		std::cout << "CLIENT MODE\n";
		SOCKET sock = this->connect_to( host, port );
		//this->monitoring_routine( sock );

	}
	else {
		_rolesProvided.clear();
		std::cout << "SERVER MODE\n";
		this->listen_from(port);
	}

}

MessageP CS_Connector::glue_message_propagation( MessageP msg, const std::string& role ) {

	if ( _rolesRequired.find( role ) != _rolesRequired.end() ) {
		/* Direct sending */
		return _rolesRequired[role]->propagate_message( msg );
	}
	else if ( _rolesRequired_connections.find( role ) != _rolesRequired_connections.end() ) {
		/* Network sending */
		return this->send_message_ntk(_rolesRequired_connections[role],msg);
	}


}


void CS_Connector::wait_for_messages_ntk( SOCKET sock ) {


	char* buffer = NULL;
	char* buffer_tmp = (char*) malloc(4096);

	int current_offset = 0;

	delimited_data_t message_data = { -1, NULL };

	int recv_size;
	int buffer_size = 0;

	int remaining_data = -1;

	do {

		/* If no data, read from network */
		if ( buffer_size == 0 ) {

			if ( ( recv_size = receive_data(sock, buffer_tmp) ) < 0 )  {

				std::cout << "Disconnecting from a peer...\n";
				
				int ret = -1;
				pthread_exit(&ret);

			}

		}
		else {
			recv_size = buffer_size;
		}

		/* If message data beginning */ 
		if ( current_offset == 0 ) {

			if ( recv_size < sizeof(int32_t) ) {
				std::cout << "Not enough\n";
				exit(1);
			}

			int32_t util_size;
			memcpy(&util_size,buffer_tmp,sizeof(int32_t));

			//std::cout << "Incoming message of size " << util_size << std::endl;

			message_data.length = util_size;
			message_data.data = (char*) malloc( message_data.length );

			buffer_size = recv_size - sizeof(int32_t);
			buffer = (char*) malloc(buffer_size);
			memcpy(buffer,&buffer_tmp[sizeof(int32_t)],buffer_size);
			
		}
		/* If message data is already loading */
		else {
			buffer_size = recv_size;
			buffer = (char*) malloc(buffer_size);
			memcpy(buffer,buffer_tmp,recv_size);
		}

		remaining_data = message_data.length - current_offset;

		int size_to_copy = remaining_data;
		if ( message_data.length > buffer_size ) {
			size_to_copy = buffer_size;
		}

		memcpy(&message_data.data[current_offset],buffer,size_to_copy);
		current_offset += size_to_copy;
		buffer_size -= size_to_copy;

		/* If remaining data in buffer */
		if ( buffer_size != 0 ) {
			memcpy(buffer_tmp,&buffer[size_to_copy],buffer_size);
		}

		//std::cout << "Buffer size after reading : " << buffer_size << std::endl;


		remaining_data = message_data.length - current_offset;

		/* If message data successfully loaded */
		if ( remaining_data == 0 ) {

			current_offset = 0;

			MessageP msg;
			std::string cpp_string( message_data.data, message_data.length );
			message_data = { 0, NULL }; // Reset
			
			if ( msg.ParseFromString(cpp_string) ) {
				/* Add to message queue */
				_messages_queue.push(msg);
			}

		}

	} while( remaining_data != 0 || buffer_size != 0 );

}



MessageP CS_Connector::receive_message_ntk( SOCKET sock ) {

	while ( _messages_queue.empty() ) {

		//std::cout << "Empty queue. Receiving through network" << std::endl;
		this->wait_for_messages_ntk( sock );

	}

	MessageP msg = _messages_queue.front();
	_messages_queue.pop();

	return msg;

}

MessageP CS_Connector::send_message_ntk( SOCKET sock, MessageP& msg, bool needs_response ) {

	msg.set_sender("[]")	;

	std::string cpp_string;
	msg.SerializeToString(&cpp_string);

	int size = cpp_string.size();

	if ( send_data(sock,cpp_string.data(),size) > 0 ) {
		//std::cout << "Message sent\n";
	}

	if ( needs_response && msg.type() != MessageP::RESPONSE ) {
		return receive_message_ntk(sock);
	}
	else {
		return msg;
	}

}



void CS_Connector::exchange_discoveries_ntk( SOCKET sock ) {
	this->send_discoveries_ntk(sock);

	for ( int i=0; i<2; i++ ) {
		MessageP msg = receive_message_ntk(sock);
		
		if ( msg.has_type() ) {
			this->on_message_received_ntk( msg, sock );
		}
		else {
			std::cout << "Bad message received (dropped)" << std::endl;
		}
	}

}

void CS_Connector::send_discoveries_ntk( SOCKET sock ) {

	MessageP disco_msg_pd = generate_discovery_message( MessageP::PROVIDED );
	this->send_message_ntk( sock, disco_msg_pd, false );

	MessageP disco_msg_rq = generate_discovery_message( MessageP::REQUIRED );
	this->send_message_ntk( sock, disco_msg_rq, false );


}

void* monitoring_routine_rebound( void* data ) {

	connector_and_sock_t* cs = (connector_and_sock_t*) data;
	SOCKET sock = cs->socket;
	CS_Connector* connector = (CS_Connector*) cs->connector;


	std::cout << "A client was connected ! Waiting for message\n";

	connector->monitoring_routine( sock );

}

SOCKET CS_Connector::connect_to( std::string host, int port ) {

	SOCKET sock = connect_to_server(host.c_str(),port);

	exchange_discoveries_ntk(sock);

	return sock;

}

void CS_Connector::monitoring_routine( SOCKET sock ) {

	/* Firstly, we send all directly reachable Roles */
	//this->send_discoveries_ntk( sock );
	this->exchange_discoveries_ntk(sock);
	// TODO
	while ( true ) {
	
		MessageP msg = receive_message_ntk(sock);
		
		if ( msg.has_type() ) {
			this->on_message_received_ntk( msg, sock );
		}
		else {
			std::cout << "Bad message received (dropped)" << std::endl;
		}

	}

}

void CS_Connector::listen_from( int port ) {

	connector_port_callback_t cp = { this, port, &monitoring_routine_rebound };

	std::cout << "Put port : " << cp.port << std::endl;

	pthread_t thread;
	pthread_create(&thread, NULL, wait_for_clients, (void *)&cp);

	// To remove
	pthread_join(thread, NULL);
}

MessageP CS_Connector::generate_discovery_message( MessageP::DiscoverType disco_type ) {

	MessageP disco_msg;
	disco_msg.set_type(MessageP::DISCOVER);
	disco_msg.set_discover_type(disco_type);
	disco_msg.set_receiver("[any]");

	std::map<std::string, Role*> roles;

	if ( disco_type == MessageP::REQUIRED ) {
		std::map<std::string, RoleRequired*>::iterator iter;
		for ( iter = _rolesRequired.begin(); iter != _rolesRequired.end(); iter++ ) {
			disco_msg.add_argument( (*iter).first );
		}	
	}
	else {
		std::map<std::string, RoleProvided*>::iterator iter;
		for ( iter = _rolesProvided.begin(); iter != _rolesProvided.end(); iter++ ) {
			disco_msg.add_argument( (*iter).first );
		}	
	}

	return disco_msg;

}


void CS_Connector::interpret_discovery_message( MessageP msg, SOCKET sock ) {

	if ( msg.discover_type() == MessageP::REQUIRED ) {

		for( int i=0; i<msg.argument_size(); i++ ) {
			std::string role = msg.argument(i);
			_rolesRequired_connections[role] = sock;
			//_rolesRequired_connections_reverse[sock] = role;
		}

	}
	else {

		for( int i=0; i<msg.argument_size(); i++ ) {
			std::string role = msg.argument(i);
			_rolesProvided_connections[role] = sock;
			//_rolesProvided_connections_reverse[sock] = role;
		}

	}

}


void CS_Connector::on_message_received_ntk( MessageP& msg, SOCKET sock ) {

	switch( msg.type() ) {
		case MessageP::DISCOVER:
			this->interpret_discovery_message(msg, sock);
			break;
		default:
			MessageP msg_response = this->propagate_message(msg,msg.receiver());
			std::cout << "Sending response...\n";
			this->send_message_ntk(sock, msg_response, false);
			std::cout << "Ok !\n";
			break;
	}
	// Switch/case here

}