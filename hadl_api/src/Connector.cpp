#include "Connector.hpp"

#include "Component.hpp"

void Connector::addRoleProvided( RoleProvided* role, std::string& linkedRole)
{
	role->setConnector(this);
	_rolesProvided.insert(std::pair<std::string, RoleProvided*>(role->getName(), role));
	_roles_association[role] = linkedRole;
}

void Connector::addRoleRequired( RoleRequired* role)
{
	role->setConnector(this);
	_rolesRequired.insert(std::pair<std::string, RoleRequired*>(role->getName(), role));
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


/* Other side */

MessageP Connector::on_message_from_provided_role( RoleProvided* from, MessageP msg ) {

	/* Get sender ROLE */
	if ( _roles_association.find(from) != _roles_association.end() ) {
		//std::cout << "Local role found : " << _roles_association[from] << std::endl;
		return this->propagate_message( msg, _roles_association[from] );
	}
	else {
		std::cout << "Error : No linked role for '" << "a role" << "'" << std::endl;
		return error_message("Role unreachable");
	}

}


MessageP Connector::propagate_message( MessageP msg, const std::string& role ) {

	std::cout << "=== Passage par Connecteur " << _name << "::propagate_message() vers Role " << role << " @@@\n";

	msg.set_receiver(role);
	/* Get sender ROLE */
	if ( _rolesRequired.find( role ) != _rolesRequired.end() ) {
		/* Direct sending */
		return _rolesRequired[role]->propagate_message( msg );
	}
	else {
		return glue_message_propagation(msg,role);
	}

}

MessageP Connector::glue_message_propagation( MessageP msg, const std::string& role ) {

	std::cout << "Cannot route message (unknown dest/action)\n";

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