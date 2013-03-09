#ifndef SERVERCLIENT_H_
#define SERVERCLIENT_H_
#include <conio.h>		// For _getche();
#include <iostream>		// For file input and output
#include <thread>		// For threading support
#include <winsock2.h>	// To create a socket

using namespace std;

class ServerClient {
private:
	const char * toSend;		// The message to send to the server
	bool isRunning;				// Should we be connected to the server
	SOCKET serverSocket;		// The created socket to connect on
	WORD wVersionRequested;		// Used to check if WSAStartup succeeds
	WSADATA	wsaData;			// Used to check if WSAStartup succeeds
	SOCKADDR_IN target;			// Socket connection information
	int	errorCode;				// Error codes if WSAStartup fails
public:
	ServerClient();
	virtual ~ServerClient();
	void socketConnection(string);	// Connects on a socket to the server
};

#endif
