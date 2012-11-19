#ifndef PORTCOMPOSANTPROVIDED_HPP
#define PORTCOMPOSANTPROVIDED_HPP

#include "PortComposant.hpp"
#include "RoleRequired.hpp"

#include <string>

class PortComposantProvided : public PortComposant
{
public:
	std::string getType(){ return "provided"; };
	RoleRequired* _rolerequired;
private:
};

#endif /* PORTCOMPOSANTPROVIDED_HPP */