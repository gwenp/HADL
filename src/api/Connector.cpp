#include "Connector.hpp"

#include "Component.hpp"

void Connector::addRoleProvided(std::string name, RoleProvided* role)
{
	role->setConnector(this);
	_rolesProvided.insert(std::pair<std::string, RoleProvided*>(name, role));
}

void Connector::addRoleRequired(std::string name, RoleRequired* role)
{
	role->setConnector(this);
	_rolesRequired.insert(std::pair<std::string, RoleRequired*>(name, role));
}

void Connector::info()
{
	std::cout << "Connector:======================" << std::endl
			<< "\t Roles Required :" << std::endl;
	for (std::map<std::string, RoleRequired*>::iterator it = _rolesRequired.begin(); it != _rolesRequired.end(); ++it)
	{
		std::cout << "\t\t" << (*it).first << std::endl;
	}

	std::cout << "\t Roles Provided :" << std::endl;
	for (std::map<std::string, RoleProvided*>::iterator it = _rolesProvided.begin(); it != _rolesProvided.end(); ++it)
	{
		std::cout << "\t\t" << (*it).first << std::endl;
	}

	std::cout << std::endl;
}

void Connector::on_notify(RoleProvided* port)
{
	std::cout << "notification received!" <<std::endl;
}

void Connector::attachToComponent(Component* c, std::string roleName, std::string portName)
{
	PortComposantProvided* port = c->_portsProvided[portName];
	_rolesRequired[roleName]->_portProvided = port;
}