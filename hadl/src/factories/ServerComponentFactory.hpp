#ifndef SERVERCOMPONENTFACTORY_HPP
#define SERVERCOMPONENTFACTORY_HPP

#include "../language_tools/ComponentFactory.hpp"
#include "../Server.hpp"

class ServerComponentFactory : public ComponentFactory {
public:
	Component* make();
private:
};

#endif