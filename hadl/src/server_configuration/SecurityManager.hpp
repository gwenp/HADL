#ifndef _H_SecurityManager_H_
#define _H_SecurityManager_H_

#include <HADL/Component.hpp>
#include <algorithm>

class SecurityManager;
typedef std::vector<std::string> (SecurityManager::*SecurityManagerMethod)(std::vector<std::string>);
typedef std::map<std::string, SecurityManagerMethod> SecurityManagerMethodsIndex;


class SecurityManager : public Component
{
public:
	SecurityManager();
	~SecurityManager();

private:

	std::vector<std::string> getUserAbilities( std::string& username );

	str_v isUserAbleTo( str_v args );

	str_v on_message( PortComposantProvided* provided_port, str_v args );

	SecurityManagerMethodsIndex _methods;
	/* data */
};
#endif /* _H_SecurityManager_H_ */