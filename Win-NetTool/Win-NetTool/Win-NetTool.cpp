// Win-NetTool.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NetToolController.h"

using namespace std;


int __cdecl main (void)
{
	int option,ret_val;
	cout << "Enter Option:" << endl;
	cin >> option;
	generic_network gen_net_access;

	switch (option)
	{
	case 1: 
		cout << "case1" << endl;
		ret_val = gen_net_access.generic_server();
	 break;

	case 2: 
		cout << "case2" << endl;
		break;
	case 3:
		cout << "case3" << endl;
		ret_val = gen_net_access.dns_lookup();
		break;
	default:
		cout << "default" << endl;
	 break;
	}

    return 0;
}

