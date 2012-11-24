#ifndef CS_CONNECTORFACTORY_HPP
#define CS_CONNECTORFACTORY_HPP

#include <HADL/Connector.hpp>
#include "../language_tools/ConnectorFactory.hpp"
#include "../CS_Connector.hpp"

class CS_ConnectorFactory : public ConnectorFactory {
public:
	Connector* make();
private:
};

#endif