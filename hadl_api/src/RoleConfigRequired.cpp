#include "RoleConfigRequired.hpp"

void RoleConfigRequired::bindTo( RoleRequired* roleRequired ) {
	_bindingRequired = roleRequired;
}

MessageP RoleConfigRequired::propagate_message( MessageP msg ) {
	
	if ( _bindingRequired != NULL ) {
		return _bindingRequired->propagate_message(msg);
	}
	else {
		std::cout << "BindingRequired not found" << std::endl;
	}

}