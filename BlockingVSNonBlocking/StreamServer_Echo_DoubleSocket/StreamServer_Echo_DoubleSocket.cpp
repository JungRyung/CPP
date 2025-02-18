// StreamServer_Echo_DoubleSocket.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <WinSock2.h>

#define	RCV_BUF_SIZE	2000

//#define	NON_BLOCKING_IO		
inline int HandleSocketError(int bPrintBlockError);

int main(int argc, char* argv[])
{
	WSADATA		wsaData;
	SOCKET		hListenSock, hSock1, hSock2;
	SOCKADDR_IN servAddr, clntAddr1, clntAddr2;
	int			nAddrLen = sizeof(clntAddr1);
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
	hSock1 = accept(hListenSock, (SOCKADDR*)&clntAddr1, &nAddrLen);
	hSock2 = accept(hListenSock, (SOCKADDR*)&clntAddr2, &nAddrLen);

	if (hSock1 == INVALID_SOCKET || hSock2 == INVALID_SOCKET) {
		std::cout << "accept () error !  Error Code " << WSAGetLastError();
		exit(1);
	}


	/* 4 */
#ifdef NON_BLOCKING_IO
	ULONG bNBIO = 1;
	if (ioctlsocket(hSock1, FIONBIO, &bNBIO) == SOCKET_ERROR)
		std::cout << "Could not change the I/O Mode of the 1st Socket" << std::endl;
	if (ioctlsocket(hSock2, FIONBIO, &bNBIO) == SOCKET_ERROR)
		std::cout << "Could not change the I/O Mode of the 2nd Socket" << std::endl;
#endif

	/* 5 */
	int nSent, nReceived, nErrorCode;
	do
	{
		if ((nReceived = recv(hSock1, buffer, RCV_BUF_SIZE, 0)) != SOCKET_ERROR)
		{
			if ((nSent = send(hSock1, buffer, nReceived, 0)) != SOCKET_ERROR)
			{
				buffer[nSent] = 0;
				std::cout << "[Echo " << inet_ntoa(clntAddr1.sin_addr) << ":" << ntohs(clntAddr1.sin_port);
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

		if ((nReceived = recv(hSock2, buffer, RCV_BUF_SIZE, 0)) != SOCKET_ERROR)
		{
			if ((nSent = send(hSock2, buffer, nReceived, 0)) != SOCKET_ERROR)
			{
				buffer[nSent] = 0;
				std::cout << "[Echo " << inet_ntoa(clntAddr2.sin_addr) << ":" << ntohs(clntAddr2.sin_port);
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
