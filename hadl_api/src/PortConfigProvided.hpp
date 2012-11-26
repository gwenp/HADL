#ifndef PORTCONFIGPROVIDED_HPP
#define PORTCONFIGPROVIDED_HPP

#include "PortConfig.hpp"
#include "PortComposantProvided.hpp"

#include <string>

class PortConfigProvided : public PortConfig, public PortComposantProvided
{
public:
	std::string getType(){ return "provided"; };

	void bindTo( PortComposantProvided* portProvided );
	MessageP receive_message( MessageP msg );
	
private:
	PortComposantProvided* _bindingProvided;
};

#endif /* PORTCONFIGPROVIDED_HPP */