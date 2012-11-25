#include "Connector.hpp"

#include "Component.hpp"

void Connector::addRoleProvided(std::string name, RoleProvided* role)
{
	role->setConnector(this);
	_rolesProvided.insert(std::pair<std::string, RoleProvided*>(name, role));
}

void Connector::addRoleRequired(std::string name, RoleRequired* role)
{
	role->setConnector(this);
	_rolesRequired.insert(std::pair<std::string, RoleRequired*>(name, role));
}

void Connector::info()
{
	std::cout << "Connector:======================" << std::endl
			<< "\t Roles Required :" << std::endl;
	for (std::map<std::string, RoleRequired*>::iterator it = _rolesRequired.begin(); it != _rolesRequired.end(); ++it)
	{
		std::cout << "\t\t" << (*it).first << std::endl;
	}

	std::cout << "\t Roles Provided :" << std::endl;
	for (std::map<std::string, RoleProvided*>::iterator it = _rolesProvided.begin(); it != _rolesProvided.end(); ++it)
	{
		std::cout << "\t\t" << (*it).first << std::endl;
	}

	std::cout << std::endl;
}

void Connector::on_notify(RoleProvided* port)
{
	std::cout << "Connector notification received!" <<std::endl;
}

void Connector::attachToComponent(Component* c, std::string roleName, std::string portName)
{
	if(getParentConfiguration() == c->getParentConfiguration())
	{
		PortComposantProvided* port = c->_portsProvided[portName];
		_rolesRequired[roleName]->_portProvided = port;
	}
	else
		std::cout << "[ERROR] : The Connector and the Component does not have the same parent Configuration!" <<std::endl;
}

void Connector::sendNotificationTo( std::string roleRequired, MessageP& msg ) {

	if ( _rolesRequired.find( roleRequired ) != _rolesRequired.end() ) {
		_rolesRequired[roleRequired]->propagateNotificationToPort();
	}
	else if ( _rolesRequired_connections.find( roleRequired ) != _rolesRequired_connections.end() ) {
		//this->send_message_ntk(_rolesRequired_connections[roleRequired],msg);
	}


}


/* Other side */




MessageP Connector::receive_message_ntk( SOCKET sock ) {

	while ( _messages_queue.empty() ) {

		std::cout << "Empty queue. Receiving through network" << std::endl;
		this->wait_for_messages_ntk( sock );

	}

	MessageP msg = _messages_queue.front();
	_messages_queue.pop();

	return msg;

}

MessageP Connector::send_message_ntk( SOCKET sock, MessageP& msg, bool needs_response ) {

	msg.set_sender("Test1")	;

	std::cout << "To send :\n";
	debug_message(msg);

	std::string cpp_string;
	msg.SerializeToString(&cpp_string);

	int size = cpp_string.size();

	if ( send_data(sock,cpp_string.data(),size) > 0 ) {
		std::cout << "Message sent\n";
	}

	if ( needs_response ) {
		return receive_message_ntk(sock);
	}
	else {
		return msg;
	}

}




void Connector::connect() {
	std::cout << "Connecting ..." << std::endl;

	/* TODO */
	SOCKET sock = this->connect_to("127.0.0.1",2345);

	if ( sock == INVALID_SOCKET ) {
		std::cout << "Bad socket ?\n";
		return;
	}

	this->monitoring_routine( sock );
}


void Connector::send_discoveries_ntk( SOCKET sock ) {

	MessageP disco_msg_pd = generate_discovery_message( MessageP::PROVIDED );
	this->send_message_ntk( sock, disco_msg_pd, false );

	MessageP disco_msg_rq = generate_discovery_message( MessageP::REQUIRED );
	this->send_message_ntk( sock, disco_msg_rq, false );


}

void* monitoring_routine_rebound( void* data ) {

	connector_and_sock_t* cs = (connector_and_sock_t*) data;
	SOCKET sock = cs->socket;
	Connector* connector = (Connector*) cs->connector;


	std::cout << "A client was connected ! Waiting for message\n";

	connector->monitoring_routine( sock );

}

SOCKET Connector::connect_to( std::string host, int port ) {

	SOCKET sock = connect_to_server(host.c_str(),port);

	return sock;

}

void Connector::monitoring_routine( SOCKET sock ) {

	/* Firstly, we send all directly reachable Roles */
	this->send_discoveries_ntk( sock );

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

void Connector::listen_from( int port ) {

	connector_port_callback_t cp = { this, port, &monitoring_routine_rebound };

	std::cout << "Put port : " << cp.port << std::endl;

	pthread_t thread;
	pthread_create(&thread, NULL, wait_for_clients, (void *)&cp);

	// To remove
	pthread_join(thread, NULL);
}

MessageP Connector::generate_discovery_message( MessageP::DiscoverType disco_type ) {

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


void Connector::interpret_discovery_message( MessageP msg, SOCKET sock ) {

	if ( msg.discover_type() == MessageP::REQUIRED ) {

		for( int i=0; i<msg.argument_size(); i++ ) {
			std::string role = msg.argument(i);
			_rolesRequired_connections[role] = sock;
			_rolesRequired_connections_reverse[sock] = role;
		}

	}
	else {

		for( int i=0; i<msg.argument_size(); i++ ) {
			std::string role = msg.argument(i);
			_rolesProvided_connections[role] = sock;
			_rolesProvided_connections_reverse[sock] = role;
		}

	}

	std::cout << "ROLES LIST UPDATED !\n";

}


void Connector::on_message_received_ntk( MessageP& msg, SOCKET sock ) {

	std::cout << "New message ! --> " << std::endl;

	debug_message(msg);

	switch( msg.type() ) {
		case MessageP::DISCOVER:
			this->interpret_discovery_message(msg, sock);
			break;
		default:
			std::cout << "Message type not supported\n";
			break;
	}
	// Switch/case here

}

MessageP Connector::propagate_message( MessageP msg ) {

	/* Get sender ROLE */
	const std::string& role_from = msg.sender();

	/* Find associated ROLE */
	if ( _roles_association.find( role_from ) != _roles_association.end() ) {

		return this->send_message_to_role( msg, _roles_association[role_from] );
	}

	std::cout << "Cannot route message (unknown dest/action)\n";
	/* TODO error message */
	return msg; 
}

MessageP Connector::send_message_to_role( MessageP msg, const std::string& role ) {

	if ( _rolesRequired.find( role ) != _rolesRequired.end() ) {
		/* Direct sending */
		return _rolesRequired[role]->propagate_message( msg );
	}
	else if ( _rolesRequired_connections.find( role ) != _rolesRequired_connections.end() ) {
		/* Network sending */
		return this->send_message_ntk(_rolesRequired_connections[role],msg);
	}


}

void Connector::wait_for_messages_ntk( SOCKET sock ) {


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

				std::cout << "Communication error\n";
				exit(-1);

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


void Connector::debug_message( MessageP& msg ) {

	std::cout << "<------------------------" << std::endl;

	std::cout << "From : " << msg.sender() << std::endl;
	std::cout << "To : " << msg.receiver() << std::endl;
	std::cout << "Type : " << msg.type() << std::endl;

	int size = msg.argument_size();
	if ( size > 0 ) {
		std::cout << "Arguments (" << size <<  ") : " << std::endl;

		for ( int i=0; i<size; i++ ) {
			std::cout << " - " << msg.argument(i) << std::endl;
		}

	}

	std::cout << "------------------------>" << std::endl;


}