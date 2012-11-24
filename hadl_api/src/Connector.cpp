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
		//this->send_message(_rolesRequired_connections[roleRequired],msg);
	}


}


/* Bad side */


void debug_message( MessageP& msg ) {

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

}

void Connector::wait_for_messages( SOCKET sock ) {


	char str[8192];
	int nb_bytes = receive_data( sock, str );

	if ( nb_bytes < 0 ) {
		std::cout << "Communication error\n";

		exit(-1);
	}

	std::cout << "Propagated " << sizeof(str) << " bytes\n";
	_rcv_messages_buffer.append(str,nb_bytes);

 	/* While there is data to read	*/
	while ( _rcv_messages_buffer.size() > 0 ) {

		std::cout << nb_bytes << " bytes remaining ("<< _rcv_messages_buffer.size() << ")\n";

		MessageP msg;

		/* Try to interpret data as a message */
		if ( msg.ParseFromString( _rcv_messages_buffer ) ) {

			_messages_queue.push(msg);

			int nb_bytes_consumed = msg.ByteSize();
			std::cout << "Byte size ::: " << nb_bytes_consumed << std::endl; 

			nb_bytes -= nb_bytes_consumed;
			_rcv_messages_buffer.erase (0,nb_bytes_consumed);

		}
		/* There is no enought data to interpret the MessageP */
		else {
			
			int nb_bytes_consumed = msg.ByteSize();
			std::cout << "Byte size ::: " << nb_bytes_consumed << std::endl; 


			std::cout << "(Not complete, waiting for more data)\n";
			return;
		}

	}

}

MessageP Connector::receive_message( SOCKET sock ) {

	while ( _messages_queue.empty() ) {

		std::cout << "Empty queue. Receiving through network" << std::endl;
		this->wait_for_messages( sock );

	}

	std::cout << "(" << _messages_queue.size() << ") Poping message ...\n";

	MessageP msg = _messages_queue.front();
	_messages_queue.pop();

	return msg;

}

MessageP Connector::send_message( SOCKET sock, MessageP& msg, bool needs_response ) {

	msg.set_sender("Test1")	;

	std::cout << "To send :\n";
	debug_message(msg);

	std::string cpp_string;
	msg.SerializeToString(&cpp_string);

	int size = cpp_string.size();

	char* cstr = new char[size+1];
	cstr[size] = 0;
	memcpy( cstr, cpp_string.data(), size );

	if ( send_data(sock,cstr,size) > 0 ) {
		std::cout << "Message sent\n";
	}

	if ( needs_response ) {
		return receive_message(sock);
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


void Connector::send_discoveries( SOCKET sock ) {

	MessageP disco_msg_pd = generate_discovery_message( MessageP::PROVIDED );
	this->send_message( sock, disco_msg_pd, false );

	MessageP disco_msg_rq = generate_discovery_message( MessageP::REQUIRED );
	this->send_message( sock, disco_msg_rq, false );


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
	this->send_discoveries( sock );

	// TODO
	while ( true ) {
	
		MessageP msg = receive_message(sock);
		
		if ( msg.has_type() ) {
			this->on_message_received( msg, sock );
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
	disco_msg.set_receiver("");

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


void Connector::on_message_received( MessageP& msg, SOCKET sock ) {

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
		return this->send_message(_rolesRequired_connections[role],msg);
	}


}