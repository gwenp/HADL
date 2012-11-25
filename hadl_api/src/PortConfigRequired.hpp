#ifndef PORTCONFIGREQUIRED_HPP
#define PORTCONFIGREQUIRED_HPP

#include "PortConfig.hpp"
#include "PortComposantRequired.hpp"

#include <string>

class PortConfigRequired : public PortConfig
{
public:
	std::string getType(){ return "required"; };

	void bindTo( PortComposantRequired* portRequired );
	MessageP send_message( str_v args );

private:
	PortComposantRequired* _bindingRequired;
};

#endif /* PORTCONFIGREQUIRED_HPP */