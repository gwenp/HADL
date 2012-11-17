#ifndef PORTCOMPOSANTPROVIDED_HPP
#define PORTCOMPOSANTPROVIDED_HPP

#include "PortComposant.hpp"
#include "RoleRequired.hpp"

class PortComposantProvided : public PortComposant
{
public:
private:
	RoleRequired* _rolerequired;
};

#endif /* PORTCOMPOSANTPROVIDED_HPP */