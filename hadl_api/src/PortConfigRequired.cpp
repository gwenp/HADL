#include "PortConfigRequired.hpp"


void PortConfigRequired::bindTo( PortComposantRequired* portRequired ) {
	_bindingRequired = portRequired;
}

str_v PortConfigRequired::send_message( str_v args ) {

	std::cout << "@@@ Passage par PortConfigRequis '" << _name << "' @@@\n";
	std::cout << "--- Sent arguments : " << std::endl;
	for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it) {
		std::cout << "+ " << (*it) << std::endl;
	}

	if ( _bindingRequired != NULL ) {

		str_v ret_vector = _bindingRequired->send_message(args);
		std::cout << "<<< Retourne par PortConfigRequis <<<\n";
		
		return ret_vector;

	}
	else {
		std::cout << "BindingRequired not found" << std::endl;
	}
}