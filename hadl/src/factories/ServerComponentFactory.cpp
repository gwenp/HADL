#include "ServerComponentFactory.hpp"

Component* ServerComponentFactory::make()
{
	return new Server();
}
