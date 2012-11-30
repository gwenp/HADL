#include "Client.hpp"

Client::Client() {


}

Client::~Client() {


}

void Client::start_cli() {

	std::string login;
	std::string password;


	while ( true ) {

		if ( _connected_user.empty() ) {

			std::cout << "Login : ";
			std::cin >> login;
			std::cout << "Password : ";
			std::cin >> password;

			if ( this->login(login,password) ) {
				_connected_user = login;
			}

		}
		else {
			std::cout << ":: " << _connected_user << " > ";
			std::string request;

			std::cin >> request;
			if ( send_a_request(request) ) {
				std::cout << "Success\n";
			}
			else {
				std::cout << "Failure\n";
			}
		}


	}

	std::cout << "Exiting..." << std::endl;

}

void Client::onInit() {
	std::cout << "Init Client" << std::endl;
}

void Client::onLaunch() {
	this->start_cli();
}

bool Client::send_a_request( std::string request_name ) {

	if ( _portsRequired.find("portClient") != _portsRequired.end() ) {
	
		std::cout << "Sending to '" << "portClient" << "'\n";

		str_v args;
		args.push_back("request");
		args.push_back(_connected_user);
		args.push_back(request_name);

		str_v response = _portsRequired["portClient"]->send_message(args);
		std::cout << "Sent !!!\n";
		std::cout << "Response : " << std::endl;
		for ( int i=0; i<response.size(); i++ ) {
			std::cout << "\t- " << response.at(i) << std::endl;
		}

		if ( response.at(0) == "Request Executed !" ) {
			return true;
		}

	}
	else {
		std::cout << "Port not found : " << "portClient" << std::endl;
	}

	return false;

}




bool Client::login( std::string login, std::string password ) {

	str_v args;
	args.push_back("connect");
	args.push_back(login);
	args.push_back(password);
	
	str_v response = _portsRequired["portClient"]->send_message(args);

	if ( response.size() > 0 ) {
		std::cout << "~ Client : Received response : " + response.at(0) + "\n";
		
		return (response.at(0) == "Connected !");
	}
	else {
		return "(empty response)";
	}

	return false;
}


str_v Client::on_message( PortComposantProvided* provided_port, str_v args ) {
	std::cout << "Client callback" << std::endl;


	str_v response;

	if ( _portsRequired_methodNames.find(provided_port) != _portsRequired_methodNames.end() ) {
		std::string& method_name = _portsRequired_methodNames[provided_port];
	
		if ( _methods.find(method_name) != _methods.end() ) {
			response = (this->*_methods[method_name])(args);
		}
		else {
			std::cout << "> '" << method_name << "' : No such method" << std::endl; 
		}
	}

	return response;

}