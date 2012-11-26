#include "PortConfigRequired.hpp"


void PortConfigRequired::bindTo( PortComposantRequired* portRequired ) {
	_bindingRequired = portRequired;
}

str_v PortConfigRequired::send_message( str_v args ) {
	if ( _bindingRequired != NULL ) {
		return _bindingRequired->send_message(args);
	}
	else {
		std::cout << "BindingRequired not found" << std::endl;
	}
}