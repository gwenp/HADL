#include "api/Component.hpp"
#include "api/Configuration.hpp"
#include "api/Connector.hpp"
#include "api/Element.hpp"
#include "api/Interface.hpp"
#include "api/InterfaceComposant.hpp"
#include "api/InterfaceConfiguration.hpp"
#include "api/InterfaceConnector.hpp"
#include "api/PortComposant.hpp"
#include "api/PortComposantProvided.hpp"
#include "api/PortComposantRequired.hpp"
#include "api/PortConfig.hpp"
#include "api/PortConfigProvided.hpp"
#include "api/PortConfigRequired.hpp"
#include "api/Role.hpp"
#include "api/RoleConfig.hpp"
#include "api/RoleConfigProvided.hpp"
#include "api/RoleConfigRequired.hpp"
#include "api/RoleProvided.hpp"
#include "api/RoleRequired.hpp"
#include "api/Service.hpp"
#include "api/ServiceProvided.hpp"
#include "api/ServiceRequired.hpp"


int main(int argc, char const *argv[])
{
	Component c;
	Configuration cfg;
	Connector cn;

	c.addPortRequired("sortieCompo", new PortComposantRequired());
	c.addPortProvided("entreeCompo", new PortComposantProvided());

	cn.addRoleProvided("entreeConnec", new RoleProvided());
	cn.addRoleRequired("sortieConnec", new RoleRequired());

	c.info();
	cn.info();

	c.attachToConnector(&cn,"sortieCompo", "entreeConnec");
	cn.attachToComponent(&c,"sortieConnec", "entreeCompo");

	c.sendNotificationTo("sortieCompo");

	return 0;
}