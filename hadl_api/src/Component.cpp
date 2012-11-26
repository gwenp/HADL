#include "Component.hpp"

#include "Connector.hpp"

void Component::addPortRequired(std::string name, PortComposantRequired* port)
{
	std::cout << "||||||||||||||| Port Required added : " << name << std::endl;
	port->setComponent(this);
	_portsRequired[name] = port;
}

void Component::addPortProvided(std::string name, PortComposantProvided* port, std::string method_index )
{
	std::cout << "||||||||||||||| Port Provided added : " << name << std::endl;
	port->setComponent(this);
	_portsProvided[name] = port;
	
	if ( !method_index.empty() ) {
		_portsRequired_methodNames[port] = method_index;
	}
}

void Component::info()
{
	std::cout << "Component:======================" << std::endl
			<< "\t Ports Required :" << std::endl;

	for (std::map<std::string, PortComposantRequired*>::iterator it = _portsRequired.begin(); it != _portsRequired.end(); ++it)
	{
		std::cout << "\t\t" << (*it).first << std::endl;
	}

	std::cout << "\t Ports Provided :" << std::endl;
	for (std::map<std::string, PortComposantProvided*>::iterator it = _portsProvided.begin(); it != _portsProvided.end(); ++it)
	{
		std::cout << "\t\t"  << (*it).first << std::endl;
	}

	std::cout << std::endl;
}

void Component::attachToConnector(Connector* c, std::string portName, std::string roleName)
{
	if(getParentConfiguration() == c->getParentConfiguration())
	{
		_portsRequired[portName]->_providedRole = c->_rolesProvided[roleName];
	}
	else
		std::cout << "[ERROR] : The Connector and the Component does not have the same parent Configuration!" <<std::endl;
}

std::vector<std::string> Component::on_message( PortComposantProvided* provided_port, std::vector<std::string> args ) {
	std::cout << "Parent callback\n";
}

