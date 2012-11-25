#ifndef PORTCOMPOSANTPROVIDED_HPP
#define PORTCOMPOSANTPROVIDED_HPP

#include "PortComposant.hpp"
#include "RoleRequired.hpp"

#include <string>

class PortComposantProvided : public PortComposant
{
public:

	//PortComposantProvided( (Component::*my_memfunc_ptr)(std::vector<std::string>) );

	std::string getType(){ return "provided"; };
	void notifyComponent();

	MessageP receive_message( MessageP msg );
	
private:
};

#endif /* PORTCOMPOSANTPROVIDED_HPP */