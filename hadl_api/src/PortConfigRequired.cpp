#include "PortConfigRequired.hpp"


void PortConfigRequired::bindTo( PortComposantRequired* portRequired ) {
	_bindingRequired = portRequired;
}

MessageP PortConfigRequired::send_message( MessageP msg ) {
	if ( _bindingRequired != NULL ) {
		return _bindingRequired->send_message(msg);
	}
}