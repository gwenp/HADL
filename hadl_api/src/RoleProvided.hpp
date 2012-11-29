#ifndef ROLEPROVIDED_HPP
#define ROLEPROVIDED_HPP

#include "Role.hpp"
#include "PortComposantRequired.hpp"

#include <string>
#include <iostream>

//template<typename component = Component>
class RoleProvided : public Role
{
public:
	std::string getType(){ return "provided"; };
	
	void attachToPortRequired( PortComposantRequired* port );


	MessageP propagate_message( MessageP msg );

private:
};

#endif /* ROLEPROVIDED_HPP */