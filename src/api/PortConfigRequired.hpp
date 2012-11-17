#ifndef PORTCONFIGREQUIRED_HPP
#define PORTCONFIGREQUIRED_HPP

#include "PortConfig.hpp"
#include "PortComposantRequired.hpp"

class PortConfigRequired : public PortConfig
{
public:
	PortConfigRequired();
	~PortConfigRequired();
private:
	PortComposantRequired* _bindingRequired;
	
};

#endif /* PORTCONFIGREQUIRED_HPP */