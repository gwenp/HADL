#include "RoleProvided.hpp"

#include "Connector.hpp"

void RoleProvided::notifyConnector()
{
	getConnector()->on_notify(this);
}