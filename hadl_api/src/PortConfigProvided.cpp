#include "PortConfigProvided.hpp"

void PortConfigProvided::bindTo( PortComposantProvided* portProvided ) {
	_bindingProvided = portProvided;
}

MessageP PortConfigProvided::receive_message( MessageP msg ) {
	
	std::cout << "@@@ Passage par PortConfigFourni @@@\n";

	if ( _bindingProvided != NULL ) {

		MessageP response_msg = _bindingProvided->receive_message(msg);
		std::cout << "<<< Retourne par PortConfigFourni <<<\n";
		return response_msg;
	}
	else {
		std::cout << "Binding NOT FOUND\n";
	}
}