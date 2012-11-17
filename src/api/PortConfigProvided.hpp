#ifndef PORTCONFIGPROVIDED_HPP
#define PORTCONFIGPROVIDED_HPP

#include "PortConfig.hpp"
#include "PortComposantProvided.hpp"

class PortConfigProvided : public PortConfig
{
public:
	PortConfigProvided();
	~PortConfigProvided();
private:
	PortComposantProvided* _bindingProvided;
};

#endif /* PORTCONFIGPROVIDED_HPP */