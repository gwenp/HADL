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
	virtual void onLaunch() {};

	void addPortRequired( PortComposantRequired* port );
	void addPortProvided( PortComposantProvided* port, std::string method_index = "" );

	void info();

	virtual std::vector<std::string> on_message( PortComposantProvided* provided_port, std::vector<std::string> args );

	std::map<std::string, PortComposantRequired*> _portsRequired;
	std::map<std::string, PortComposantProvided*> _portsProvided;
	
protected:

	std::map<PortComposantProvided*,std::string> _portsRequired_methodNames;
	Configuration* _linkedConfiguration;
};


#endif /* COMPONENT_HPP */