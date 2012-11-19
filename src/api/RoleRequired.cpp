#include "RoleRequired.hpp"

#include "PortComposantProvided.hpp"

void RoleRequired::propagateNotificationToPort()
{
	if(_portProvided != NULL)
	{
		_portProvided->notifyComponent();
	}
	else
		std::cout << "[ERROR] No Component attached to the role" <<std::endl;
}