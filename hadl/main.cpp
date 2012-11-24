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

#include <HADL/MessageP.pb.h>

#include "src/Client.hpp"
#include "src/Server.hpp"
#include "src/CS_Connector.hpp"
#include "src/PortRequiredCS.hpp"
#include "src/PortProvidedCS.hpp"
#include "src/language_tools/LanguageManager.hpp"
#include "src/factories/ClientComponentFactory.hpp"
#include "src/factories/ServerComponentFactory.hpp"
#include "src/factories/CS_ConnectorFactory.hpp"

#include <fstream>
#include <ostream>

int main(int argc, char const* argv[]) {

	LanguageManager l;
	l.registerComponentFactory("Client", new ClientComponentFactory());
	l.registerComponentFactory("Server", new ServerComponentFactory());

	l.registerConnectorFactory("CS_Connector", new CS_ConnectorFactory());

	Client* client = (Client*) l.makeComponent("Client");
	Server* server = (Server*) l.makeComponent("Server");


	CS_Connector* connector = (CS_Connector*) l.makeConnector("CS_Connector");
	
	l.addRequiredPortToComponent("Client", "PortRequisCS");
	l.addProvidedPortToComponent("Server", "PortFourniCS");
	
	l.addRequiredRoleToConnector("CS_Connector", "dqd");
	l.addProvidedRoleToConnector("CS_Connector", "TestP1");
	

	if ( argc > 1 ) {




		client->info();
		server->info();

		if ( !strcmp(argv[1],"server") ) {
			connector->addRoleRequired("dqd", new RoleRequired());
			connector->listen_from(2345);
		}
		else {
			connector->addRoleProvided("TestP1", new RoleProvided());
			connector->addRoleProvided("TestP2", new RoleProvided());
			connector->connect();
		}

	}

	/*
	MessageP* msg = new MessageP();
	msg->set_code(404);
	msg->add_argument("Trololol est");
	msg->add_argument("aaaa");
	msg->set_sender("Maison");
	msg->set_receiver("Bleue");
	std::cout << msg << std::endl;

	std::string str;
	msg->SerializeToString(&str);


	std::cout << str << std::endl;


	MessageP* msg2 = new MessageP();
	msg2->ParseFromString(str);

	std::cout << msg2->argument(0) << std::endl;
	*/
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