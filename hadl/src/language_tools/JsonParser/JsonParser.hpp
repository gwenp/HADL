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
	static void parseApplication(LanguageManager* l, Json::Value app);
	static void parseElement(LanguageManager* l, Json::Value element);
	static void parseProperies(LanguageManager* l, std::string elementName, std::string elementType, Json::Value properties);
	static void parseAttachment(LanguageManager* l, Json::Value attachment);
};

#endif