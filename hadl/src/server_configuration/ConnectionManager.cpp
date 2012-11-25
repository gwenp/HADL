#include "ConnectionManager.hpp"

ConnectionManager::ConnectionManager() {

	_methods["authenticate"] = &ConnectionManager::authenticate;
	_methods["makeACoolRequest"] = &ConnectionManager::makeACoolRequest;

}



ConnectionManager::~ConnectionManager() {

}

str_v ConnectionManager::authenticate( str_v args ) {

	str_v ret;

	if ( args.size() > 1 ) {
		std::string& username = args.at(0);
		std::string& password = args.at(1);

		/* Ask to DB ? */
		if ( password == password ) {
			_user_sessions.insert(username);
			ret.push_back("ok");
		}

	}

	return ret;

}

str_v ConnectionManager::makeACoolRequest( str_v args ) {

	if ( args.size() > 1 ) {

		std::string& username = args.at(0);

		/* If connected */
		if ( _user_sessions.find(username) != _user_sessions.end() ) {
			std::string& request = args.at(1);

			std::cout << "Do stuff : " << request << std::endl;
		}

	}

}

str_v ConnectionManager::on_message( PortComposantProvided* provided_port, str_v args ) {

	std::cout << "ConnectionManager Callback" << std::endl;

	str_v response;

	if ( _portsRequired_methodNames.find(provided_port) != _portsRequired_methodNames.end() ) {
		std::string& method_name = _portsRequired_methodNames[provided_port];
	
		if ( _methods.find(method_name) != _methods.end() ) {
			response = (this->*_methods[method_name])(args);
		}
	}

	return response;

}
