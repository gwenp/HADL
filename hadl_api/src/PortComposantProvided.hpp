#ifndef PORTCOMPOSANTPROVIDED_HPP
#define PORTCOMPOSANTPROVIDED_HPP

#include "PortComposant.hpp"
#include "RoleRequired.hpp"

#include <string>

#include "Common.hpp"

class PortComposantProvided : public PortComposant
{
public:

	//PortComposantProvided( ComponentMethod component_method = NULL );

	// TEMP
	/*
	void set_callback( ComponentMethod component_method ) {
		_component_method = component_method;
	}
	*/
	std::string getType(){ return "provided"; };
	//void notifyComponent();

	MessageP receive_message( MessageP msg );
	
protected:

	//ComponentMethod _component_method;

};

#endif /* PORTCOMPOSANTPROVIDED_HPP */