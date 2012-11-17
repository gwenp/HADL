#ifndef ROLECONFIGREQUIRED_HPP
#define ROLECONFIGREQUIRED_HPP

#include "RoleConfig.hpp"
#include "RoleRequired.hpp"

#include <string>

class RoleConfigRequired : public RoleConfig
{
public:
	std::string getType(){ return "required"; };

private:
	RoleRequired* _bindingRequired;
};

#endif /* ROLECONFIGREQUIRED_HPP */