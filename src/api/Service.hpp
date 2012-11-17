#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <list>

#include "InterfaceComposant.hpp"
#include "PortComposant.hpp"

class Service : public InterfaceComposant
{
public:


private:
	std::list<PortComposant*> _ports;
};

#endif /* SERVICE_HPP */