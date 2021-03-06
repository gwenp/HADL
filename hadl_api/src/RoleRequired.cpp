#include "RoleRequired.hpp"

#include "PortComposantProvided.hpp"
#include "Connector.hpp"

MessageP RoleRequired::propagate_message( MessageP msg ) {

	std::cout << "@@@ Passage par RoleRequis '" << _name << "' @@@\n";

	MessageP response_msg;
	/* Return to sender */
	response_msg.set_receiver(msg.sender());
	response_msg.set_type(MessageP::RESPONSE);

	if ( _portProvided != NULL ) {

		response_msg = _portProvided->receive_message( msg );
		std::cout << "<<< Retourne par RoleRequis '" << _name << "' <<<\n";

	}
	else {
		std::cout << "Port provided not found\n";
	}

	return response_msg;

}


void RoleRequired::attachToPortProvided( PortComposantProvided* port ) {

	if ( _portProvided != port ) {
		_portProvided = port;
	}

}