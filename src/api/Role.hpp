#ifndef ROLE_HPP
#define ROLE_HPP

#include "InterfaceConnector.hpp"

class Connector;

class Role : public InterfaceConnector
{
public:
	void setConnector(Connector* c){ _connector=c; };
	Connector* getConnector(){ return _connector; };

private:
	Connector* _connector;
};

#endif /* ROLE_HPP */