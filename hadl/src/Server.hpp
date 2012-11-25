#ifndef M1_SERVER_HPP
#define M1_SERVER_HPP

#include <HADL/Component.hpp>

class Server;

typedef std::vector<std::string> (Server::*ServerMethod)(std::vector<std::string>);
typedef std::map<std::string, ServerMethod> ServerMethodsIndex;

class Server : public Component {
public:
	Server();
	~Server();

	str_v receive( str_v args );
	void onInit();
	str_v on_message( PortComposantProvided* provided_port, str_v args );

	/* data */
private:

	ServerMethodsIndex _methods;
};

#endif