#ifndef ROLEREQUIRED_HPP
#define ROLEREQUIRED_HPP

#include "Role.hpp"

#include <string>

class RoleRequired : public Role
{
public:
	std::string getType(){ return "required"; };
};

#endif /* ROLEREQUIRED_HPP */