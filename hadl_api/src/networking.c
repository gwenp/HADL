#include "networking.h"

//#include "InterfaceConnector.hpp"

void onSigTerm() {
	printf("Graceful exit\n");

}

#ifndef HEXDUMP_COLS
#define HEXDUMP_COLS 8
#endif
 
void hexdump(void *mem, unsigned int len)
{
        unsigned int i, j;
        
        for(i = 0; i < len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) : 0); i++)
        {
                /* print offset */
                if(i % HEXDUMP_COLS == 0)
                {
                        printf("0x%06x: ", i);
                }
 
                /* print hex data */
                if(i < len)
                {
                        printf("%02x ", 0xFF & ((char*)mem)[i]);
                }
                else /* end of block, just aligning for ASCII dump */
                {
                        printf("   ");
                }
                
                /* print ASCII dump */
                if(i % HEXDUMP_COLS == (HEXDUMP_COLS - 1))
                {
                        for(j = i - (HEXDUMP_COLS - 1); j <= i; j++)
                        {
                                if(j >= len) /* end of block, not really printing */
                                {
                                        putchar(' ');
                                }
                                else if(isprint(((char*)mem)[j])) /* printable char */
                                {
                                        putchar(0xFF & ((char*)mem)[j]);        
                                }
                                else /* other char */
                                {
                                        putchar('.');
                                }
                        }
                        putchar('\n');
                }
        }
}

void init_exit_signals() {
	#ifdef WIN32
		signal( SIGINT, onSigTerm);
		signal( SIGTERM, onSigTerm);
	#elif defined (linux)
		struct sigaction act;

		act.sa_flags = SA_SIGINFO;
		act.sa_handler = onSigTerm;      /* fonction à lancer */

		sigemptyset(&act.sa_mask);        /* rien à masquer */

		sigaction(SIGINT, &act, NULL);    /* fin contrôle-C */
		sigaction(SIGTERM, &act, NULL);   /* arrêt */
	#endif
}

int receive_data( SOCKET sock, char* buffer ) {

	int recv_size;
	if ( ( recv_size = recv(sock, buffer, 4096, 0) ) <= 0 )  {

		printf("Socket Error. Closing\n");
		shutdown(sock,SHUT_RDWR);
		return -2;

	}
	
	//printf(" -- received : %d bytes\n",recv_size);
	//printf(" ---- RAW\n");
	//hexdump(buffer,recv_size);

	return recv_size;

}


int send_data( SOCKET sock, const char* buffer, int32_t size ) {

	int size_to_send = size+sizeof(size);
	char* delimited_buffer = (char*) malloc(size_to_send);

	memcpy(delimited_buffer,&size,sizeof(size));
	memcpy(&delimited_buffer[sizeof(size)],buffer,size);

	int sent_size;
	if ( ( sent_size = send(sock, delimited_buffer, size_to_send , 0) ) < 0 )  {

		return -2;

	}

	//printf(" -- sent : %d bytes with %d utils (%s)\n",sent_size,size);
	//printf("=======================\n");
	//hexdump(buffer,sent_size);
	//printf(" ------ RAW\n");
	//hexdump(delimited_buffer,sent_size);

	return sent_size;

}


/* Fonction de depart. Attente des Clients et creation d'un Thread par Client */
void* wait_for_clients( void* data ) {

	connector_port_callback_t* cp = (connector_port_callback_t*) data;

	#ifdef WIN32
		WSADATA wsa;
		WSAStartup(MAKEWORD(2, 2), &wsa);
	#endif

	SOCKADDR_IN local_address;
	SOCKET sock = INVALID_SOCKET;
	socklen_t la_size = sizeof(local_address);

	if ( (sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET ) {
		printf("Error : Unable to listen\n");
		return 3;
	}
	
	local_address.sin_addr.s_addr = htonl(INADDR_ANY);
	local_address.sin_family = AF_INET;
	local_address.sin_port = htons(cp->port);

	if ( (bind(sock, (SOCKADDR*) &local_address, la_size)) == SOCKET_ERROR ) {
		printf("Error : Localhost not found\n");
		return 4;
	}


	int nb_clients = 0;

	printf("Listening on port %d ...\n",cp->port);
	listen( sock, 10 );

	int i;
	for (i=0; i<NB_MAX_CLIENTS; i++) {

		SOCKADDR_IN client_address;
		SOCKET sock_in = INVALID_SOCKET;
		socklen_t ca_size = sizeof(client_address);
	
		if ( (sock_in = accept(sock, (SOCKADDR*)&client_address, &ca_size)) == INVALID_SOCKET ) {

			printf("Accept error\n");
			return -1;

		}

		printf("Incoming connection with socket %d of %d:%d\n", sock_in, inet_ntoa(client_address.sin_addr), htons(client_address.sin_port));

		connector_and_sock_t cs = { cp->connector, sock_in };

		pthread_t thread;
		pthread_create( &thread, NULL, cp->callback, (void *)&cs );

	}

	return 0;


}


/* Initialise une connexion */
SOCKET connect_to_server( const char* server_name, int port ) {


	SOCKET sock = INVALID_SOCKET;
	sock = socket(AF_INET, SOCK_STREAM, 0);

	struct hostent* hostinfo = NULL;
	SOCKADDR_IN socket_in = { 0 };

	hostinfo = gethostbyname(server_name);


	printf("Connecting to %s:%d ...\n", server_name,port);

	if (hostinfo == NULL) {
		printf("%s : Unknown host\n", server_name);
		return INVALID_SOCKET;
	}

	socket_in.sin_addr = *(IN_ADDR*) hostinfo->h_addr;
	socket_in.sin_port = htons(port);
	socket_in.sin_family = AF_INET; /* IPv4 TCP */

	if ( connect(sock, (SOCKADDR*) &socket_in, sizeof(socket_in)) == SOCKET_ERROR ) {

		printf("Connection error ! \n");
		return INVALID_SOCKET;

	}

	printf("Connected !\n");

	// Do work with sock

	return sock;

	
}