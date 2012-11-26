#include "PortComposantRequired.hpp"

#include "RoleProvided.hpp"


str_v PortComposantRequired::send_message( str_v args ) {

	MessageP msg;
	msg.set_type(MessageP::REQUEST);
	for ( int i=0; i<args.size(); i++ ) {
		msg.add_argument( args.at(i) );
	}
	
	MessageP response_msg = _providedRole->propagate_message( msg );
	
	str_v ret_args;
	for ( int i=0; i<response_msg.argument_size(); i++ ) {
		ret_args.push_back(response_msg.argument(i));
	}

	return ret_args;


}