#ifndef M1_CLIENT_HPP
#define M1_CLIENT_HPP

#include <HADL/Component.hpp>

class Client;

typedef std::vector<std::string> (Client::*ClientMethod)(std::vector<std::string>);
typedef std::map<std::string, ClientMethod> ClientMethodsIndex;

class Client : public Component {
public:
	Client();
	~Client();

	void onInit();
	void onLaunch();

	void start_cli();

	bool send_a_request( std::string request_name );
	bool login( std::string login, std::string password );


	str_v on_message( PortComposantProvided* provided_port, str_v args );

private:
	ClientMethodsIndex _methods;

	std::string _connected_user;

};

#endif