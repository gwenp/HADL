#ifndef SERVICEPROVIDED_HPP
#define SERVICEPROVIDED_HPP


#include <vector>
#include "Service.hpp"


class ServiceProvided : public Service
{
public:
	ServiceProvided();
	~ServiceProvided();
private:
	std::vector<PortComposantProvided*> _providedPorts;
};

#endif /* SERVICEPROVIDED_HPP */