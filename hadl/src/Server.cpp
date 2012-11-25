#include "Server.hpp"

Server::Server() {
	//PortRequired* pr = new PortRequired();
	//_methods["test"] = 

	_methods["testm"] = &Server::testm;

}

Server::~Server() {

}


//Server::ServerMethodsIndex(test);

void Server::onInit() {
	//_methods_index["test"] = &Client::test_method;
	//_methods["test"] = &Component::stub_method;
	std::cout << "Init Server" << std::endl;
}

str_v Server::testm( std::vector<std::string> args ) {
		std::cout << "Server Method" << std::endl;

}

str_v Server::on_message( PortComposantProvided* provided_port, str_v args ) {

	std::cout << "Server Callback" << std::endl;


	str_v response;

	if ( _portsRequired_methodNames.find(provided_port) != _portsRequired_methodNames.end() ) {
		std::string& method_name = _portsRequired_methodNames[provided_port];
	
		if ( _methods.find(method_name) != _methods.end() ) {
			response = (this->*_methods[method_name])(args);
		}
	}

	return response;

}
