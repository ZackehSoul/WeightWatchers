#include <conio.h>
#include <fstream>		// Needed for the file stream
#include <iostream>		// Needed for input and output
#include <winsock2.h>	// Needed for socket connection

using namespace std;

#define SERVER_PORT 12345	// Server port to connect on
#define BUF_SIZE 4096  		// Block transfer size
#define QUEUE_SIZE 10		// Queue size to accept

int main(int argc, char * argv[]){

	cout << "The server has been started." << endl;

	// Create integers for the required codes
	int	bindCode, listenCode, on = 1;
	// Empty char for the received message
	char inputMessage[80] = { };
	// Create socket objects
	SOCKET socketA, socketB;
	// Hold the channel IP address in a structure
	struct sockaddr_in channel;
	// Initialize variables to generate error code
	WORD wVersionRequested = MAKEWORD(1, 1);
	WSADATA wsaData;
	// Calculate if WSAStartup was successful
	int	errorCode = WSAStartup(wVersionRequested, &wsaData);
	// The number of bytes received
	int	bytesReceived;

	if(errorCode != 0){
		// If WSA fails to start up, print an error
		cout << "WSAStarup error: " << static_cast<long>(WSAGetLastError()) << endl;
		WSACleanup();
		return false;
	}

	// Create the address structure to be bound to the socket using channel zero
	memset(&channel, 0, sizeof(channel));
	// Set address family Internet
	channel.sin_family = AF_INET;
	// Uses SERVER_PORT defined earlier to connect on
	channel.sin_addr.s_addr = htonl(INADDR_ANY);
	channel.sin_port = htons(SERVER_PORT);

	// Create a new socket
	socketA = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(socketA < 0){
		// If there's a socket error, display the error
		cout << "Socket error: " << static_cast<long>(WSAGetLastError()) << endl;
		// Then cleanup and return to the outer thread
		WSACleanup();
		return false;
	}
	// Finish socket creation
	setsockopt(socketA, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof(on));

	// Bind the new socket
	bindCode = bind(socketA, (struct sockaddr *) &channel, sizeof(channel));
	if(bindCode < 0){
		// If there's a binding error, display the error
		cout << "Binding error: " << static_cast<long>(WSAGetLastError()) << endl;
		// Then cleanup and return to the outer thread
		WSACleanup();
		return false;
	}

	// Listen on the socket
	listenCode = listen(socketA, QUEUE_SIZE); // Set the queue size
	if (listenCode < 0) {
		// If there's a listening error, display the error
		cout << "Listening error: " << static_cast<long>(WSAGetLastError()) << endl;
		// Then cleanup and return to the outer thread
		WSACleanup();
		return false;
	}

	// Create a new output stream to contain the received messages
	ofstream simLog;
	// The file is named after the when the server was started
	simLog.open("simulation-log.txt", ios_base::trunc);

	// Await inputs whilst the server stays running
	while(true) {
		// Block for the connection request
		socketB = accept(socketA, 0, 0);
		if(socketB < 0){
			// If there is a socket error output the error
			cout << "Accept error: " << static_cast<long>(WSAGetLastError()) << endl;
			// Then cleanup and return to the outer thread
			WSACleanup();
			return false;
		}

		// Receive the message
		bytesReceived = recv(socketB, inputMessage, 80, 0);
		// Check for any errors
		errorCode = WSAGetLastError();
		if(bytesReceived == 0 || bytesReceived == WSAECONNRESET){
			// If no bytes are received the connection is closed
			cout << "The connection has been closed" << endl;
			// Then cleanup and return to the outer thread
			WSACleanup();
		}
		// Output the received message to the server window
		cout << inputMessage;
		// Write the received message to the output file
		simLog << inputMessage;
		// Close socketB
		closesocket(socketB);
	}
	// Close the output stream
	simLog.close();
	// Close socketA
	closesocket(socketA);
	// Then cleanup and close the method
	WSACleanup();
	return 0;
}
