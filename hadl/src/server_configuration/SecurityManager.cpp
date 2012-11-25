#include "SecurityManager.hpp"

SecurityManager::SecurityManager()
{

}

SecurityManager::~SecurityManager()
{
	
}


str_v SecurityManager::on_message( PortComposantProvided* provided_port, str_v args ) {

	std::cout << "SecurityManager Callback" << std::endl;

	str_v response;

	if ( _portsRequired_methodNames.find(provided_port) != _portsRequired_methodNames.end() ) {
		std::string& method_name = _portsRequired_methodNames[provided_port];
	
		if ( _methods.find(method_name) != _methods.end() ) {
			response = (this->*_methods[method_name])(args);
		}
	}

	return response;

}
