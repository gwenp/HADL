#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "Element.hpp"
#include "ConnectableElement.hpp"
#include "InterfaceConfiguration.hpp"

#include "PortConfigRequired.hpp"
#include "PortConfigProvided.hpp"
#include "RoleConfigProvided.hpp"
#include "RoleConfigRequired.hpp"

#include <map>
#include <list>
#include <string>

class Configuration : public Element
{
public:

	void addPortRequired(std::string name, PortConfigRequired* port);
	void addPortProvided(std::string name, PortConfigProvided* port);
	void addRoleProvided(std::string name, RoleConfigProvided* role);
	void addRoleRequired(std::string name, RoleConfigRequired* role);

	void linkElement(ConnectableElement* element, bool _internal);
private:
	std::list<Element*> _elements;
	std::map<std::string, PortConfigRequired*> _portsRequired;
	std::map<std::string, PortConfigProvided*> _portsProvided;
	std::map<std::string, RoleConfigProvided*> _rolesProvided;
	std::map<std::string, RoleConfigRequired*> _rolesRequired;

	ConnectableElement* _linkedElement;
};

#endif /* CONFIGURATION_HPP */