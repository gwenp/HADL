#ifndef ROLEPROVIDED_HPP
#define ROLEPROVIDED_HPP

#include "Role.hpp"
#include "PortComposantRequired.hpp"

#include <string>

class RoleProvided : public Role
{
public:
	std::string getType(){ return "provided"; };
	
private: 
	PortComposantRequired* _portRequired;
};

#endif /* ROLEPROVIDED_HPP */