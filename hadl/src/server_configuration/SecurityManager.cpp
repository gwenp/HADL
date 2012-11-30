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
	if ( _portsRequired.find("portRequiredPermissionsStore") != _portsRequired.end() ) {

		std::cout << "Demande de permission utilisateur. Demandons a la DataBase\n" << std::endl;

		str_v request;
		request.push_back(username);

		response = _portsRequired["portRequiredPermissionsStore"]->send_message( request );

		std::cout << "~~ SecurityManager recupere le retour de la DataBase\n" << std::endl;

	}
	else {
		std::cout << "Port Required not found : " << "portRequiredPermissionsStore" << std::endl;
	}

	return response;

}

str_v SecurityManager::isUserAbleTo( str_v args ) {

	std::cout << "\tSecurityManager::isUserAbleTo" << std::endl;

	str_v ret;

	if ( args.size() > 1 ) {
		std::string& username = args.at(0);
		std::string required_ability = args.at(1);

		/* Ask to DB ? */
		std::vector<std::string> abilities = getUserAbilities(username);
		if ( std::find(abilities.begin(), abilities.end(), required_ability) != abilities.end() ) {
			ret.push_back("OK");
		}
		else {
			ret.push_back("Not Allowed !");
		}

	}

	return ret;

}

str_v SecurityManager::on_message( PortComposantProvided* provided_port, str_v args ) {

	std::cout << "[][][] Arrivee au Composant " << _name << "\n";
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
