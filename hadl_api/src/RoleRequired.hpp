#ifndef ROLEREQUIRED_HPP
#define ROLEREQUIRED_HPP

#include "Role.hpp"

#include <string>
#include <iostream>

#include "MessageP.pb.h"

class PortComposantProvided;

class RoleRequired : public Role
{
public:
	std::string getType(){ return "required"; };
	PortComposantProvided* _portProvided;

	// Doublon
	void propagateNotificationToPort();

	MessageP propagate_message( MessageP msg );

private:

};

#endif /* ROLEREQUIRED_HPP */