#ifndef LANGUAGEMANAGER_HPP
#define LANGUAGEMANAGER_HPP

#include <functional>
#include <HADL/Component.hpp>
#include <HADL/Connector.hpp>
#include "ComponentFactory.hpp"
#include "ConnectorFactory.hpp"

class LanguageManager {
public:
	void registerComponentFactory(std::string name, ComponentFactory* factory);
	Component* makeComponent(std::string name);

	void registerConnectorFactory(std::string name, ConnectorFactory* factory);
	Connector* makeConnector(std::string name);
private:
	std::map<std::string, ComponentFactory*> _componentFactories;
	std::map<std::string, ConnectorFactory*> _connectorFactories;
};

#endif