#ifndef H_NETWORK_H
	#define H_NETWORK_H

	#include <signal.h>

	#ifdef WIN32

		#include <winsock2.h> /* Sockets pour Windows */
		typedef int socklen_t;
		
	#elif defined (linux)

		#include <sys/socket.h>
		#include <netdb.h>		/* Host by name */
		#include <linux/types.h>
		#include <sys/ioctl.h>
		#include <net/if.h>

		/* Sous Windows, "winsock2.h" definit certaines constantes qui ne sont pas definies par "socket.h" sous Linux */
		#define INVALID_SOCKET -1
		#define SOCKET_ERROR -1

		/* Macro pour remplacer les 'closesocket' par 'close' sous Linux */
		#define	closesocket(s) close(s)
		
		/* Sous Windows, le type SOCKET (qui, en fait, est un 'int') est obligatoire.
		On va donc definir le type SOCKET sous Linux comme etant un 'int', pour maximiser la portabilite du programme */
		#ifndef SOCKET
			typedef int SOCKET; 
		#endif

		/* Divergences egalement pour le nom des structures (casse) */
		typedef struct sockaddr_in SOCKADDR_IN;
		typedef struct sockaddr	SOCKADDR;
		typedef struct in_addr IN_ADDR;

	#endif
	
	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
		
	#define TEST_PORT 2345
	#define NB_MAX_CLIENTS 10

	//struct InterfaceConnector;

	typedef struct connector_and_sock {
		void* connector;
		SOCKET socket;
	} connector_and_sock_t;

	typedef struct connector_and_port {
		void* connector;
		int port;
		void* (*callback)( void* );
	} connector_port_callback_t;


	typedef struct delimited_data {
		int32_t length;
		char* data;
	} delimited_data_t;

	/* Debug */
	void hexdump(void *mem, unsigned int len);

	void* wait_for_clients( void* data );
	SOCKET connect_to_server( const char* server_name, int port ) ;
	int disconnect() ;

	int receive_data( SOCKET sock, char* buffer );
	int send_data( SOCKET sock, const char* buffer, int32_t size );


	void init_exit_signals();

#endif