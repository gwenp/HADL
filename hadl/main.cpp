#include "HADL/Component.hpp"
#include "HADL/Configuration.hpp"
#include "HADL/Connector.hpp"
#include "HADL/Element.hpp"
#include "HADL/Interface.hpp"
#include "HADL/InterfaceComposant.hpp"
#include "HADL/InterfaceConfiguration.hpp"
#include "HADL/InterfaceConnector.hpp"
#include "HADL/PortComposant.hpp"
#include "HADL/PortComposantProvided.hpp"
#include "HADL/PortComposantRequired.hpp"
#include "HADL/PortConfig.hpp"
#include "HADL/PortConfigProvided.hpp"
#include "HADL/PortConfigRequired.hpp"
#include "HADL/Role.hpp"
#include "HADL/RoleConfig.hpp"
#include "HADL/RoleConfigProvided.hpp"
#include "HADL/RoleConfigRequired.hpp"
#include "HADL/RoleProvided.hpp"
#include "HADL/RoleRequired.hpp"
#include "HADL/Service.hpp"
#include "HADL/ServiceProvided.hpp"
#include "HADL/ServiceRequired.hpp"

#include "src/Client.hpp"
#include "src/Server.hpp"
#include "src/CS_Connector.hpp"
#include "src/PortRequiredCS.hpp"
#include "src/PortProvidedCS.hpp"


int main(int argc, char const *argv[])
{


	if ( argc > 1 ) {

		PortRequiredCS* pr = new PortRequiredCS();
		PortProvidedCS* pp = new PortProvidedCS();

		Client* client = new Client();
		Server* server = new Server();

		client->addPortRequired( "PortRequisCS", pr );
		server->addPortProvided( "PortFourniCS", pp );

		client->info();
		server->info();

		CS_Connector* connector = new CS_Connector();

	}

	//c.addPortRequired("sortieCompo", new PortComposantRequired());
	//c.addPortRequired("sortieCompoToNULL", new PortComposantRequired());
	//c.addPortProvided("entreeCompo", new PortComposantProvided());
//
//	//cn.addRoleProvided("entreeConnec", new RoleProvided());
//	//cn.addRoleRequired("sortieConnec", new RoleRequired());
//	//cn.addRoleRequired("sortieConnecToNULL", new RoleRequired());
//
//	//c.setParentConfiguration(&cfg);
//	//cn.setParentConfiguration(&cfg);
//
//	//cfg.addPortRequired("entreeConfig", new PortConfigRequired);
//
//	//c.attachToConnector(&cn,"sortieCompo", "entreeConnec");
//	//cn.attachToComponent(&c,"sortieConnec", "entreeCompo");
//
//	//c.sendNotificationTo("sortieCompo");
//	//c.sendNotificationTo("sortieCompoToNULL");
//	//cn.sendNotificationTo("sortieConnec");
//	//cn.sendNotificationTo("sortieConnecToNULL");
//
	return 0;
}