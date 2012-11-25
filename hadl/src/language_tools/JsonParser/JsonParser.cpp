#include "JsonParser.hpp"

#include "../LanguageManager.hpp"

void JsonParser::parse(LanguageManager* l,std::string fileUrl, std::string applicationContext)
{
	std::ifstream ifs(fileUrl.c_str());

	Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;
	bool parsingSuccessful = reader.parse( ifs, root );

	if ( !parsingSuccessful )
	{
		std::cout  	<< "Failed to parse configuration\n"
					<< reader.getFormattedErrorMessages();
		return;
	}

	const Json::Value apps = root["applications"];
	for ( int index = 0; index < apps.size(); ++index )
	{
		JsonParser::parseApplication(l, apps[index]);
	}
}

void JsonParser::parseApplication(LanguageManager* l, Json::Value app)
{
	std::cout << "[JSON] application : " << app.get("name", "").asString() << std::endl;
	
	const Json::Value elements = app["elements"];
	for ( int index = 0; index < elements.size(); ++index )
	{
		JsonParser::parseElement(l, elements[index]);
	}	
}

void JsonParser::parseElement(LanguageManager* l, Json::Value elt)
{
	std::cout << "[JSON] application : " << elt.get("name", "").asString() << "; type: " << elt.get("type", "").asString() << std::endl;
	std::string type = elt.get("type", "").asString();
	std::string name = elt.get("name", "").asString();
	std::string factory = elt.get("factory", "").asString();

	if(type == "Component")
	{
		l->makeComponent(name, factory);

		const Json::Value portsRequired = elt["PortsRequired"];
		for ( int index = 0; index < portsRequired.size(); ++index )
		{
			l->addRequiredPortToComponent(name, portsRequired[index].asString());
		}

		const Json::Value portsProvided = elt["PortsProvided"];
		for ( int index = 0; index < portsProvided.size(); ++index )
		{
			l->addProvidedPortToComponent(name, portsProvided[index].asString());
		}
	}
	else
	{
		if (type == "Connector")
		{
			l->makeConnector(name, factory);

			const Json::Value rolesRequired = elt["RolesRequired"];
			for ( int index = 0; index < rolesRequired.size(); ++index )
			{
				l->addRequiredRoleToConnector(name, rolesRequired[index].asString());
			}

			const Json::Value rolesProvided = elt["RolesProvided"];
			for ( int index = 0; index < rolesProvided.size(); ++index )
			{
				l->addProvidedRoleToConnector(name, rolesProvided[index].asString());
			}
		}
	}

}