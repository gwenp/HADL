#include "LanguageManager.hpp"

void LanguageManager::parseJSON(std::string jsonUrl)
{
	JsonParser::parse(this, jsonUrl, "Server");
}

void LanguageManager::registerComponentFactory(std::string name, ComponentFactory* factory)
{
	_componentFactories[name] = factory;
}

Component* LanguageManager::makeComponent(std::string name, std::string factory)
{
	Dbg::out("LanguageManager") << "[LanguageManager] makeComponent : "<< name << "; from factory : " << factory  << std::endl;
	_components[name] = _componentFactories[factory]->make();
	return _components[name];
}

void LanguageManager::registerConnectorFactory(std::string name, ConnectorFactory* factory)
{
	_connectorFactories[name] = factory;
}

Connector* LanguageManager::makeConnector(std::string name, std::string factory)
{
	Dbg::out("LanguageManager") << "[LanguageManager] makeConnector : "<< name << "; from factory : " << factory << std::endl;

	_connectors[name] = _connectorFactories[factory]->make();
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
	Dbg::out("LanguageManager") << "[LanguageManager] addPortRequired : "<< portName << " to Component : " << componentName << std::endl;
	_components[componentName]->addPortRequired(portName, new PortComposantRequired());
	_componentsByPort[portName] = _components[componentName];
}

void LanguageManager::addProvidedPortToComponent(std::string componentName, std::string portName)
{
	Dbg::out("LanguageManager") << "[LanguageManager] addPortProvided : "<< portName << " to Component : " << componentName << std::endl;
	_components[componentName]->addPortProvided(portName, new PortComposantProvided());
	_componentsByPort[portName] = _components[componentName];
}

void LanguageManager::addRequiredRoleToConnector(std::string connectorName, std::string roleName)
{
	Dbg::out("LanguageManager") << "[LanguageManager] addRoleRequired : "<< roleName << " to Connector : " << connectorName << std::endl;
	_connectors[connectorName]->addRoleRequired(roleName, new RoleRequired());
	_connectorsByRole[roleName] = _connectors[connectorName];
}

void LanguageManager::addProvidedRoleToConnector(std::string connectorName, std::string roleName)
{
	Dbg::out("LanguageManager") << "[LanguageManager] addRoleProvided : "<< roleName << " to Connector : " << connectorName << std::endl;
	_connectors[connectorName]->addRoleProvided(roleName, new RoleProvided());
	_connectorsByRole[roleName] = _connectors[connectorName];
}

void LanguageManager::addPropertyToElement(Element* e, std::string key, std::string value)
{
	Dbg::out("LanguageManager") << "[LanguageManager] addPropertyToElement : "<< key << "  : " << value << std::endl;
	e->setProperty(key, value);
}

void LanguageManager::attachConfigurationToComponent(std::string componentName, std::string configurationName)
{
	Dbg::out("LanguageManager") << "[LanguageManager] attachConfigurationToComponent : "<< componentName << "  : " << configurationName << std::endl;

	_configurations[configurationName] = new Configuration();
	_components[componentName]->linkConfiguration(_configurations[configurationName], false);
}

void LanguageManager::addElementToConfiguration(std::string elementName, std::string elementType, std::string configurationName)
{
	Dbg::out("LanguageManager") << "[LanguageManager] addElementToConfiguration : "<< elementName << "  : " << configurationName << std::endl;

	if(_configurations[configurationName] != NULL)
		if(elementType == "Connector")
		{
			if(_connectors[elementName] != NULL)
				_configurations[configurationName]->addElement(_connectors[elementName]);
		}	
		if(elementType == "Component")
		{
			if(_components[elementName] != NULL)
				_configurations[configurationName]->addElement(_components[elementName]);
		}
}

void LanguageManager::makeAttachment(std::string fromType, std::string fromName, std::string toType, std::string toName)
{
	Dbg::out("LanguageManager") << "[LanguageManager] makeAttachment : "<< fromName << "  : " << toName << std::endl;
	
	if(fromType == "Port" && toType == "Role")
	{
		_componentsByPort[fromName]->attachToConnector(_connectorsByRole[toName], fromName, toName);
	}
	else if(fromType == "Role" && toType == "Port")
	{
		_connectorsByRole[fromName]->attachToComponent(_componentsByPort[toName], fromName, toName);
	}
}
