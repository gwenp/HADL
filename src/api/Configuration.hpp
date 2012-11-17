#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP


#include <list>

#include "Element.hpp"
#include "ConnectableElement.hpp"
#include "InterfaceConfiguration.hpp"

class Configuration : public Element
{
public:
	void addInterface(InterfaceConfiguration* interface);

	void linkElement(ConnectableElement* element, bool _internal);
private:
	std::list<Element*> _elements;
	std::list<InterfaceConfiguration*> _interfaces;

	ConnectableElement* _linkedElement;
};

#endif /* CONFIGURATION_HPP */