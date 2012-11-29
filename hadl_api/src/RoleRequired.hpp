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

	void attachToPortProvided( PortComposantProvided* port );

	MessageP propagate_message( MessageP msg );

private:
	PortComposantProvided* _portProvided;


};

#endif /* ROLEREQUIRED_HPP */