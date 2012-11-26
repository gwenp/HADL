#include "Server.hpp"

Server::Server() {
	//PortRequired* pr = new PortRequired();
	//_methods["test"] = 

	_methods["receive"] = &Server::receive;

}

Server::~Server() {

}


//Server::ServerMethodsIndex(test);

void Server::onInit() {
	std::cout << "Init Server" << std::endl;
}

str_v Server::receive( std::vector<std::string> args ) {

	std::cout << "Server Method" << std::endl;
	str_v ret;
	ret.push_back("Hello ! That's my response !");

	return ret;
}

str_v Server::on_message( PortComposantProvided* provided_port, str_v args ) {

	str_v response;

	if ( _linkedConfiguration != NULL ) {

		std::cout << "Server Callback" << std::endl;
		
		if ( _portsRequired_methodNames.find(provided_port) != _portsRequired_methodNames.end() ) {
			std::string& method_name = _portsRequired_methodNames[provided_port];
		
			if ( _methods.find(method_name) != _methods.end() ) {
				response = (this->*_methods[method_name])(args);
			}
		}

	}

	return response;

}
