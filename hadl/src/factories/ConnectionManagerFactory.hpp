#ifndef CONNECTIONMANAGERFACTORY_HPP
#define CONNECTIONMANAGERFACTORY_HPP

#include "../language_tools/ComponentFactory.hpp"
#include "../server_configuration/ConnectionManager.hpp"

class ConnectionManagerFactory : public ComponentFactory {
public:
	Component* make();
private:
};

#endif