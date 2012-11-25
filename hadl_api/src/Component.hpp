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
	void addPortProvided(std::string name, PortComposantProvided* port, std::string method_index = "");

	void info();

	void attachToConnector(Connector* c, std::string portName, std::string roleName);
	void sendNotificationTo(std::string portRequired);
	
	// DOUBLON
	void on_notify(PortComposantProvided* port);

	virtual std::vector<std::string> on_message( PortComposantProvided* provided_port, std::vector<std::string> args );

	std::map<std::string, PortComposantRequired*> _portsRequired;
	std::map<std::string, PortComposantProvided*> _portsProvided;

	//std::map< std::string, a_fun >;
	str_v stub_method( str_v args );

	static MessageP error_message( std::string& error ) {

		MessageP msg;
		msg.set_sender("");
		msg.set_receiver("");
		//msg.set_code(-1);
		msg.add_argument("Error : " + error );

		return msg;

	}

protected:

	std::map<PortComposantProvided*,std::string> _portsRequired_methodNames;

private:
	Configuration* _linkedConfiguration;
};


#endif /* COMPONENT_HPP */