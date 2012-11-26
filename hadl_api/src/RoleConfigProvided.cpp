#include "RoleConfigProvided.hpp"

void RoleConfigProvided::bindTo( RoleProvided* roleProvided ) {
	_bindingProvided = roleProvided;
}

MessageP RoleConfigProvided::propagate_message( MessageP msg ) {

	std::cout << "@@@ Passage par  '" << _name << "' @@@\n";

	if ( _bindingProvided != NULL ) {
		return _bindingProvided->propagate_message(msg);
	}
	else {
		std::cout << "BindingRequired not found" << std::endl;
	}

}
