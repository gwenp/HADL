#include "Client.hpp"

Client::Client() {


}

Client::~Client() {


}

void Client::start_cli() {

	std::cout << "Type something to send request (test mode): ";
	std::string test;
	std::cin >> test;

	this->send_a_request();
	std::cout << "Request sent to port\n";


	std::cin >> test;

}

void Client::send_a_request() {

	if ( _portsRequired.find("portClient") != _portsRequired.end() ) {

	//if ( _portsRequired.find("portClient") != _portsRequired.end() ) {
	
		std::cout << "Sending to '" << "portClient" << "'\n";

		str_v args;
		args.push_back("test_message");
		args.push_back("test_message_arg2");
		str_v response = _portsRequired["portClient"]->send_message(args);
		std::cout << "Sent !!!\n";
		std::cout << "Response : " << std::endl;
		for ( int i=0; i<response.size(); i++ ) {
			std::cout << "\t- " << response.at(i) << std::endl;
		}
	}
	else {
		std::cout << "Port not found : " << "portClient" << std::endl;
	}

}


void Client::onInit() {


	std::cout << "Init Client" << std::endl;

	this->start_cli();
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