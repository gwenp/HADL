#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "Element.hpp"
#include "ConnectableElement.hpp"
#include "InterfaceConfiguration.hpp"

#include <map>
#include <list>
#include <string>

class Configuration : public Element
{
public:
	void addInterface(std::string name, InterfaceConfiguration* interface);

	void linkElement(ConnectableElement* element, bool _internal);
private:
	std::list<Element*> _elements;
	std::map<std::string, InterfaceConfiguration*> _interfaces;

	ConnectableElement* _linkedElement;
};

#endif /* CONFIGURATION_HPP */