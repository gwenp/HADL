#ifndef SERVICEREQUIRED_HPP
#define SERVICEREQUIRED_HPP

#include <list>
#include "Service.hpp"
#include "PortComposantRequired.hpp"

#include <string>

class ServiceRequired : public Service
{
public:
	std::string getType(){ return "required"; };
private:
	std::list<PortComposantRequired*> _requiredPorts;
};

#endif /* SERVICEREQUIRED_HPP */