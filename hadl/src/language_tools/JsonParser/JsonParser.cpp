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
		Dbg::out("json")  	<< "Failed to parse configuration\n"
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
	Dbg::out("json") << "[JSON] application : " << app.get("name", "").asString() << std::endl;
	
	const Json::Value elements = app["elements"];
	for ( int index = 0; index < elements.size(); ++index )
	{
		JsonParser::parseElement(l, elements[index]);
	}
	
	const Json::Value attachments = app["attachments"];
	for ( int index = 0; index < attachments.size(); ++index )
	{
		JsonParser::parseAttachment(l, attachments[index]);
	}

}

void JsonParser::parseElement(LanguageManager* l, Json::Value elt)
{
	Dbg::out("json") << "[JSON] element : " << elt.get("name", "").asString() << "; type: " << elt.get("type", "").asString() << std::endl;
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
			l->addProvidedPortToComponent(name, portsProvided[index]["name"].asString(),portsProvided[index]["toMethod"].asString());
		}

		const Json::Value properties = elt["properties"];
		JsonParser::parseProperies(l, name, type, properties);

		const Json::Value attachedConfiguration = elt["attachedConfiguration"];
		if(attachedConfiguration.empty())
		{
			Dbg::out("json") << "[JSON] no attachedConfiguration for : " << name << std::endl;
		}
		else
		{
			Dbg::out("json") << "[JSON] Parsing configuration of : " << name << std::endl;
			
			l->attachConfigurationToComponent(name, attachedConfiguration.get("name", "").asString());
			
			const Json::Value elements = attachedConfiguration["elements"];
			for ( int index = 0; index < elements.size(); ++index )
			{
				JsonParser::parseElement(l, elements[index]);
				l->addElementToConfiguration(elements[index]["name"].asString(), elements[index]["type"].asString(), attachedConfiguration.get("name", "").asString());
			}

			const Json::Value bindings = attachedConfiguration["bindings"];
			for ( int index = 0; index < bindings.size(); ++index )
			{
				JsonParser::parseBinding(l, attachedConfiguration.get("name", "").asString(), bindings[index]);
			}


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

			const Json::Value properties = elt["properties"];
			JsonParser::parseProperies(l, name, type, properties);
		}
	}

}

void JsonParser::parseProperies(LanguageManager* l, std::string elementName, std::string elementType, Json::Value properties)
{
	Element* e;
	if(elementType == "Component")
	{
		e = l->getComponent(elementName);
	}
	else
	if(elementType == "Connector")
	{
		e = l->getConnector(elementName);
	}

	std::vector<std::string> propertieslist = properties.getMemberNames();

	for (std::vector<std::string>::iterator it = propertieslist.begin(); it != propertieslist.end(); ++it)
	{
		l->addPropertyToElement(e,(*it), properties.get((*it), "").asString());
	}
}

void JsonParser::parseAttachment(LanguageManager* l, Json::Value attachment)
{
	l->makeAttachment(attachment["fromType"].asString(), attachment["fromName"].asString(), attachment["toType"].asString(), attachment["toName"].asString());
}

void JsonParser::parseBinding(LanguageManager* l, std::string configName, Json::Value binding)
{
	l->addBinding(configName, binding["bindingName"].asString(), binding["type"].asString(), binding["destinationName"].asString() );
}
