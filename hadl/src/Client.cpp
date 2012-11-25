#include "Client.hpp"

Client::Client() {


}

Client::~Client() {


}


str_v Client::test_method( str_v args) {

	std::cout << "Test method called automatically" << std::endl;

}

void Client::onInit() {
	//_methods_index["test"] = &Client::test_method;
	//_methods_index["test"] = &Component::stub_method;

	std::cout << "Init Client" << std::endl;
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