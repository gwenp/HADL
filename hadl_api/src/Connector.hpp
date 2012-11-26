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

class Component;

class Connector : public ConnectableElement
{
public:
	//Connector() { _messages_queue = std::queue<MessageP>(); }

	void addRoleProvided(std::string name, RoleProvided* roleProvided, std::string& linkedRole );
	void addRoleRequired(std::string name, RoleRequired* roleRequired);

	void info();
	//void on_notify(RoleProvided* port);

	void attachToComponent(Component* c, std::string roleName, std::string portName);

	// Doublon
	//void sendNotificationTo(std::string roleRequired, MessageP& message ); //this should be protected in the future

	std::map<std::string, RoleProvided*> _rolesProvided;
	std::map<std::string, RoleRequired*> _rolesRequired;


	/* Other side */

	MessageP on_message_from_provided_role( RoleProvided* from, MessageP msg );
	MessageP propagate_message( MessageP msg, const std::string& role );

	static MessageP error_message( std::string error ) {

		MessageP msg;
		msg.set_sender("");
		msg.set_receiver("");
		//msg.set_code(-1);
		msg.add_argument("Error : " + error );

		return msg;

	}

protected:

		/* For debuging */
	void debug_message( MessageP& msg );

	virtual MessageP glue_message_propagation( MessageP msg, const std::string& role );

	Configuration* _linkedConfiguration;

	/* How to know to which ROle a message should be sent */
	std::map<RoleProvided*,std::string> _roles_association;
};

#endif /* CONNECTOR_HPP */