#ifndef DATABASEFACTORY_HPP
#define DATABASEFACTORY_HPP

#include "../language_tools/ComponentFactory.hpp"
#include "../server_configuration/DataBase.hpp"

class DatabaseFactory : public ComponentFactory {
public:
	Component* make();
private:
};

#endif