#include "RoleConfigProvided.hpp"

void RoleConfigProvided::bindTo( RoleProvided* roleProvided ) {
	_bindingProvided = roleProvided;
}

MessageP RoleConfigProvided::propagate_message( MessageP msg ) {

	if ( _bindingProvided != NULL ) {
		return _bindingProvided->propagate_message(msg);
	}
	else {
		std::cout << "BindingRequired not found" << std::endl;
	}

}
