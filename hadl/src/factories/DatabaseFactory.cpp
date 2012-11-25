#include "DatabaseFactory.hpp"

Component* DatabaseFactory::make()
{
	return new DataBase();
}
