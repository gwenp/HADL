#ifndef COMPONENT_HPP
#define COMPONENT_HPP


#include "ConnectableElement.hpp"
#include "PortComposantRequired.hpp"
#include "PortComposantProvided.hpp"
#include "RoleProvided.hpp"
#include "Configuration.hpp"
#include "InterfaceComposant.hpp"

#include <map>
#include <string>

#include "Common.hpp"
class Connector;

typedef std::map<std::string, ComponentMethod> MethodsIndex;
//typedef std::map<PortComposantProvided*, ComponentMethod> MethodsIndex;


class Component : public ConnectableElement
{
public:
	void addPortRequired(std::string name, PortComposantRequired* port);
	void addPortProvided(std::string name, PortComposantProvided* port);

	void info();

	void attachToConnector(Connector* c, std::string portName, std::string roleName);
	void sendNotificationTo(std::string portRequired);
	void on_notify(PortComposantProvided* port);

	std::map<std::string, PortComposantRequired*> _portsRequired;
	std::map<std::string, PortComposantProvided*> _portsProvided;

	//std::map< std::string, a_fun >;
	std::vector<std::string> stub_method( std::vector<std::string> args );

protected:
	// TO remove
	//MethodsIndex _methods_index;

	virtual std::vector<std::string> callback_method( PortComposantProvided* provided_port, std::vector<std::string> args ) {
		std::cout << "Parent callback\n";
	}
private:
	Configuration* _linkedConfiguration;
};

#endif /* COMPONENT_HPP */