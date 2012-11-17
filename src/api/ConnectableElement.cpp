#include "ConnectableElement.hpp"

#include "Configuration.hpp"

void ConnectableElement::linkConfiguration(Configuration* c, bool _internal= false)
{
	_linkedConfiguration = c;

	if(!_internal && c != NULL)
		c->linkElement(this, true);
}