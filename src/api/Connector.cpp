#include "Connector.hpp"

void Connector::addInterface(InterfaceConnector* interface)
{
	_interfaces.push_back(interface);
}
