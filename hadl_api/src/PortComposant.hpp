#ifndef PORTCOMPOSANT_HPP
#define PORTCOMPOSANT_HPP

#include "InterfaceComposant.hpp"
#include "MessageP.pb.h"

class Component;

class PortComposant : public InterfaceComposant
{
public:
	void setComponent( Component* c ){ _component = c; };
	Component* getComponent(){ return _component; };
protected:
	Component* _component;
};

#endif /* PORTCOMPOSANT_HPP */