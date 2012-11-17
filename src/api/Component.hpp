#ifndef COMPONENT_HPP
#define COMPONENT_HPP


#include "ConnectableElement.hpp"
#include "Configuration.hpp"
#include "InterfaceComposant.hpp"

#include <list>

class Component : public ConnectableElement
{
public:
private:
	std::list<InterfaceComposant*> _interfaces;
	Configuration* _linkedConfiguration;
};

#endif /* COMPONENT_HPP */