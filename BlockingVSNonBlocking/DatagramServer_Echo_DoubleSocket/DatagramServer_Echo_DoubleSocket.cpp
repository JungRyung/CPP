// DatagramServer_Echo_DoubleSocket.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <WinSock2.h>

#define	RCV_BUF_SIZE	2000
#define	NON_BLOCKING_IO		
inline int HandleSocketError(int bPrintBlockError);

int main(int argc, char* argv[])
{
	WSADATA		wsaData;
	SOCKET		hSock1, hSock2;
	SOCKADDR_IN servAddr, clntAddr;
	char		buffer[RCV_BUF_SIZE + 1];

	if (argc != 2) {
		std::cout << "Usage : " << argv[0] << " <port>" << std::endl;
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cout << "WSAStartup() error !";
		exit(1);
	}
	
	/* 1 */
	hSock1 = socket(AF_INET, SOCK_DGRAM, 0);
	hSock2 = socket(AF_INET, SOCK_DGRAM, 0);

	if (hSock1 == INVALID_SOCKET || hSock2 == INVALID_SOCKET) {
		std::cout << "socket() error !";
		exit(1);
	}

	/* 2 */
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(argv[1]));
	if (bind(hSock1, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		std::cout << "socket 1 bind() error !";
		exit(1);
	}
	servAddr.sin_port = htons(atoi(argv[1]) + 1);
	if (bind(hSock2, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		std::cout << "socket2 bind() error !";
		exit(1);
	}

	/* 3 */
#ifdef NON_BLOCKING_IO
	ULONG bNBIO = 1;
	if (ioctlsocket(hSock1, FIONBIO, &bNBIO) == SOCKET_ERROR)
		std::cout << "Could not change the I/O Mode of the 1st Socket" << std::endl; 
	if (ioctlsocket(hSock2, FIONBIO, &bNBIO) == SOCKET_ERROR)
		std::cout << "Could not change the I/O Mode of the 2nd Socket" << std::endl;
#endif

	/* 4 */
	int nSent, nReceived, nAddrLen = sizeof(clntAddr), nErrorCode;
	do
	{
		if ((nReceived = recvfrom(hSock1, buffer, RCV_BUF_SIZE, 0, (struct sockaddr *)&clntAddr, &nAddrLen)) != SOCKET_ERROR)
		{
			if ((nSent = sendto(hSock1, buffer, nReceived, 0, (struct sockaddr *)&clntAddr, nAddrLen)) != SOCKET_ERROR)
			{
				buffer[nSent] = 0;
				std::cout << "[Echo " << inet_ntoa(clntAddr.sin_addr) << ":" << ntohs(clntAddr.sin_port);
				std::cout << ",Size " << nSent << "]-\"" << buffer << "\"" << std::endl;
			}
			else
			{
				nErrorCode = HandleSocketError(0);
			}
		}
		else
		{
			nErrorCode = HandleSocketError(0);
		}

		if ((nReceived = recvfrom(hSock2, buffer, RCV_BUF_SIZE, 0, (struct sockaddr *)&clntAddr, &nAddrLen)) != SOCKET_ERROR)
		{
			if ((nSent = sendto(hSock2, buffer, nReceived, 0, (struct sockaddr *)&clntAddr, nAddrLen)) != SOCKET_ERROR)
			{
				buffer[nSent] = 0;
				std::cout << "[Echo " << inet_ntoa(clntAddr.sin_addr) << ":" << ntohs(clntAddr.sin_port);
				std::cout << ",Size " << nSent << "]-\"" << buffer << "\"" << std::endl;
			}
			else
			{
				nErrorCode = HandleSocketError(0);
			}
		}
		else
		{
			nErrorCode = HandleSocketError(0);
		}

	} while (nReceived > 0 || nErrorCode == WSAEWOULDBLOCK);

	/* 5 */
	closesocket(hSock1);
	closesocket(hSock2);

	WSACleanup();
	return 0;
}


inline int HandleSocketError(int bPrintBlockError)
{
	int nErrorCode = WSAGetLastError();

	if (bPrintBlockError || nErrorCode != WSAEWOULDBLOCK)
		std::cout << "[Error] " << nErrorCode << std::endl;

	return nErrorCode;
}