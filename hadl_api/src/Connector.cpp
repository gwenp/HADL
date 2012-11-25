#include "Connector.hpp"

#include "Component.hpp"

void Connector::addRoleProvided(std::string name, RoleProvided* role, std::string& linkedRole)
{
	role->setConnector(this);
	_rolesProvided.insert(std::pair<std::string, RoleProvided*>(name, role));
	_roles_association[name] = linkedRole;
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


/* Other side */




MessageP Connector::propagate_message( MessageP msg ) {

	/* Get sender ROLE */
	//const std::string& role_to = msg.receiver();
	const std::string& role_from = msg.sender();
	//const std::string& role_to = _roles_association[msg.sender()];

	if ( _roles_association.find(role_from) != _roles_association.end() ) {
		return this->glue_message_propagation( msg, _roles_association[role_from] );
	}
	else {
		std::cout << "Error : No linked role for '" << role_from << "'" << std::endl;
	}
}

MessageP Connector::glue_message_propagation( MessageP msg, const std::string& role ) {

	if ( _rolesRequired.find( role ) != _rolesRequired.end() ) {
		/* Direct sending */
		return _rolesRequired[role]->propagate_message( msg );
	}

	std::cout << "Cannot route message (unknown dest/action)\n";
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