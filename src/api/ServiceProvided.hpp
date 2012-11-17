#ifndef SERVICEPROVIDED_HPP
#define SERVICEPROVIDED_HPP


#include "Service.hpp"
#include "PortComposantProvided.hpp"

#include <list>
#include <string>

class ServiceProvided : public Service
{
public:
	std::string getType(){ return "provided"; };
	
private:
	std::list<PortComposantProvided*> _providedPorts;
};

#endif /* SERVICEPROVIDED_HPP */