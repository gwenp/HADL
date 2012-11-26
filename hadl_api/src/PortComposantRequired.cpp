#include "PortComposantRequired.hpp"

#include "RoleProvided.hpp"


str_v PortComposantRequired::send_message( str_v args ) {

	std::cout << "@@@ Passage par PortRequis @@@\n";
	std::cout << "--- Sent arguments : " << std::endl;
	for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it) {
		std::cout << "+ " << (*it) << std::endl;
	}

	MessageP msg;
	msg.set_type(MessageP::REQUEST);
	for ( int i=0; i<args.size(); i++ ) {
		msg.add_argument( args.at(i) );
	}
	
	MessageP response_msg;
	
	if ( _providedRole != NULL ) {
		response_msg = _providedRole->propagate_message( msg );
	}
	else {
		std::cout << "ProvidedRole not found" << std::endl;
	}

	std::cout << "<<< Retourne par PortRequis <<<\n";
	std::cout << "--- Arguments retournes : \n";
	str_v ret_args;
	for ( int i=0; i<response_msg.argument_size(); i++ ) {
		ret_args.push_back(response_msg.argument(i));
		std::cout << "+ " << response_msg.argument(i) << std::endl;
	}
	std::cout << ".\n";


	return ret_args;

}