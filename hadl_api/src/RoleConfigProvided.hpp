#ifndef ROLECONFIGPROVIDED_HPP
#define ROLECONFIGPROVIDED_HPP

#include "RoleConfig.hpp"
#include "RoleProvided.hpp"

#include <string>

class RoleConfigProvided : public RoleConfig
{
public:
	std::string getType(){ return "provided"; };

	void bindTo( RoleProvided* roleProvided );
private:
	RoleProvided* _bindingProvided;
};

#endif /* ROLECONFIGPROVIDED_HPP */