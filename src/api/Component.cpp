#include "Component.hpp"

void Component::addInterface(std::string name, InterfaceComposant* interface)
{
	_interfaces.insert(std::pair<std::string, InterfaceComposant*>(name, interface));
}
