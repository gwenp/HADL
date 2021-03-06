#include "DataBase.hpp"

DataBase::DataBase()
{
	_methods["getPasswordOfUser"] = &DataBase::getPasswordOfUser;
	_methods["getAbilitiesOfUser"] = &DataBase::getAbilitiesOfUser;


	_user_passwords["demo"] = "demo";
	_user_passwords["test_login"] = "test_password";

	str_v abilities;
	abilities.push_back("do_stuff");
	abilities.push_back("cook marmalade");
	abilities.push_back("demo");

	_user_abilities["demo"] = abilities;
}

DataBase::~DataBase()
{}

str_v DataBase::getPasswordOfUser( str_v args ) {

	std::cout << "\tDataBase::getPasswordOfUser" << std::endl;

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

	std::cout << "\tDataBase::getAbilitiesOfUser" << std::endl;

	str_v ret;

	if ( args.size() > 0 ) {
		
		std::string& username = args.at(0);

		if ( _user_abilities.find(username) != _user_abilities.end() ) {
			return _user_abilities[username];
		}
		else {
			ret.push_back(username + " : User not found !");
		}

	}

	return ret;

}


str_v DataBase::on_message( PortComposantProvided* provided_port, str_v args ) {

	std::cout << "[][][] Arrivee au Composant " << _name << "\n";
	std::cout << "\tDataBase Callback" << std::endl;

	str_v response;

	if ( _portsRequired_methodNames.find(provided_port) != _portsRequired_methodNames.end() ) {
		std::string& method_name = _portsRequired_methodNames[provided_port];
	
		if ( _methods.find(method_name) != _methods.end() ) {
			response = (this->*_methods[method_name])(args);
		}
	}

	return response;

}
