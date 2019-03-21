// DatagramClient_Echo.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <WinSock2.h>

#define	SND_BUF_SIZE	1000

int main(int argc, char* argv[])
{
	WSADATA		wsaData;
	SOCKET		hSock;
	SOCKADDR_IN servAddr;

	if (argc != 3) {
		std::cout << "Usage : " << argv[0] << " <IP> <port>" << std::endl;
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

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	servAddr.sin_port = htons(atoi(argv[2]));


	/* 2 */
	int nMsgSize, nSent, nReceived;
	for (int i = 1; i < 10000; i++)
	{
		char buffer[SND_BUF_SIZE + 1];

		std::cout << ">>";
		sprintf_s(buffer, "%04d-", i);
		std::cin.getline(buffer + 5, sizeof(buffer)-5);
		nMsgSize = strlen(buffer);

		if (nMsgSize == 5) break; // User just pressed "Enter"

		if ((nSent = sendto(hSock, buffer, nMsgSize, 0,
			(struct sockaddr*)&servAddr, sizeof(servAddr))) != SOCKET_ERROR)
		{
			if (nSent != nMsgSize)
				printf("Only %d bytes from %d bytes are sent \n", nSent, nMsgSize);

			int nLen = sizeof(servAddr);
			if ((nReceived = recvfrom(hSock, buffer, SND_BUF_SIZE, 0,
				(struct sockaddr*)&servAddr, &nLen)) != SOCKET_ERROR) {
				std::cout << "[Echo " << nReceived << "]  \"" << buffer << "\" \n";
			}
			else {
				std::cout << "[" << i << "] Socket Error - Code" << WSAGetLastError() << std::endl;
				break;
			}
		}
		else {
			std::cout << "[" << i << "] Socket Error - Code" << WSAGetLastError() << std::endl;
			break;
		}
	}

	/* 4 */
	std::cout << "Press Enter to Close the Socket" << std::endl;
	getchar();
	closesocket(hSock);

	WSACleanup();

	return 0;
}