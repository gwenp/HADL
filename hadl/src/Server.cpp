#include "Server.hpp"

Server::Server() {
	//PortRequired* pr = new PortRequired();
	//_methods["test"] = 
}

Server::~Server() {

}


//Server::ServerMethodsIndex(test);

void Server::onInit() {
	//_methods_index["test"] = &Client::test_method;
	//_methods["test"] = &Component::stub_method;
	std::cout << "Init Server" << std::endl;
}

std::vector<std::string> Server::testm( std::vector<std::string> args ) {
		std::cout << "Server Method" << std::endl;

}

std::vector<std::string> Server::on_message( PortComposantProvided* provided_port, std::vector<std::string> args ) {

	std::cout << "Server Callback" << std::endl;


	std::vector<std::string> response;

	if ( _methods.find(provided_port) != _methods.end() ) {
		response = (this->*_methods[provided_port])(args);
	}

	return response;

}

void Server::dbg_mt( PortComposantProvided* p ) {
	_methods[p] = &Server::testm;
}