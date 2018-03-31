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
#include <pcap.h>
// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")


int pcap_network::list_device(void) {

	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_if_t *interfaces, *temp;
	int i = 0;

	if (pcap_findalldevs(&interfaces, errbuf) == -1)
	{
		perror("Error: Can't Find Devices \n");
		return -1;
	}

	printf("Current Interfaces \n");

	for (temp = interfaces; temp; temp = temp->next)
	{
		printf("Device %d  :  %s \n", i++, temp->name);
	}

	return 0;
	//pcap_close(pcap_handle);
}

