// Win-NetTool.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NetToolController.h"
#include <iostream>
using namespace std;


int __cdecl main (void)
{
	int option,ret_val;
	cout << "Generic Web Tool" << endl << endl;
	cout << "1: Generic Server" << endl;
	cout << "2: Generic Client" << endl;
	cout << "3: DNS Lookup" << endl;
	cout << "4: Pcap Devices" << endl;
	cout << endl;

	generic_network gen_net_access;
	pcap_network pcap_access;

	while (1) {

	cout << "Enter Option:" << endl;
	cin >> option;
	
	switch (option)
	{
	case 1: 
		cout << "1 : Generic Server" << endl;
		ret_val = gen_net_access.generic_server();
	 break;

	case 2: 
		cout << "2: Generic Client" << endl;
		break;
	case 3:
		cout << "3: DNS Lookup" << endl;
		ret_val = gen_net_access.dns_lookup();
		break;
	case 4:
		cout << "4: Pcap Devices" << endl;
		ret_val = pcap_access.list_device();
	
		break;

	default:
		cout << "default" << endl;
	 break;
	}
}


    return 0;
}

