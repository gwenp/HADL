#ifndef ROLECONFIGPROVIDED_HPP
#define ROLECONFIGPROVIDED_HPP

#include "RoleConfig.hpp"
#include "RoleProvided.hpp"

class RoleConfigProvided : public RoleConfig
{
public:
	RoleConfigProvided();
	~RoleConfigProvided();
private:
	RoleProvided* _bindingProvided;
};

#endif /* ROLECONFIGPROVIDED_HPP */