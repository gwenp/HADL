#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include "ConnectableElement.hpp"
#include "Configuration.hpp"
#include "InterfaceConnector.hpp"

class Connector : public ConnectableElement
{
public:
	Connector();
	~Connector();
private:
	std::list<InterfaceConnector*> _interfaces;

	Configuration* _linkedConfiguration;
};

#endif /* CONNECTOR_HPP */