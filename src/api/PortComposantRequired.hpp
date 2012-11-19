#ifndef PORTCOMPOSANTREQUIRED_HPP
#define PORTCOMPOSANTREQUIRED_HPP

#include "PortComposant.hpp"

#include <string>
#include <iostream>

class RoleProvided;

class PortComposantRequired : public PortComposant
{
public:
	std::string getType(){ return "required"; };

	void propagateNotificationToRole();
	RoleProvided* _providedRole;
};

#endif /* PORTCOMPOSANTREQUIRED_HPP */