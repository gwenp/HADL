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
	MessageP propagate_message( MessageP msg );
private:
	RoleProvided* _bindingProvided;
};

#endif /* ROLECONFIGPROVIDED_HPP */