#include "ConnectionManager.hpp"

ConnectionManager::ConnectionManager() {

}


ConnectionManager::~ConnectionManager() {

}


str_v ConnectionManager::on_message( PortComposantProvided* provided_port, str_v args ) {

	std::cout << "ConnectionManager Callback" << std::endl;

	str_v response;

	if ( _portsRequired_methodNames.find(provided_port) != _portsRequired_methodNames.end() ) {
		std::string& method_name = _portsRequired_methodNames[provided_port];
	
		if ( _methods.find(method_name) != _methods.end() ) {
			response = (this->*_methods[method_name])(args);
		}
	}

	return response;

}
