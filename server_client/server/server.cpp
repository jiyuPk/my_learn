#include <winsock2.h>

#include <stdlib.h>

#include <stdio.h>

#include <iostream>

constexpr int port = 7798;

#pragma comment(lib, "ws2_32.lib")





int main(int argc, char* argv[])
{
	WSADATA data;
	SOCKET socket;
	SOCKADDR_IN server_address;

	char msg[] = "Test";

	if (int i = WSAStartup(MAKEWORD(2, 2), &data); i != 0) {
		std::cerr << i;
		return -1;
	}

	WSACleanup();
}

