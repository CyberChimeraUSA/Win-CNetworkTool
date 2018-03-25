#pragma once

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class generic_network {
  public:
	  int generic_server(void);
	  int generic_client(void);
	  int dns_lookup(void);
};