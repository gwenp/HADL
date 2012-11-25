#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <map>
#include <string>

class Element
{
public:

	void setProperty( const std::string& key, const std::string& value );
	std::string getProperty( const std::string& key );

protected:

	virtual void onInit() {};
	std::map<std::string,std::string> _properties;

};

#endif /* ELEMENT_HPP */