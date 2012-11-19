#include "PortComposantRequired.hpp"

#include "RoleProvided.hpp"


void PortComposantRequired::propagateNotificationToRole()
{
	std::cout << "PortComposantRequired::propagateNotificationToRole" <<std::endl;
	_providedRole->notifyConnector();
}