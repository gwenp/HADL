#include "CS_ConnectorFactory.hpp"

Connector* CS_ConnectorFactory::make()
{
	return new CS_Connector();
}
