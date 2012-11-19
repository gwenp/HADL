#ifndef PORTCOMPOSANT_HPP
#define PORTCOMPOSANT_HPP

#include "InterfaceComposant.hpp"

class Component;

class PortComposant : public InterfaceComposant
{
public:
	void setComponent(Component* c){ _component=c; };
private:
	Component* _component;
};

#endif /* PORTCOMPOSANT_HPP */