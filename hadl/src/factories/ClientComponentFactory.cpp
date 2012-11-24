#include "ClientComponentFactory.hpp"

Component* ClientComponentFactory::make()
{
	return new Client();
}
