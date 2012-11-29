#include "LanguageManager.hpp"

void LanguageManager::parseJSON(std::string jsonUrl, std::string app)
{
	appName = app;
	JsonParser::parse(this, jsonUrl, app);
}

void LanguageManager::initialize()
{
	for (std::map<std::string, Component*>::iterator it = _components.begin(); it != _components.end(); ++it)
	{
		Dbg::out("Initialization") << "[Initialization] Compo : "<< (*it).first << std::endl;

		if(_components[(*it).first] != NULL)
			(*it).second->onInit();
	}

	for (std::map<std::string, Connector*>::iterator it = _connectors.begin(); it != _connectors.end(); ++it)
	{
		Dbg::out("Initialization") << "[Initialization] Connector : "<< (*it).first << std::endl;
		if(_connectors[(*it).first] != NULL)
			(*it).second->onInit();
	}
}

void LanguageManager::launch()
{
	for (std::map<std::string, Component*>::iterator it = _components.begin(); it != _components.end(); ++it)
	{
		(*it).second->onLaunch();
	}	
}

void LanguageManager::registerComponentFactory(std::string name, ComponentFactory* factory)
{
	_componentFactories[name] = factory;
}

Component* LanguageManager::makeComponent(std::string name, std::string factory)
{
	Dbg::out("LanguageManagerMake") << "[LanguageManager] makeComponent : "<< name << "; from factory : " << factory  << std::endl;
	_components[name] = _componentFactories[factory]->make();

	if ( _components[name] != NULL ) {
		_components[name]->setName(name);
	}

	return _components[name];
}

void LanguageManager::registerConnectorFactory(std::string name, ConnectorFactory* factory)
{
	_connectorFactories[name] = factory;
}

Connector* LanguageManager::makeConnector(std::string name, std::string factory)
{
	Dbg::out("LanguageManagerMake") << "[LanguageManager] makeConnector : "<< name << "; from factory : " << factory << std::endl;

	_connectors[name] = _connectorFactories[factory]->make();

	if ( _connectors[name] != NULL ) {
		_connectors[name]->setName(name);
	}

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

PortComposantProvided* LanguageManager::getPortProvided(std::string name)
{
	return _portsProvided[name]; 
}

PortComposantRequired* LanguageManager::getPortRequired(std::string name)
{
	return _portsRequired[name]; 
}

RoleProvided* LanguageManager::getRoleProvided(std::string name)
{
	return _rolesProvided[name]; 
}

RoleRequired* LanguageManager::getRoleRequired(std::string name)
{
	return _rolesRequired[name]; 
}

void LanguageManager::addRequiredPortToComponent(std::string componentName, std::string portName)
{
	Dbg::out("LanguageManager") << "[LanguageManager] addPortRequired : "<< portName << " to Component : " << componentName << std::endl;
	_portsRequired[portName] = new PortComposantRequired();

	_portsRequired[portName]->setName(portName);

	_components[componentName]->addPortRequired(portName, _portsRequired[portName]);
	_componentsByPort[portName] = _components[componentName];
}

void LanguageManager::addProvidedPortToComponent(std::string componentName, std::string portName, std::string toMethod)
{
	_portsProvided[portName] = new PortComposantProvided();

	_portsProvided[portName]->setName(portName);
	Dbg::out("LanguageManager") << "[LanguageManager] addPortProvided : "<< portName << " to Component : " << componentName << std::endl;
	_components[componentName]->addPortProvided(portName,_portsProvided[portName], toMethod);
	_componentsByPort[portName] = _components[componentName];
}

void LanguageManager::addRequiredRoleToConnector(std::string connectorName, std::string roleName)
{
	Dbg::out("LanguageManager") << "[LanguageManager] addRoleRequired : "<< roleName << " to Connector : " << connectorName << std::endl;
	_rolesRequired[roleName] = new RoleRequired();

	_rolesRequired[roleName]->setName(roleName);
	_connectors[connectorName]->addRoleRequired(roleName, _rolesRequired[roleName]);
	_connectorsByRole[roleName] = _connectors[connectorName];
}

void LanguageManager::addProvidedRoleToConnector(std::string connectorName, std::string roleName, std::string toMethod)
{
	Dbg::out("LanguageManager") << "[LanguageManager] addRoleProvided : "<< roleName << " to Connector : " << connectorName << std::endl;
	_rolesProvided[roleName] =  new RoleProvided();

	_rolesProvided[roleName]->setName(roleName);
	_connectors[connectorName]->addRoleProvided(roleName, _rolesProvided[roleName], toMethod);
	_connectorsByRole[roleName] = _connectors[connectorName];
}

void LanguageManager::addPropertyToElement(Element* e, std::string key, std::string value)
{
	std::cout << "[LanguageManager] addPropertyToElement : "<< key << "  : " << value << std::endl;
	e->setProperty(key, value);
}

void LanguageManager::attachConfigurationToComponent(std::string componentName, std::string configurationName)
{
	Dbg::out("LanguageManager") << "[LanguageManager] attachConfigurationToComponent : "<< componentName << "  : " << configurationName << std::endl;

	_configurations[configurationName] = new Configuration();

	_configurations[configurationName]->setName(configurationName);
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
		if(_componentsByPort[toName] != NULL)
			_connectorsByRole[fromName]->attachToComponent(_componentsByPort[toName], fromName, toName);
		if(_configurationsByPortProvided[toName] != NULL)
			_connectorsByRole[fromName]->attachToComponent(_configurationsByPortProvided[toName], fromName, toName);
		
	}
}

void LanguageManager::addBinding(std::string configName, std::string bindingName, std::string type, std::string destName)
{
	if(type == "toPortRequired")
	{
		Dbg::out("LanguageManager") << "[LanguageManager] !!!!! addBinding : "<< configName << "  : " << bindingName << std::endl;
		_portsConfigRequired[bindingName] =  new PortConfigRequired();
		_portsConfigRequired[bindingName]->bindTo(_portsRequired[destName]);
		_configurations[configName]->addPortRequired(bindingName, _portsConfigRequired[bindingName]);
	}
	if(type == "toPortProvided")
	{
		Dbg::out("LanguageManager") << "[LanguageManager] !!!!! addBinding : "<< configName << "  : " << bindingName << std::endl;
		_portsConfigProvided[bindingName] =  new PortConfigProvided();
		_portsConfigProvided[bindingName]->bindTo(_portsProvided[destName]);
		_configurations[configName]->addPortProvided(bindingName, _portsConfigProvided[bindingName]);

		_configurationsByPortProvided[bindingName] = _configurations[configName];

	}
}
