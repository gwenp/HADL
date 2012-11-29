#ifndef M1_CSCONNECTOR_HPP
#define M1_CSCONNECTOR_HPP

#include <HADL/Connector.hpp>


extern "C" {
	#include "networking.h"
}


class CS_Connector : public Connector {
public:
	CS_Connector();
	~CS_Connector();

	virtual void onInit();
	void monitoring_routine( SOCKET sock );

private:
	virtual MessageP glue_message_propagation( MessageP msg, const std::string& role );


 	/** BEGIN NETWORKING **/

	void listen_from( int port );


	void exchange_discoveries_ntk( SOCKET sock );

	MessageP generate_discovery_message( MessageP::DiscoverType disco_type );
	void interpret_discovery_message( MessageP msg, SOCKET sock );

	SOCKET connect_to( std::string host, int port ); // Connect

	void wait_for_messages_ntk( SOCKET sock );

	MessageP receive_message_ntk( SOCKET sock );
	MessageP send_message_ntk( SOCKET sock, MessageP& msg, bool needs_response = true );

	void on_message_received_ntk( MessageP& msg, SOCKET sock = INVALID_SOCKET );

	void send_discoveries_ntk( SOCKET sock );


	std::map<std::string, SOCKET> _rolesProvided_connections;

	std::map<std::string, SOCKET> _rolesRequired_connections;

	/* Used for receiving messages */
	std::queue<MessageP> _messages_queue;

	/** END NETWORKING **/

};

#endif