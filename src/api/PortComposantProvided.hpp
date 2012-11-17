#ifndef PORTCOMPOSANTPROVIDED_HPP
#define PORTCOMPOSANTPROVIDED_HPP

#include "PortComposant.hpp"
#include "RoleRequired.hpp"

class PortComposantProvided : public PortComposant
{
public:
	PortComposantProvided();
	~PortComposantProvided();
private:
	RoleRequired* _rolerequired;
};

#endif /* PORTCOMPOSANTPROVIDED_HPP */