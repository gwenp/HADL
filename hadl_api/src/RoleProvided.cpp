#include "RoleProvided.hpp"

#include "Connector.hpp"

void RoleProvided::notifyConnector()
{
	getConnector()->on_notify(this);
}

MessageP RoleProvided::propagate_message( MessageP msg ) {

	std::string _name = "provided_role_1";
	
	msg.set_sender(_name);
	return _connector->propagate_message( msg );

}
