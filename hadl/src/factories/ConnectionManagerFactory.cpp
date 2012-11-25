#include "ConnectionManagerFactory.hpp"

Component* ConnectionManagerFactory::make()
{
	return new ConnectionManager();
}
