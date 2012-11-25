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
	/* Should be private ? */
	void listen_from( int port );
	void connect();
	void monitoring_routine( SOCKET sock );



private:
	virtual MessageP glue_message_propagation( MessageP msg, const std::string& role );

 	/** BEGIN NETWORKING **/

	MessageP generate_discovery_message( MessageP::DiscoverType disco_type );
	void interpret_discovery_message( MessageP msg, SOCKET sock );

	SOCKET connect_to( std::string host, int port ); // Connect

	void wait_for_messages_ntk( SOCKET sock );

	MessageP receive_message_ntk( SOCKET sock );
	MessageP send_message_ntk( SOCKET sock, MessageP& msg, bool needs_response = true );

	void on_message_received_ntk( MessageP& msg, SOCKET sock = INVALID_SOCKET );

	void send_discoveries_ntk( SOCKET sock );



	// Temp ? Can be used to store Roles
	std::map<std::string, SOCKET> _rolesProvided_connections;
	std::map<SOCKET,std::string> _rolesProvided_connections_reverse;

	std::map<std::string, SOCKET> _rolesRequired_connections;
	std::map<SOCKET,std::string> _rolesRequired_connections_reverse;


	/* Used for receiving messages */
	std::queue<MessageP> _messages_queue;
	//std::string _rcv_messages_buffer;

	/** END NETWORKING **/

	/* data */
};

#endif