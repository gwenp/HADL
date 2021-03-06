#include "PortComposantProvided.hpp"

#include "Component.hpp"

MessageP PortComposantProvided::receive_message( MessageP msg ) {

	std::cout << "@@@ Passage par PortFourni '" << _name << "' @@@\n";

	/* Ici lancer la methode associee au composant */

	MessageP reponse_message;
	reponse_message.set_type(MessageP::RESPONSE);

	if ( _component != NULL ) {

		std::vector<std::string> args;
		for ( int i=0; i<msg.argument_size(); i++ ) {
			args.push_back( msg.argument(i) );
		}

		std::vector<std::string> response_args;
		response_args = _component->on_message(this,args);

		std::cout << "<<< Retourne par PortFourni '" << _name << "'\n";
		std::cout << "--- Arguments retournes : \n";
		for ( int i=0; i<response_args.size(); i++ ) {
			std::cout << "+ " << response_args.at(i) << std::endl;
			reponse_message.add_argument( response_args.at(i) );
		}

	}
	else {
		std::cout << "Error : Port has not Component\n";
	}

	reponse_message.set_receiver( msg.sender() );

	return reponse_message;

}