#ifndef _H_ConnectionManager_H_
#define _H_ConnectionManager_H_

#include <HADL/Component.hpp>

#include <set>
#include <vector>
#include <algorithm>

class ConnectionManager;
typedef std::vector<std::string> (ConnectionManager::*ConnectionManagerMethod)(std::vector<std::string>);
typedef std::map<std::string, ConnectionManagerMethod> ConnectionManagerMethodsIndex;

class ConnectionManager : public Component
{
public:
	ConnectionManager();
	~ConnectionManager();

	str_v on_message( PortComposantProvided* provided_port, str_v args );

private:

	std::string getUserPassword( std::string& username );
	bool checkUserAbilityFor( std::string& username, std::string& request_type );

	str_v receive_command( str_v args );

	ConnectionManagerMethodsIndex _methods;

	std::set<std::string> _user_sessions;
};

#endif /* _H_ConnectionManager_H_ */