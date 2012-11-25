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

	PortComposantProvided* getPortProvided(std::string name);
	PortComposantRequired* getPortRequired(std::string name);

	RoleProvided* getRoleProvided(std::string name);
	RoleRequired* getRoleRequired(std::string name);

	void addRequiredPortToComponent(std::string componentName, std::string portName);
	void addProvidedPortToComponent(std::string componentName, std::string portName, std::string toMethod);

	void addRequiredRoleToConnector(std::string connectorName, std::string roleName);
	void addProvidedRoleToConnector(std::string connectorName, std::string roleName);

	void addPropertyToElement(Element* e, std::string key, std::string value);

	void attachConfigurationToComponent(std::string componentName, std::string configurationName);
	void addElementToConfiguration(std::string elementName, std::string elementType, std::string configurationName);

	void makeAttachment(std::string fromType, std::string fromName, std::string toType, std::string toName);
	void addBinding(std::string configName, std::string bindingName, std::string type, std::string destName);
private:
	std::map<std::string, ComponentFactory*> _componentFactories;
	std::map<std::string, ConnectorFactory*> _connectorFactories;

	std::map<std::string, Connector*> _connectors;
	std::map<std::string, Component*> _components;
	std::map<std::string, Configuration*> _configurations;
	
	std::map<std::string, Component*> _componentsByPort;
	std::map<std::string, Connector*> _connectorsByRole;

	std::map<std::string, RoleProvided*> _rolesProvided;
	std::map<std::string, RoleRequired*> _rolesRequired;

	std::map<std::string, PortComposantProvided*> _portsProvided;
	std::map<std::string, PortComposantRequired*> _portsRequired;

	std::map<std::string, PortConfigRequired*> _portsConfigRequired;
};

#endif