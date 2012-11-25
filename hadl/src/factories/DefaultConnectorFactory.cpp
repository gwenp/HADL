#include "DefaultConnectorFactory.hpp"

Connector* DefaultConnectorFactory::make()
{
	return new Connector();
}
