#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>

class Interface
{
public:
	Interface();
	~Interface();

	virtual std::string getType() = 0;
};

#endif /* INTERFACE_HPP */