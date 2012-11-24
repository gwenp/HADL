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
#include <queue>

/* Bad side */

#include "MessageP.pb.h"

extern "C" {
	#include "networking.h"
}


class Component;

class Connector : public ConnectableElement
{
public:
	//Connector() { _messages_queue = std::queue<MessageP>(); }

	void addRoleProvided(std::string name, RoleProvided* roleProvided);
	void addRoleRequired(std::string name, RoleRequired* roleRequired);

	void info();
	void on_notify(RoleProvided* port);

	void attachToComponent(Component* c, std::string roleName, std::string portName);

	// Doublon
	void sendNotificationTo(std::string roleRequired, MessageP& message ); //this should be protected in the future

	std::map<std::string, RoleProvided*> _rolesProvided;
	std::map<std::string, RoleRequired*> _rolesRequired;

	/* Other side */

	MessageP propagate_message( MessageP msg );


	void listen_from( int port );

	void monitoring_routine( SOCKET sock );

	void connect();

private:

	Configuration* _linkedConfiguration;

	/* Other side */

	/** BEGIN NETWORKING **/
	MessageP generate_discovery_message( MessageP::DiscoverType disco_type );
	void interpret_discovery_message( MessageP msg, SOCKET sock );

	SOCKET connect_to( std::string host, int port ); // Connect

	void wait_for_messages( SOCKET sock );

	MessageP receive_message( SOCKET sock );
	MessageP send_message( SOCKET sock, MessageP& msg, bool needs_response = true );

	void on_message_received( MessageP& msg, SOCKET sock = INVALID_SOCKET );

	void send_discoveries( SOCKET sock );
	/** END NETWORKING **/


	MessageP send_message_to_role( MessageP msg, const std::string& role );

	// Temp ? Can be used to store Roles
	std::map<std::string, SOCKET> _rolesProvided_connections;
	std::map<SOCKET,std::string> _rolesProvided_connections_reverse;

	std::map<std::string, SOCKET> _rolesRequired_connections;
	std::map<SOCKET,std::string> _rolesRequired_connections_reverse;

	/* Used for receiving messages */
	std::queue<MessageP> _messages_queue;
	std::string _rcv_messages_buffer;


	/* How to know to which ROle a message should be sent */
	std::map<std::string,std::string> _roles_association;

};

#endif /* CONNECTOR_HPP */