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

	str_v on_message( PortComposantProvided* provided_port, str_v args );
	str_v test_method( str_v args);

private:
	ClientMethodsIndex _methods;

};

#endif