#include "RoleRequired.hpp"

#include "PortComposantProvided.hpp"
#include "Connector.hpp"

/*
void RoleRequired::propagateNotificationToPort()
{
	if(_portProvided != NULL)
	{
		_portProvided->notifyComponent();
	}
	else
		std::cout << "[ERROR] No Component attached to the role" <<std::endl;
}
*/

MessageP RoleRequired::propagate_message( MessageP msg ) {

	MessageP response_msg = _portProvided->receive_message( msg );
	
	/* Return to sender */
	response_msg.set_receiver(msg.sender());

	return response_msg;

}
