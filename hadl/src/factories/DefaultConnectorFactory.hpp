#ifndef DEFAULTCONNECTORFACTORY_HPP
#define DEFAULTCONNECTORFACTORY_HPP

#include <HADL/Connector.hpp>
#include "../language_tools/ConnectorFactory.hpp"

class DefaultConnectorFactory : public ConnectorFactory {
public:
	Connector* make();
private:
};

#endif