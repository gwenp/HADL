#ifndef COMPONENT_HPP
#define COMPONENT_HPP


#include "ConnectableElement.hpp"
#include "Configuration.hpp"
#include "InterfaceComposant.hpp"

#include <map>
#include <string>

class Component : public ConnectableElement
{
public:
	void addInterface(std::string name, InterfaceComposant* interface);
private:
	std::map<std::string, InterfaceComposant*> _interfaces;
	Configuration* _linkedConfiguration;
};

#endif /* COMPONENT_HPP */