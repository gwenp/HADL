#include "RoleRequired.hpp"

#include "PortComposantProvided.hpp"

void RoleRequired::propagateNotificationToPort()
{
	_portProvided->notifyComponent();
}