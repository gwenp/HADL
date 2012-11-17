#include "Connector.hpp"

void Connector::addInterface(std::string name, InterfaceConnector* interface)
{
	_interfaces.insert(std::pair<std::string, InterfaceConnector*>(name, interface));
}
