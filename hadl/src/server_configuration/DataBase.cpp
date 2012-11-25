#include "DataBase.hpp"

DataBase::DataBase()
{

}

DataBase::~DataBase()
{}


str_v DataBase::on_message( PortComposantProvided* provided_port, str_v args ) {

	std::cout << "DataBase Callback" << std::endl;

	str_v response;

	if ( _portsRequired_methodNames.find(provided_port) != _portsRequired_methodNames.end() ) {
		std::string& method_name = _portsRequired_methodNames[provided_port];
	
		if ( _methods.find(method_name) != _methods.end() ) {
			response = (this->*_methods[method_name])(args);
		}
	}

	return response;

}
