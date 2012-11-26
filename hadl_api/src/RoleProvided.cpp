#include "RoleProvided.hpp"

#include "Connector.hpp"

MessageP RoleProvided::propagate_message( MessageP msg ) {

	/* STUB */
	std::string _name = "provided_role_1";
	
	msg.set_sender(_name);
	return _connector->on_message_from_provided_role( this, msg );

}
