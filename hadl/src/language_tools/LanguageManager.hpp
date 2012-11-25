#ifndef LANGUAGEMANAGER_HPP
#define LANGUAGEMANAGER_HPP

#include <functional>
#include <HADL/Component.hpp>
#include <HADL/Connector.hpp>
#include <HADL/Configuration.hpp>
#include "JsonParser/JsonParser.hpp"
#include "ComponentFactory.hpp"
#include "ConnectorFactory.hpp"

class LanguageManager {
public:
	void parseJSON(std::string jsonUrl);

	void registerComponentFactory(std::string name, ComponentFactory* factory);
	Component* makeComponent(std::string name, std::string factory);

	void registerConnectorFactory(std::string name, ConnectorFactory* factory);
	Connector* makeConnector(std::string name, std::string factory);

	Component* getComponent(std::string name);
	Connector* getConnector(std::string name);

	void addRequiredPortToComponent(std::string componentName, std::string portName);
	void addProvidedPortToComponent(std::string componentName, std::string portName);

	void addRequiredRoleToConnector(std::string connectorName, std::string roleName);
	void addProvidedRoleToConnector(std::string connectorName, std::string roleName);

	void addPropertyToElement(Element* e, std::string key, std::string value);

	void attachConfigurationToComponent(std::string componentName, std::string configurationName);

private:
	std::map<std::string, ComponentFactory*> _componentFactories;
	std::map<std::string, ConnectorFactory*> _connectorFactories;

	std::map<std::string, Connector*> _connectors;
	std::map<std::string, Component*> _components;
	std::map<std::string, Configuration*> _configurations;
};

#endif