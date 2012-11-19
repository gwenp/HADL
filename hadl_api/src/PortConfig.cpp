#include "PortConfig.hpp"

#include "Configuration.hpp"

Configuration* PortConfig::getConfiguration()
{
	return _configuration;
}

void PortConfig::setConfiguration(Configuration* c)
{
	_configuration = c;
}
