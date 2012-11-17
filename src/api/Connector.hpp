#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include "Element.hpp"
#include "InterfaceConnector.hpp"

class Connector : public Element
{
public:
	Connector();
	~Connector();
private:
	std::list<InterfaceConnector*> _interfaces;
};

#endif /* CONNECTOR_HPP */