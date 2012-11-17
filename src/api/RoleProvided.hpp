#ifndef ROLEPROVIDED_HPP
#define ROLEPROVIDED_HPP

#include "Role.hpp"
#include "PortComposantRequired.hpp"


class RoleProvided : public Role
{
public:
	RoleProvided();
	~RoleProvided();
private: 
	PortComposantRequired* _portRequired;
};

#endif /* ROLEPROVIDED_HPP */