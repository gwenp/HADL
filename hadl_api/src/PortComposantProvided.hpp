#ifndef PORTCOMPOSANTPROVIDED_HPP
#define PORTCOMPOSANTPROVIDED_HPP

#include "PortComposant.hpp"
#include "RoleRequired.hpp"

#include <string>

#include "Common.hpp"

class PortComposantProvided : public PortComposant, public Element
{
public:

	std::string getType(){ return "provided"; };

	virtual MessageP receive_message( MessageP msg );
	

};

#endif /* PORTCOMPOSANTPROVIDED_HPP */