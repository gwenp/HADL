#include "RoleConfig.hpp"

#include "Configuration.hpp"

Configuration* RoleConfig::getConfiguration()
{
	return _configuration;
}

void RoleConfig::setConfiguration(Configuration* c)
{
	_configuration = c;
}
