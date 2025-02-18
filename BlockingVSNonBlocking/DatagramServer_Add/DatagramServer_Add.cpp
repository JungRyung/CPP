// DatagramServer_Add.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <WinSock2.h>

int main(int argc, char* argv[])
{
	WSADATA		wsaData;
	SOCKET		hSock;
	SOCKADDR_IN servAddr;
	int			network_sum = 0;

	if (argc != 2) {
		std::cout << "Usage : " << argv[0] << " <port>" << std::endl;
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cout << "WSAStartup() error !";
		exit(1);
	}

	/* 1 */
	if ((hSock = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
		std::cout << "socket() error !";
		exit(1);
	}

	/* 2 */
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(argv[1]));
	if (bind(hSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		std::cout << "socket bind() error !";
		exit(1);
	}

	/* Enter your code */

	/* 5 */
	closesocket(hSock);
	WSACleanup();

	return 0;
}
