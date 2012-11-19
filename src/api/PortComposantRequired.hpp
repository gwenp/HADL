#ifndef PORTCOMPOSANTREQUIRED_HPP
#define PORTCOMPOSANTREQUIRED_HPP

#include "PortComposant.hpp"

#include <string>

class RoleProvided;

class PortComposantRequired : public PortComposant
{
public:
	std::string getType(){ return "required"; };

	RoleProvided* _providedRole;
};

#endif /* PORTCOMPOSANTREQUIRED_HPP */