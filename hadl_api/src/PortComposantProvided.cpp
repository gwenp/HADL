#include "PortComposantProvided.hpp"

#include "Component.hpp"

//PortComposantProvided::PortComposantProvided( (Component::*my_memfunc_ptr)(std::vector<std::string>) ) {
//	
//}

void PortComposantProvided::notifyComponent()
{
	getComponent()->on_notify(this);
}

MessageP PortComposantProvided::receive_message( MessageP msg ) {

	// DO WORK
	/* Ici lancer la methode associee au composant */

	// return _composant->ma_mem_fun(msg);

	/* STUB */
	MessageP msgr;
	msgr.set_sender("me");
	msgr.set_receiver( msg.sender() );

	return msgr;

	/* END STUB */

}