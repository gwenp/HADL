#ifndef SERVICEREQUIRED_HPP
#define SERVICEREQUIRED_HPP

#include <list>
#include "Service.hpp"


class ServiceRequired : public Service
{
public:
	ServiceRequired();
	~ServiceRequired();
private:
	std::list<PortComposantRequired*> _requiredPorts;
};

#endif /* SERVICEREQUIRED_HPP */