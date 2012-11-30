#ifndef _H_DataBase_H_
#define _H_DataBase_H_

#include <HADL/Component.hpp>

class DataBase;
typedef std::vector<std::string> (DataBase::*DataBaseMethod)(std::vector<std::string>);
typedef std::map<std::string, DataBaseMethod> DataBaseMethodsIndex;


class DataBase : public Component {
public:
	DataBase();
	~DataBase();

	str_v on_message( PortComposantProvided* provided_port, str_v args );

private:

	str_v getPasswordOfUser( str_v args );
	str_v getAbilitiesOfUser( str_v args );


	DataBaseMethodsIndex _methods;
	/* data */

	std::map<std::string,std::string> _user_passwords;
	std::map<std::string,str_v> _user_abilities;
};
#endif /* _H_DataBase_H_ */