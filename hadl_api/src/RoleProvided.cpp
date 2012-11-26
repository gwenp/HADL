#include "RoleProvided.hpp"

#include "Connector.hpp"

MessageP RoleProvided::propagate_message( MessageP msg ) {

	std::cout << "@@@ Passage par RoleFourni @@@\n";

	if ( _connector != NULL ) {

		MessageP response_msg = _connector->on_message_from_provided_role( this, msg );

		std::cout << "<<< Retourne par RoleFourni <<<	\n";

		return response_msg;
	}
	else {
		MessageP merror;
		merror.set_type(MessageP::RESPONSE);
		merror.set_sender("");
		merror.set_receiver(msg.sender());
		std::cout << "Connector not found\n";

		return merror;
	}

}
