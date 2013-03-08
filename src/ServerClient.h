#ifndef SERVERCLIENT_H_
#define SERVERCLIENT_H_
#include <iostream>		// For file input and output
#include <thread>		// For threading support
#include <winsock2.h>	// To create a socket

using namespace std;

class ServerClient {
private:
	const char * toSend;		// The message to send to the server
	bool serverConnect;			// Should we be connected to the server
	WORD wVersionRequested;		// Used to check if WSAStartup succeeds
	WSADATA	wsaData;			// Used to check if WSAStartup succeeds
	SOCKADDR_IN target;			// Socket connection information
	SOCKET serverSocket;		// The created socket to connect on
	int	errorCode;				// Error codes if WSAStartup fails
public:
	ServerClient();
	virtual ~ServerClient();
	void toServer(string);		// Send a message to the server
	void socketConnection();	// Connects on a socket to the server
};

#endif
