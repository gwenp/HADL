#ifndef SECURITYMANAGERFACTORY_HPP
#define SECURITYMANAGERFACTORY_HPP

#include "../language_tools/ComponentFactory.hpp"
#include "../server_configuration/SecurityManager.hpp"

class SecurityManagerFactory : public ComponentFactory {
public:
	Component* make();
private:
};

#endif