#ifndef PORTCONFIG_HPP
#define PORTCONFIG_HPP

#include "InterfaceConfiguration.hpp"

class Configuration;

class PortConfig : public InterfaceConfiguration
{
public:
	Configuration* getConfiguration();
	void setConfiguration(Configuration* c);
private:
	Configuration* _configuration;	
};

#endif /* PORTCONFIG_HPP */