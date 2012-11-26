#include "RoleProvided.hpp"

#include "Connector.hpp"

MessageP RoleProvided::propagate_message( MessageP msg ) {
	
	if ( _connector != NULL ) {
		return _connector->on_message_from_provided_role( this, msg );
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
