#ifndef _H_SecurityManager_H_
#define _H_SecurityManager_H_

#include <HADL/Component.hpp>

class SecurityManager;
typedef std::vector<std::string> (SecurityManager::*SecurityManagerMethod)(std::vector<std::string>);
typedef std::map<std::string, SecurityManagerMethod> SecurityManagerMethodsIndex;


class SecurityManager : public Component
{
public:
	SecurityManager();
	~SecurityManager();


	str_v isUserAbleTo( str_v args );

	str_v on_message( PortComposantProvided* provided_port, str_v args );

private:
	SecurityManagerMethodsIndex _methods;
	/* data */
};
#endif /* _H_SecurityManager_H_ */