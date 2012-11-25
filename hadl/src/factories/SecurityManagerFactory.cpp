#include "SecurityManagerFactory.hpp"

Component* SecurityManagerFactory::make()
{
	return new SecurityManager();
}
