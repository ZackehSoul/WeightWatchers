#include "ServerClient.h"

// Define the server addresses used by the client
#define SERVER_PORT 12345		// The port that the server is going to connect through
#define BUF_SIZE 4096 			// Maximum block transfer size
#define IPAddress "127.0.0.1" 	// 127.0.01 directs to localhost.

ServerClient::ServerClient(){
	isRunning = true;
}

ServerClient::~ServerClient(){
	isRunning = false;
}

/**
 * Sends a message to the server, after being called by toServer. Currently has a whitespace
 * bug when sending the message which I need to fix, but the server connection is fine.
 *
 * @param message the message to be sent
 */
void ServerClient::socketConnection(string message){

	toSend = message.c_str();	// Converts input string to const char *

	// Initialize other variables
	wVersionRequested = MAKEWORD(1, 1);
	// Assign error code if WSAStartup fails
	errorCode = WSAStartup(wVersionRequested, &wsaData);
	// If there was an error starting
	if(errorCode != 0){
		// Output an error message with the error code.
		cout << "WSAStartup error: " << static_cast<long>(WSAGetLastError()) << endl;
		// Then cleanup and return to the outer thread
		WSACleanup();
		return;
	}
	// Create the address structure to be bound to the socket
	target.sin_family = AF_INET;
	// Uses SERVER_PORT defined earlier to connect on
	target.sin_port = htons(SERVER_PORT);
	// Sets the target IP, again defined earlier in IPAddress
	target.sin_addr.s_addr = inet_addr (IPAddress);

	// Create a new socket
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// If the socket is invalid throw an error
	if(serverSocket == INVALID_SOCKET){
		// Output an error message
		cout << "Socket error: " << static_cast<long>(WSAGetLastError()) << endl;
		// Then cleanup and return to the outer thread
		WSACleanup();
		return;
	}
	// If there is a connection error to the socket
	if(connect(serverSocket, (SOCKADDR *)&target, sizeof(target)) == SOCKET_ERROR){
		// Output an error message and error code
		cout << "Connection error: " << static_cast<long>(WSAGetLastError()) << endl;
		// Then cleanup and return to the outer thread
		WSACleanup();
		return;
	}
	send(serverSocket, toSend, 80, 0);
	// Close the socket and clean up
	closesocket(serverSocket);
	WSACleanup();

	return; // End the thread
}
