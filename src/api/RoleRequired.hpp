#ifndef ROLEREQUIRED_HPP
#define ROLEREQUIRED_HPP

#include "Role.hpp"

#include <string>

class PortComposantProvided;

class RoleRequired : public Role
{
public:
	std::string getType(){ return "required"; };
	PortComposantProvided* _portProvided;
private:

};

#endif /* ROLEREQUIRED_HPP */