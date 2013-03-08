#include "ServerClient.h"

// Define the server addresses used by the client
#define SERVER_PORT 12345		// The port that the server is going to connect through
#define BUF_SIZE 4096 			// Maximum block transfer size
#define IPAddress "127.0.0.1" 	// 127.0.01 directs to localhost.

ServerClient::ServerClient(){
	// When the client is called, the serverConnect loop must run
	serverConnect = true;
	// Initialize other variables
	wVersionRequested = MAKEWORD(1, 1);
	// Assign error code if WSAStartup fails
	errorCode = WSAStartup(wVersionRequested, &wsaData);
}

ServerClient::~ServerClient(){
	// TODO Auto-generated destructor stub
}

void ServerClient::socketConnection(){
	// While the client is needed, we stay connected to the server
	while(serverConnect){
		// If there was an error starting
		if(errorCode != 0){
			// Output an error message with the error code.
			cout << "WSAStartup error %ld" << static_cast<long>(WSAGetLastError()) << endl;
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
			cout << "Socket error %ld" << static_cast<long>(WSAGetLastError()) << endl;
			// Then cleanup and return to the outer thread
			WSACleanup();
			return;
		}
		// If there is a connection error to the socket
		if(connect(serverSocket, (SOCKADDR *)&target, sizeof(target)) == SOCKET_ERROR){
			// Output an error message and error code
			cout << "Connection error %ld" << static_cast<long>(WSAGetLastError()) << endl;
			// Then cleanup and return to the outer thread
			WSACleanup();
			return;
		}
		// Close the socket and clean up
		closesocket(serverSocket);
		WSACleanup();
	}
	return; // End the thread
}

void ServerClient::toServer(string message){
	// Create a char * from the input string
	toSend = message.c_str();
	// Pass it to the server
	send(serverSocket, toSend, 80, 0);
	// End the server connection
	serverConnect = false;
}
