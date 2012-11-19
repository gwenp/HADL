#ifndef COMPONENT_HPP
#define COMPONENT_HPP


#include "ConnectableElement.hpp"
#include "PortComposantRequired.hpp"
#include "PortComposantProvided.hpp"
#include "RoleProvided.hpp"
#include "Configuration.hpp"
#include "InterfaceComposant.hpp"

#include <map>
#include <string>

class Connector;

class Component : public ConnectableElement
{
public:
	void addPortRequired(std::string name, PortComposantRequired* port);
	void addPortProvided(std::string name, PortComposantProvided* port);

	void info();

	void attachToConnector(Connector* c, std::string portName, std::string roleName);

	std::map<std::string, PortComposantRequired*> _portsRequired;
	std::map<std::string, PortComposantProvided*> _portsProvided;

private:
	Configuration* _linkedConfiguration;
};

#endif /* COMPONENT_HPP */