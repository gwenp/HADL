#ifndef JSONPARSER_HPP
#define JSONPARSER_HPP

#include "../LanguageManager.hpp"

#include <fstream>
// #include <jsoncpp/json/json.h>
#include "libjsoncpp/json.h"
#include "../../Utils/Dbg.hpp"

class LanguageManager;

class JsonParser {
public:
	static void parse(LanguageManager* l, std::string fileUrl, std::string applicationContext);
private:
	static void parseApplication(LanguageManager* l, Json::Value app, Json::Value root);
	static void parseElement(LanguageManager* l, Json::Value element, bool onlyRolesProvided=false);
	static void parseProperies(LanguageManager* l, std::string elementName, std::string elementType, Json::Value properties);
	static void parseAttachment(LanguageManager* l, Json::Value attachment, Json::Value root);
	static void parseBinding(LanguageManager* l, std::string configName, Json::Value binding);

	static void lookForTheLostConnector(LanguageManager* l, std::string connectorName, Json::Value root);
};

#endif