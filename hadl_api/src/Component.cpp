#include "Component.hpp"

#include "Connector.hpp"

void Component::addPortRequired( PortComposantRequired* port)
{
	std::cout << "||||||||||||||| Port Required added : " << port->getName() << std::endl;
	port->setComponent(this);
	_portsRequired[port->getName()] = port;
}

void Component::addPortProvided( PortComposantProvided* port, std::string method_index )
{
	std::cout << "||||||||||||||| Port Provided added : " << port->getName() << std::endl;
	port->setComponent(this);
	_portsProvided[port->getName()] = port;
	
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


std::vector<std::string> Component::on_message( PortComposantProvided* provided_port, std::vector<std::string> args ) {
	std::cout << "Parent callback\n";
}

