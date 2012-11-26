#include "PortComposantProvided.hpp"

#include "Component.hpp"

/*
PortComposantProvided::PortComposantProvided( ComponentMethod component_method ) {
	
	_component_method = component_method;

}
*/
void PortComposantProvided::notifyComponent()
{
	getComponent()->on_notify(this);
}

MessageP PortComposantProvided::receive_message( MessageP msg ) {

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

		for ( int i=0; i<response_args.size(); i++ ) {
			reponse_message.add_argument( response_args.at(i) );
		}

	}

	reponse_message.set_receiver( msg.sender() );

	return reponse_message;

}