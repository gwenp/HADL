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