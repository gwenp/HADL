#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP


#include <list>

#include "Element.hpp"
#include "InterfaceConfiguration.hpp"

class Configuration : public Element
{
public:
	Configuration();
	~Configuration();
private:
	std::list<Element*> _elements;
	std::list<InterfaceConfiguration*> _interfaces;
};

#endif /* CONFIGURATION_HPP */