#ifndef _H_ConnectionManager_H_
#define _H_ConnectionManager_H_

#include <HADL/Component.hpp>

#include <set>

class ConnectionManager;
typedef std::vector<std::string> (ConnectionManager::*ConnectionManagerMethod)(std::vector<std::string>);
typedef std::map<std::string, ConnectionManagerMethod> ConnectionManagerMethodsIndex;

class ConnectionManager : public Component
{
public:
	ConnectionManager();
	~ConnectionManager();

	std::string getUserPassword( std::string& username );

	str_v authenticate( str_v args );
	str_v makeACoolRequest( str_v args );

	str_v on_message( PortComposantProvided* provided_port, str_v args );

private:
	ConnectionManagerMethodsIndex _methods;


	std::set<std::string> _user_sessions;
};

#endif /* _H_ConnectionManager_H_ */