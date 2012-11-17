#ifndef SERVICEREQUIRED_HPP
#define SERVICEREQUIRED_HPP

#include <list>
#include "Service.hpp"
#include "PortComposantRequired.hpp"

class ServiceRequired : public Service
{
public:
private:
	std::list<PortComposantRequired*> _requiredPorts;
};

#endif /* SERVICEREQUIRED_HPP */