#include "Component.hpp"

void Component::addInterface(InterfaceComposant* interface)
{
	_interfaces.push_back(interface);
}
