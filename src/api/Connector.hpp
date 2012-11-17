#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include "ConnectableElement.hpp"
#include "Configuration.hpp"
#include "InterfaceConnector.hpp"

#include <map>
#include <string>

class Connector : public ConnectableElement
{
public:
	void addInterface(std::string name, InterfaceConnector* interface);
private:
	std::map<std::string, InterfaceConnector*> _interfaces;

	Configuration* _linkedConfiguration;
};

#endif /* CONNECTOR_HPP */