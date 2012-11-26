#ifndef PORTCOMPOSANTREQUIRED_HPP
#define PORTCOMPOSANTREQUIRED_HPP

#include "PortComposant.hpp"

#include <string>
#include <iostream>

#include "MessageP.pb.h"

#include "Common.hpp"

class RoleProvided;

class PortComposantRequired : public PortComposant
{
public:
	std::string getType(){ return "required"; };

	// Doublon
	void propagateNotificationToRole();

	str_v send_message( str_v args );

	RoleProvided* _providedRole;
};

#endif /* PORTCOMPOSANTREQUIRED_HPP */