#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include "ConnectableElement.hpp"
#include "Configuration.hpp"
#include "InterfaceConnector.hpp"
#include "RoleProvided.hpp"
#include "RoleRequired.hpp"

#include <map>
#include <string>
#include <iostream>

/* Bad side */

#include "MessageP.pb.h"

extern "C" {
	#include "networking.h"
}


class Component;

class Connector : public ConnectableElement
{
public:
	void addRoleProvided(std::string name, RoleProvided* roleProvided);
	void addRoleRequired(std::string name, RoleRequired* roleRequired);

	void info();
	void on_notify(RoleProvided* port);

	void attachToComponent(Component* c, std::string roleName, std::string portName);

	void sendNotificationTo(std::string roleRequired); //this should be protected in the future

	std::map<std::string, RoleProvided*> _rolesProvided;
	std::map<std::string, RoleRequired*> _rolesRequired;

	/* Other side */



	void launch_monitoring_routines(); // Listen

	void monitoring_routine( SOCKET sock );

	void connect();

private:

	Configuration* _linkedConfiguration;

	/* Other side */

	MessageP generate_discovery_message();
	void interpret_discovery_message( MessageP msg, SOCKET sock );

	SOCKET connect_to( std::string host, int port ); // Connect

	MessageP wait_for_message( SOCKET sock );
	MessageP send_message( SOCKET sock, MessageP& msg );

	void on_message_received( MessageP& msg );

	// Temp ? Can be used to store Roles
	std::map<std::string, SOCKET> _socket_connections;
	std::map<SOCKET,std::string> _socket_connections_reverse;

};

#endif /* CONNECTOR_HPP */