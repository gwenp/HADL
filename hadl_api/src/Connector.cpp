#include "Connector.hpp"

#include "Component.hpp"

void Connector::addRoleProvided(std::string name, RoleProvided* role)
{
	role->setConnector(this);
	_rolesProvided.insert(std::pair<std::string, RoleProvided*>(name, role));
}

void Connector::addRoleRequired(std::string name, RoleRequired* role)
{
	role->setConnector(this);
	_rolesRequired.insert(std::pair<std::string, RoleRequired*>(name, role));
}

void Connector::info()
{
	std::cout << "Connector:======================" << std::endl
			<< "\t Roles Required :" << std::endl;
	for (std::map<std::string, RoleRequired*>::iterator it = _rolesRequired.begin(); it != _rolesRequired.end(); ++it)
	{
		std::cout << "\t\t" << (*it).first << std::endl;
	}

	std::cout << "\t Roles Provided :" << std::endl;
	for (std::map<std::string, RoleProvided*>::iterator it = _rolesProvided.begin(); it != _rolesProvided.end(); ++it)
	{
		std::cout << "\t\t" << (*it).first << std::endl;
	}

	std::cout << std::endl;
}

void Connector::on_notify(RoleProvided* port)
{
	std::cout << "Connector notification received!" <<std::endl;
}

void Connector::attachToComponent(Component* c, std::string roleName, std::string portName)
{
	if(getParentConfiguration() == c->getParentConfiguration())
	{
		PortComposantProvided* port = c->_portsProvided[portName];
		_rolesRequired[roleName]->_portProvided = port;
	}
	else
		std::cout << "[ERROR] : The Connector and the Component does not have the same parent Configuration!" <<std::endl;
}

//void Connector::sendNotificationTo( std::string roleRequired, MessageP& msg ) {
//
//	if ( _rolesRequired.find( roleRequired ) != _rolesRequired.end() ) {
//		_rolesRequired[roleRequired]->propagateNotificationToPort();
//	}
//	else if ( _rolesRequired_connections.find( roleRequired ) != _rolesRequired_connections.end() ) {
//		//this->send_message_ntk(_rolesRequired_connections[roleRequired],msg);
//	}
//
//
//}


/* Other side */




MessageP Connector::propagate_message( MessageP msg ) {

	/* Get sender ROLE */
	const std::string& role_from = msg.sender();

	/* Find associated ROLE */
	if ( _roles_association.find( role_from ) != _roles_association.end() ) {

		return this->glue_message_propagation( msg, _roles_association[role_from] );
	}

	std::cout << "Cannot route message (unknown dest/action)\n";
	/* TODO error message */
	return msg; 
}

MessageP Connector::glue_message_propagation( MessageP msg, const std::string& role ) {

	if ( _rolesRequired.find( role ) != _rolesRequired.end() ) {
		/* Direct sending */
		return _rolesRequired[role]->propagate_message( msg );
	}
	
	/*
	else if ( _rolesRequired_connections.find( role ) != _rolesRequired_connections.end() ) {
		return this->send_message_ntk(_rolesRequired_connections[role],msg);
	}
	*/

}



void Connector::debug_message( MessageP& msg ) {

	std::cout << "<------------------------" << std::endl;

	std::cout << "From : " << msg.sender() << std::endl;
	std::cout << "To : " << msg.receiver() << std::endl;
	std::cout << "Type : " << msg.type() << std::endl;

	int size = msg.argument_size();
	if ( size > 0 ) {
		std::cout << "Arguments (" << size <<  ") : " << std::endl;

		for ( int i=0; i<size; i++ ) {
			std::cout << " - " << msg.argument(i) << std::endl;
		}

	}

	std::cout << "------------------------>" << std::endl;


}