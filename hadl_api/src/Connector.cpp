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

void Connector::sendNotificationTo(std::string roleRequired)
{
	_rolesRequired[roleRequired]->propagateNotificationToPort();
}


/* Bad side */


void debug_message( MessageP& msg ) {
	
	std::cout << "New message ! --> " << std::endl;

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

MessageP Connector::wait_for_message( SOCKET sock ) {

	MessageP msg;

	char str[8192];
	int size = receive_data( sock, str );
	if ( size > 0 ) {
		std::cout << "Propagated " << sizeof(str) << " bytes\n";
		std::string cpp_string(str,size);
		msg.ParseFromString( cpp_string );
	}

	return msg;
}

MessageP Connector::send_message( SOCKET sock, MessageP& msg ) {

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

	return msg;

}




void Connector::connect() {
	std::cout << "Connecting ..." << std::endl;
	SOCKET sock = this->connect_to("127.0.0.1",2345);

	if ( sock == INVALID_SOCKET ) {
		std::cout << "Bad socket ?\n";
		return;
	}

		MessageP disco_msg = generate_discovery_message();

		this->send_message( sock, disco_msg );

		monitoring_routine( sock );
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


	MessageP msg = wait_for_message(sock);
	
	if ( msg.has_type() ) {
		this->on_message_received( msg );
		return;
	}

	std::cout << "Bad message received (dropped)" << std::endl;
}

void Connector::launch_monitoring_routines() {

	connector_port_callback_t cp = { this, 2345, &monitoring_routine_rebound };

	std::cout << "Put port : " << cp.port << std::endl;

	pthread_t thread;
	pthread_create(&thread, NULL, wait_for_clients, (void *)&cp);

	// To remove
	pthread_join(thread, NULL);
}

MessageP Connector::generate_discovery_message() {

	MessageP disco_msg;
	disco_msg.set_type(MessageP::DISCOVER);
	disco_msg.set_receiver("");

	std::map<std::string, RoleProvided*>::iterator iter;
	for ( iter = _rolesProvided.begin(); iter != _rolesProvided.end(); iter++ ) {
		disco_msg.add_argument( (*iter).first );
	}

	return disco_msg;

}


void Connector::interpret_discovery_message( MessageP msg, SOCKET sock ) {

	for( int i=0; i<msg.argument_size(); i++ ) {
		std::string role = msg.argument(i);
		_socket_connections[role] = sock;
		_socket_connections_reverse[sock] = role;
	}

}


void Connector::on_message_received( MessageP& msg ) {

	debug_message(msg);

	// Switch/case here

}