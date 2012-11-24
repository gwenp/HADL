#ifndef CLIENTCOMPONENTFACTORY_HPP
#define CLIENTCOMPONENTFACTORY_HPP

#include "../language_tools/ComponentFactory.hpp"
#include "../Client.hpp"

class ClientComponentFactory : public ComponentFactory {
public:
	Component* make();
private:
};

#endif