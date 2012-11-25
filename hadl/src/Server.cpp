#include "Server.hpp"

Server::Server() {
	//PortRequired* pr = new PortRequired();
}

Server::~Server() {

}


void Server::onInit() {
	//_methods_index["test"] = &Client::test_method;
	//_methods["test"] = &Component::stub_method;

}


std::vector<std::string> Server::callback_method( PortComposantProvided* provided_port, std::vector<std::string>& args ) {

	std::vector<std::string> response;

	if ( _methods.find(provided_port) != _methods.end() ) {
		response = (this->*_methods[provided_port])(args);
	}

	return response;

}