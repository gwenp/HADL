#ifndef ROLECONFIGREQUIRED_HPP
#define ROLECONFIGREQUIRED_HPP

#include "RoleConfig.hpp"
#include "RoleRequired.hpp"

class RoleConfigRequired : public RoleConfig
{
public:
	RoleConfigRequired();
	~RoleConfigRequired();
private:
	RoleRequired* _bindingRequired;
};

#endif /* ROLECONFIGREQUIRED_HPP */