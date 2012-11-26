#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>
#include "Element.hpp"

class Interface
{
public:

	virtual std::string getType() = 0;
};

#endif /* INTERFACE_HPP */