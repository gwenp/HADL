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

	virtual void onInit();
	virtual std::vector<std::string> callback_method( PortComposantProvided* provided_port, std::vector<std::string>& args );

	/* data */
private:

	ServerMethodsIndex _methods;
};

#endif