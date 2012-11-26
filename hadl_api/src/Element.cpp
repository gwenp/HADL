#include "Element.hpp"



void Element::setProperty( const std::string& key, const std::string& value ) {
	_properties[key] = value;
}

std::string Element::getProperty( const std::string& key ) {
	if ( _properties.find(key) != _properties.end() ) {
		return _properties[key];
	}
	else {
		return "";
	}
}

const std::string& Element::getName() const {
	return _name;
}

void Element::setName( const std::string& name) {
	_name = name;
}