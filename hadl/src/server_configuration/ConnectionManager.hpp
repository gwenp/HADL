#ifndef _H_ConnectionManager_H_
#define _H_ConnectionManager_H_

#include <HADL/Component.hpp>


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
	ConnectionManagerMethodsIndex _methods;

};

#endif /* _H_ConnectionManager_H_ */