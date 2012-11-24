#include "LanguageManager.hpp"

void LanguageManager::registerComponentFactory(std::string name, ComponentFactory* factory)
{
	_componentFactories[name] = factory;
}

Component* LanguageManager::makeComponent(std::string name)
{
	_components[name] = _componentFactories[name]->make();
	return _components[name];
}

void LanguageManager::registerConnectorFactory(std::string name, ConnectorFactory* factory)
{
	_connectorFactories[name] = factory;
}

Connector* LanguageManager::makeConnector(std::string name)
{
	_connectors[name] = _connectorFactories[name]->make();
	return _connectors[name];
}

Component* LanguageManager::getComponent(std::string name)
{
	return _components[name];
}

Connector* LanguageManager::getConnector(std::string name)
{
	return _connectors[name];
}

void LanguageManager::addRequiredPortToComponent(std::string componentName, std::string portName)
{
	_components[componentName]->addPortRequired(portName, new PortComposantRequired());
}

void LanguageManager::addProvidedPortToComponent(std::string componentName, std::string portName)
{
	_components[componentName]->addPortProvided(portName, new PortComposantProvided());
}

void LanguageManager::addRequiredRoleToConnector(std::string connectorName, std::string roleName)
{
	_connectors[connectorName]->addRoleRequired(roleName, new RoleRequired());
}

void LanguageManager::addProvidedRoleToConnector(std::string connectorName, std::string roleName)
{
	_connectors[connectorName]->addRoleProvided(roleName, new RoleProvided());
}

