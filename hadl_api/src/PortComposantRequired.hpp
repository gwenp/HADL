#ifndef PORTCOMPOSANTREQUIRED_HPP
#define PORTCOMPOSANTREQUIRED_HPP

#include "PortComposant.hpp"

#include <string>
#include <iostream>

#include "MessageP.pb.h"

#include "Common.hpp"

class RoleProvided;

class PortComposantRequired : public PortComposant, public Element
{
public:
	std::string getType(){ return "required"; };

	str_v send_message( str_v args );

	void attachToRoleProvided( RoleProvided* role );

protected:
	RoleProvided* _providedRole;
};

#endif /* PORTCOMPOSANTREQUIRED_HPP */