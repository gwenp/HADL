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

#include <fstream>
#include <ostream>

int main(int argc, char const* argv[]) {


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