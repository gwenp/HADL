#ifndef ROLEREQUIRED_HPP
#define ROLEREQUIRED_HPP

#include "Role.hpp"

#include <string>
#include <iostream>

class PortComposantProvided;

class RoleRequired : public Role
{
public:
	std::string getType(){ return "required"; };
	PortComposantProvided* _portProvided;

	void propagateNotificationToPort();
private:

};

#endif /* ROLEREQUIRED_HPP */