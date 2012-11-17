#ifndef COMPONENT_HPP
#define COMPONENT_HPP


#include "Element.hpp"
#include "InterfaceComposant.hpp"

#include <list>

class Component : public Element
{
public:
	Component();
	~Component();
private:
	std::list<InterfaceComposant*> _interfaces;
};

#endif /* COMPONENT_HPP */