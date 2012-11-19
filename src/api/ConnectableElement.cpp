#include "ConnectableElement.hpp"

#include "Configuration.hpp"

void ConnectableElement::addToConfiguration(Configuration* c)
{
	_parentConfiguration = c;
}

Configuration* ConnectableElement::getParentConfiguration()
{
	return _parentConfiguration;
}

void ConnectableElement::setParentConfiguration(Configuration* cfg)
{
	_parentConfiguration = cfg;
}

void ConnectableElement::linkConfiguration(Configuration* c, bool _internal= false)
{
	_linkedConfiguration = c;

	if(!_internal && c != NULL)
		c->linkElement(this, true);
}