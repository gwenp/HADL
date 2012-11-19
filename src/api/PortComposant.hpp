#ifndef PORTCOMPOSANT_HPP
#define PORTCOMPOSANT_HPP

#include "InterfaceComposant.hpp"

class Component;

class PortComposant : public InterfaceComposant
{
public:
	void setComponent(Component* c){ _component=c; };
	Component* getComponent(){ return _component; };
private:
	Component* _component;
};

#endif /* PORTCOMPOSANT_HPP */