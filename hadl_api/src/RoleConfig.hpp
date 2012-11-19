#ifndef ROLECONFIG_HPP
#define ROLECONFIG_HPP

#include "InterfaceConfiguration.hpp"

class Configuration;

class RoleConfig : public InterfaceConfiguration
{
public:
	Configuration* getConfiguration();
	void setConfiguration(Configuration* c);

private:
	Configuration* _configuration;
};

#endif /* ROLECONFIG_HPP */