#include "ConnectionManager.hpp"

ConnectionManager::ConnectionManager() {

	_methods["receive_command"] = &ConnectionManager::receive_command;
	//_methods["makeACoolRequest"] = &ConnectionManager::makeACoolRequest;

}



ConnectionManager::~ConnectionManager() {

}

std::string ConnectionManager::getUserPassword( std::string& username ) {

	if ( _portsRequired.find("portRequiredAuthentication") != _portsRequired.end() ) {

		std::cout << "Demande du mot de passe. Demandons a la DataBase\n" << std::endl;

		str_v request;
		request.push_back(username);

		str_v response = _portsRequired["portRequiredAuthentication"]->send_message( request );

		std::cout << "~~ ConnectionManager recupere le retour de la DataBase\n" << std::endl;


		if ( response.size() > 0 ) {
			std::cout << "Response : " << response.at(0) << std::endl;
			return response.at(0);
		}

	}

	return "";

}

bool ConnectionManager::checkUserAbilityFor( std::string& username, std::string& request_type ) {

	if ( _portsRequired.find("portRequiredUserAbility") != _portsRequired.end() ) {

		std::cout << "Requete specifique. Demandons au SecurityManager\n" << std::endl;

		str_v request;
		request.push_back(username);
		request.push_back(request_type);

		str_v response = _portsRequired["portRequiredUserAbility"]->send_message( request );

		std::cout << "~~ ConnectionManager recupere le retour du SecurityManager\n" << std::endl;


		if ( response.size() > 0 ) {
			std::cout << "Response : " << response.at(0) << std::endl;
			return ( response.at(0) == "OK" );

		}

	}

	return false;

}

str_v ConnectionManager::receive_command( str_v args ) {

	std::cout << "\tConnectionManager::receive_command" << std::endl;

	str_v ret;

	if ( args.size() > 2 ) {

		std::string& username = args.at(1);

		if ( args.at(0) == "connect" ) {

			std::string& password = args.at(2);

			/* Ask to DB ? */
			if ( password == this->getUserPassword(username) ) {
				_user_sessions.insert(username);
				ret.push_back("Connected !");
			}
			else {
				ret.push_back("Denied");
			}
		}
		else if ( args.at(0) == "request" ) {
			std::string& request_type = args.at(2);

			if ( _user_sessions.find(username) != _user_sessions.end() ) {

				if ( checkUserAbilityFor(username,request_type) ) {
					// A fictive Component executes the request
					ret.push_back("Request Executed !");
				}
				else {
					ret.push_back("You haven't permission to do that ! :'(");
				}

			}
			else {
				ret.push_back("You are not connected !");
			}

		}
		else if ( args.at(0) == "disconnect" ) {
			// STUB
			ret.push_back("Successfully disconnected");
		}
		else {
			ret.push_back("Bad request : '" + args.at(0) + "'");
		}

	}
	else {
		ret.push_back("Too few arguments.");
	}

	return ret;

}


str_v ConnectionManager::on_message( PortComposantProvided* provided_port, str_v args ) {

	std::cout << "[][][] Arrivee au Composant " << _name << "\n";
	std::cout << "\tConnectionManager Callback" << std::endl;

	str_v response;

	if ( _portsRequired_methodNames.find(provided_port) != _portsRequired_methodNames.end() ) {
		std::string& method_name = _portsRequired_methodNames[provided_port];
	
		if ( _methods.find(method_name) != _methods.end() ) {
			response = (this->*_methods[method_name])(args);
		}
	}

	return response;

}
