#ifndef ROLECONFIGPROVIDED_HPP
#define ROLECONFIGPROVIDED_HPP

#include "RoleConfig.hpp"
#include "RoleProvided.hpp"

class RoleConfigProvided : public RoleConfig
{
public:
private:
	RoleProvided* _bindingProvided;
};

#endif /* ROLECONFIGPROVIDED_HPP */