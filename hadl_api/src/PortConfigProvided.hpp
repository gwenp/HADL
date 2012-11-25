#ifndef PORTCONFIGPROVIDED_HPP
#define PORTCONFIGPROVIDED_HPP

#include "PortConfig.hpp"
#include "PortComposantProvided.hpp"

#include <string>

class PortConfigProvided : public PortConfig
{
public:
	std::string getType(){ return "provided"; };

	void bindTo( PortComposantProvided* portProvided );
	
private:
	PortComposantProvided* _bindingProvided;
};

#endif /* PORTCONFIGPROVIDED_HPP */