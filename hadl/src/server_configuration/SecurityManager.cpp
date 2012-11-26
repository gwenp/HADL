#include "SecurityManager.hpp"

SecurityManager::SecurityManager()
{
	_methods["isUserAbleTo"] = &SecurityManager::isUserAbleTo;
}

SecurityManager::~SecurityManager()
{
	
}

std::vector<std::string> SecurityManager::getUserAbilities( std::string& username ) {

	std::vector<std::string> response;
	if ( _portsRequired.find("portRequiredLoginSecurity") != _portsRequired.end() ) {

		str_v request;
		request.push_back(username);

		response = _portsRequired["portRequiredLoginSecurity"]->send_message( request );

	}
	else {
		std::cout << "Port Required not found : " << "portRequiredLoginSecurity" << std::endl;
	}

	return response;

}

str_v SecurityManager::isUserAbleTo( str_v args ) {

	std::cout << "\tSecurityManager::isUserAbleTo" << std::endl;

	str_v ret;

	if ( args.size() > 0 ) {
		std::string& username = args.at(0);
		std::string required_ability = "cook marmalade";

		std::cout << "Asking for DB ...\n";
		/* Ask to DB ? */
		std::vector<std::string> abilities = getUserAbilities(username);
		if ( std::find(abilities.begin(), abilities.end(), required_ability) != abilities.end() ) {
			ret.push_back("granted");
		}
		else {
			ret.push_back("denied");
		}

	}

	return ret;

}

str_v SecurityManager::on_message( PortComposantProvided* provided_port, str_v args ) {

	std::cout << "[][][] Arrivee au Composant\n";
	std::cout << "\tSecurityManager Callback" << std::endl;

	str_v response;

	if ( _portsRequired_methodNames.find(provided_port) != _portsRequired_methodNames.end() ) {
		std::string& method_name = _portsRequired_methodNames[provided_port];
	
		if ( _methods.find(method_name) != _methods.end() ) {
			response = (this->*_methods[method_name])(args);
		}
	}

	return response;

}
