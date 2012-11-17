#ifndef SERVICEPROVIDED_HPP
#define SERVICEPROVIDED_HPP


#include <list>
#include "Service.hpp"
#include "PortComposantProvided.hpp"


class ServiceProvided : public Service
{
public:
private:
	std::list<PortComposantProvided*> _providedPorts;
};

#endif /* SERVICEPROVIDED_HPP */