#ifndef PORTCOMPOSANTREQUIRED_HPP
#define PORTCOMPOSANTREQUIRED_HPP

#include "PortComposant.hpp"

#include <string>

class PortComposantRequired : public PortComposant
{
public:
	std::string getType(){ return "required"; };


};

#endif /* PORTCOMPOSANTREQUIRED_HPP */