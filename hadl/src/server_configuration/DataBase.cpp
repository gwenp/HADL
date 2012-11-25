#include "DataBase.hpp"

DataBase::DataBase()
{
	_methods["getPasswordOfUser"] = &DataBase::getPasswordOfUser;
	_methods["getAbilitiesOfUser"] = &DataBase::getAbilitiesOfUser;
}

DataBase::~DataBase()
{}

str_v DataBase::getPasswordOfUser( str_v args ) {

	str_v ret;

	if ( args.size() > 0 ) {

		std::string& username = args.at(0);

		if ( _user_passwords.find(username) != _user_passwords.end() ) {

			ret.push_back(_user_passwords[username]);

		}

	}

	return ret;

}

str_v DataBase::getAbilitiesOfUser( str_v args ) {


	str_v ret;

	if ( args.size() > 0 ) {
		
		std::string& username = args.at(0);

		if ( _user_passwords.find(username) != _user_passwords.end() ) {
			return _user_abilities[username];
		}

	}

	return ret;

}


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
