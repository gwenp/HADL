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
	std::cout << "Server callback (epic win)" << std::endl;
}