// StreamClient_Add.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <WinSock2.h>

int main(int argc, char* argv[])
{
	WSADATA		wsaData;
	SOCKET		hSock;
	SOCKADDR_IN servAddr;
	int i, n_values, rvalues[1000];
	int local_sum = 0, network_sum = 0;

	srand(time(NULL)); // use current time as seed for random generator

	if (argc != 3) {
		std::cout << "Usage : " << argv[0] << " <IP> <port>" << std::endl;
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cout << "WSAStartup() error !";
		exit(1);
	}

	/* 0 */
	std::cout << "Enter the number of Random Numbers to generate (<1000):";
	std::cin >> n_values;
	if (n_values <= 0 || n_values >= 1000)
		n_values = 1000;

	for (i = 0; i < n_values; i++) {
		rvalues[i] = rand();
		local_sum += rvalues[i];
	}

	/* 1 */
	if ((hSock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		std::cout << "socket() error !";
		exit(1);
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	servAddr.sin_port = htons(atoi(argv[2]));

	/* Enter your code */


	/* 4 */
	closesocket(hSock);
	WSACleanup();

	/* 5 */
	std::cout << "Sum of Random Values - Local : " << local_sum << ", Network : " << network_sum << std::endl;
	return 0;
}