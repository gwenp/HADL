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
//#include "src/PortRequiredCS.hpp"
//#include "src/PortProvidedCS.hpp"
#include "src/language_tools/LanguageManager.hpp"
#include "src/language_tools/JsonParser/JsonParser.hpp"
#include "src/factories/ClientComponentFactory.hpp"
#include "src/factories/ServerComponentFactory.hpp"
#include "src/factories/CS_ConnectorFactory.hpp"
#include "src/factories/DatabaseFactory.hpp"
#include "src/factories/ConnectionManagerFactory.hpp"
#include "src/factories/SecurityManagerFactory.hpp"
#include "src/factories/DefaultConnectorFactory.hpp"

#include "src/Utils/Dbg.hpp"

#include <fstream>
#include <ostream>

int main(int argc, char const* argv[]) {

	Dbg::init("config/debug.conf");

	

	if ( argc > 2 ) {

		LanguageManager l;

		l.registerComponentFactory("Client", new ClientComponentFactory());
		l.registerComponentFactory("Server", new ServerComponentFactory());
		l.registerComponentFactory("Database", new DatabaseFactory());
		l.registerComponentFactory("ConnectionManager", new ConnectionManagerFactory());
		l.registerComponentFactory("SecurityManager", new SecurityManagerFactory());
	
		l.registerConnectorFactory("CS_Connector", new CS_ConnectorFactory());
		l.registerConnectorFactory("Default", new DefaultConnectorFactory());
	
		l.parseJSON(std::string(argv[2]), std::string(argv[1]));
	
	}


	return 0;
}