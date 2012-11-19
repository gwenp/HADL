#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include "ConnectableElement.hpp"
#include "Configuration.hpp"
#include "InterfaceConnector.hpp"
#include "RoleProvided.hpp"
#include "RoleRequired.hpp"

#include <map>
#include <string>
#include <iostream>

class Component;

class Connector : public ConnectableElement
{
public:
	void addRoleProvided(std::string name, RoleProvided* roleProvided);
	void addRoleRequired(std::string name, RoleRequired* roleRequired);

	void info();
	void on_notify(RoleProvided* port);

	void attachToComponent(Component* c, std::string roleName, std::string portName);

	std::map<std::string, RoleProvided*> _rolesProvided;
	std::map<std::string, RoleRequired*> _rolesRequired;
private:

	Configuration* _linkedConfiguration;
};

#endif /* CONNECTOR_HPP */