#ifndef ROLEPROVIDED_HPP
#define ROLEPROVIDED_HPP

#include "Role.hpp"
#include "PortComposantRequired.hpp"

#include <string>
#include <iostream>

class RoleProvided : public Role
{
public:
	std::string getType(){ return "provided"; };
	
	void notifyConnector();
private: 
};

#endif /* ROLEPROVIDED_HPP */