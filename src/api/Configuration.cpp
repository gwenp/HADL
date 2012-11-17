#include "Configuration.hpp"

void Configuration::addInterface(std::string name, InterfaceConfiguration* interface)
{
	_interfaces.insert(std::pair<std::string, InterfaceConfiguration*>(name, interface));
}

void Configuration::linkElement(ConnectableElement* e, bool _internal = false)
{
	_linkedElement = e;	
	if(!_internal && e != NULL)
		e->linkConfiguration(this, true);
}