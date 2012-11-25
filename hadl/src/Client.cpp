#include "Client.hpp"

Client::Client() {


}

Client::~Client() {


}


std::vector<std::string> Client::test_method(std::vector<std::string> args) {

	std::cout << "Test method called automatically" << std::endl;

}

void Client::onInit() {
	//_methods_index["test"] = &Client::test_method;
	//_methods_index["test"] = &Component::stub_method;

	std::cout << "Init Client" << std::endl;
}

std::vector<std::string> Client::callback_method( PortComposantProvided* provided_port, std::vector<std::string>& args ) {
	std::cout << "Server callback (epic win)" << std::endl;
}