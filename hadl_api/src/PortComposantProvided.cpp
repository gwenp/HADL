#include "PortComposantProvided.hpp"

#include "Component.hpp"

void PortComposantProvided::notifyComponent()
{
	getComponent()->on_notify(this);
}

