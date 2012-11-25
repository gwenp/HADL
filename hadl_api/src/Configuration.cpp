#include "Configuration.hpp"


void Configuration::addPortRequired(std::string name, PortConfigRequired* port)
{
	port->setConfiguration(this);
	_portsRequired.insert(std::pair<std::string, PortConfigRequired*>(name, port));
}

void Configuration::addPortProvided(std::string name, PortConfigProvided* port)
{
	port->setConfiguration(this);
	_portsProvided.insert(std::pair<std::string, PortConfigProvided*>(name, port));
}

void Configuration::addRoleProvided(std::string name, RoleConfigProvided* role)
{
	role->setConfiguration(this);
	_rolesProvided.insert(std::pair<std::string, RoleConfigProvided*>(name, role));
}

void Configuration::addRoleRequired(std::string name, RoleConfigRequired* role)
{
	role->setConfiguration(this);
	_rolesRequired.insert(std::pair<std::string, RoleConfigRequired*>(name, role));
}


void Configuration::linkElement(ConnectableElement* e, bool _internal = false)
{
	_linkedElement = e;	
	if(!_internal && e != NULL)
		e->linkConfiguration(this, true);
}

void Configuration::addElement(ConnectableElement* elt)
{
	_elements.push_back(elt);
	elt->setParentConfiguration(this);
}
