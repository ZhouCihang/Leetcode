#include <iostream>
#include <WinSock2.h>
#include <windows.h>
#pragma comment(lib, "WS2_32.lib")
using namespace std;

int main()
{
    WSADATA wsaData;
    WORD wsaVersion = MAKEWORD(2, 2);
    WSAStartup(wsaVersion, &wsaData);

    SOCKET serverSock = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9999);
    
    connect(serverSock, (sockaddr *)&addr, sizeof(addr));

    char buf[] = "hello Server!";
    char recvBuf[512] = {0};
    int i = send(serverSock, buf, strlen(buf), 0);
    int recvLen = recv(serverSock, recvBuf, sizeof(recvBuf),0);
    cout<<recvBuf<< endl;
    getchar();

    closesocket(serverSock);
    WSACleanup();
    return 0;
}