#include "stdafx.h"

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include "NetToolController.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

using namespace std;
int generic_network::dns_lookup(void)
{
	WSADATA wsaData;
	int iResult;

	//Create Sockets
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;


	struct addrinfo *result = NULL;
	struct addrinfo hints;
	struct addrinfo *p;
	struct sockaddr_in *ip_access;

	char *hostname;
	char url_input[DEFAULT_BUFLEN];
	
	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;





	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	cout << "Enter URL" << endl;
	cin >> url_input;
	cout << url_input << endl;

	// Resolve the server address and port
	iResult = getaddrinfo("www.google.com", "80", &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	//loops through structure using ai_next
	for (p = result; p != NULL; p = p->ai_next)
	{
		//pass data into sockaddr_in struct
		ip_access = (struct sockaddr_in *) p->ai_addr;

		printf("IP address is %s: \n", inet_ntoa(ip_access->sin_addr));

	}

	freeaddrinfo(result);

	printf("\n");

}



#if 0

INPUT_RECORD record;
DWORD numRead;
if (!ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &record, 1, &numRead))


BOOL WINAPI ReadConsole(
	_In_     HANDLE  hConsoleInput,
	_Out_    LPVOID  lpBuffer,
	_In_     DWORD   nNumberOfCharsToRead,
	_Out_    LPDWORD lpNumberOfCharsRead,
	_In_opt_ LPVOID  pInputControl
);

HANDLE input_handle;
LPVOID output_buffer;
DWORD max_char;
LPDWORD char_read;



#endif