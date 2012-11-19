#include "RoleProvided.hpp"

#include "Connector.hpp"

void RoleProvided::notifyConnector()
{
	std::cout << "RoleProvided::notifyConnector" <<std::endl;
	
	getConnector()->on_notify(this);
}