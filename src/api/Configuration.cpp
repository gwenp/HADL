#include "Configuration.hpp"

void Configuration::linkElement(ConnectableElement* e, bool _internal = false)
{
	_linkedElement = e;	
	if(!_internal && e != NULL)
		e->linkConfiguration(this, true);
}