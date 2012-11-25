#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <map>
#include <string>

class Element
{
public:

	void setProperty( const std::string& key, const std::string& value );
	std::string getProperty( const std::string& key );

	virtual void onInit() {};

protected:

	std::map<std::string,std::string> _properties;

};

#endif /* ELEMENT_HPP */