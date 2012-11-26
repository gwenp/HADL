#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <map>
#include <string>

class Element
{
public:

	Element( std::string name = "[unamed]") : _name(name) { };

	void setProperty( const std::string& key, const std::string& value );
	std::string getProperty( const std::string& key );

	const std::string& getName() const;
	void setName( const std::string& name);

	virtual void onInit() {};

protected:

	std::map<std::string,std::string> _properties;
	std::string _name;

};

#endif /* ELEMENT_HPP */