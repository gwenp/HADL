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

MessageP PortComposantRequired::send_message( MessageP msg ) {

	return _providedRole->propagate_message( msg );

}