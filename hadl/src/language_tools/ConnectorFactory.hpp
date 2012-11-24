#ifndef CONNECTORFACTORY_HPP
#define CONNECTORFACTORY_HPP

#include <HADL/Connector.hpp>


class ConnectorFactory {
public:
	virtual Connector* make() =0;
};

#endif