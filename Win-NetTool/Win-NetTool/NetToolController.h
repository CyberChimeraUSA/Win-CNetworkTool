#pragma once

#ifndef CONTROLLER__H_
#define CONTROLLER__H_

void dump(const unsigned char *data_buffer, const unsigned int length);

class generic_network {
  public:
	  int generic_server(void);
	  int generic_client(void);
	  int dns_lookup(void);
};
class pcap_network {
public:
	int list_device(void);
};

#endif