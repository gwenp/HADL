#include "PortComposantRequired.hpp"

#include "RoleProvided.hpp"


void PortComposantRequired::propagateNotificationToRole()
{
	if(_providedRole != NULL)
	{
		_providedRole->notifyConnector();		
	}
	else
		std::cout << "[ERROR] No Connector attached to the port" <<std::endl;

}

MessageP PortComposantRequired::send_message( str_v args ) {

	MessageP msg;
	for ( int i=0; i<args.size(); i++ ) {
		msg.add_argument( args.at(i) );
	}
	return _providedRole->propagate_message( msg );

}