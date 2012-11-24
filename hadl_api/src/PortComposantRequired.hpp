#ifndef PORTCOMPOSANTREQUIRED_HPP
#define PORTCOMPOSANTREQUIRED_HPP

#include "PortComposant.hpp"

#include <string>
#include <iostream>

#include "MessageP.pb.h"

class RoleProvided;

class PortComposantRequired : public PortComposant
{
public:
	std::string getType(){ return "required"; };

	// Doublon
	void propagateNotificationToRole();

	MessageP send_message( MessageP msg );

	RoleProvided* _providedRole;
};

#endif /* PORTCOMPOSANTREQUIRED_HPP */