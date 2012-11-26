#include "PortConfigProvided.hpp"

void PortConfigProvided::bindTo( PortComposantProvided* portProvided ) {
	_bindingProvided = portProvided;
}

MessageP PortConfigProvided::receive_message( MessageP msg ) {
	if ( _bindingProvided != NULL ) {

		return _bindingProvided->receive_message(msg);
	}
	else {
		std::cout << "Binding NOT FOUND\n";
	}
}