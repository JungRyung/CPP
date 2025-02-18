// StreamServer_Add.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <WinSock2.h>

int main(int argc, char* argv[])
{
	WSADATA		wsaData;
	SOCKET		hListenSock, hSock;
	SOCKADDR_IN servAddr, clntAddr;
	int			nAddrLen = sizeof(clntAddr);
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
	if ((hListenSock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		std::cout << "socket() error !";
		exit(1);
	}

	/* 2 */
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(argv[1]));
	if (bind(hListenSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		std::cout << "bind() error !";
		exit(1);
	}

	if (listen(hListenSock, 5) == SOCKET_ERROR) {
		std::cout << "listen() error !";
		exit(1);
	}

	/* 3 */
	if ((hSock = accept(hListenSock, (SOCKADDR*)&clntAddr, &nAddrLen)) == INVALID_SOCKET ) {
		std::cout << "accept () error !  Error Code " << WSAGetLastError();
		exit(1);
	}

	/* Enter your code */

	/* 5 */
	closesocket(hSock);
	WSACleanup();

	return 0;
}