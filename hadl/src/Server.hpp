#ifndef M1_SERVER_HPP
#define M1_SERVER_HPP

#include <HADL/Component.hpp>

class Server;

typedef std::vector<std::string> (Server::*ServerMethod)(std::vector<std::string>);
typedef std::map<PortComposantProvided*, ServerMethod> ServerMethodsIndex;

class Server : public Component {
public:
	Server();
	~Server();

	std::vector<std::string> testm( std::vector<std::string> args );
	void onInit();
	std::vector<std::string> on_message( PortComposantProvided* provided_port, std::vector<std::string> args );

	/* data */
private:

	ServerMethodsIndex _methods;
};

#endif