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

	/* STUB */
	MessageP msgr;
	msgr.set_sender("me");
	msgr.set_receiver( msg.sender() );
	msg.set_type(MessageP::RESPONSE);

	return msgr;

	/* END STUB */

}