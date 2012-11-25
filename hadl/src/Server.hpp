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

	str_v testm( str_v args );
	void onInit();
	str_v on_message( PortComposantProvided* provided_port, str_v args );

	void dbg_mt(PortComposantProvided* p );
	/* data */
private:

	ServerMethodsIndex _methods;
};

#endif