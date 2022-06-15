#include <iostream>
using namespace std;
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <netdb.h>
// #include <unistd.h>
// #include <errno.h>

int main()
{
    //Initialiez winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2); //define version 2.2

    int wsOK = WSAStartup(ver, &wsData);
    if (wsOK != 0)
    {
        cerr << "WSAStartup() failed, can't initialize winsock! Quitting" << endl;
        return -1;
    }

    //create a socket
    SOCKET serverSock = socket(AF_INET, SOCK_STREAM, 0); //AF_INET ipv4, SOCK_STREAM TCP
    if (serverSock == INVALID_SOCKET)
    {
        cerr << "Can't create a socket! Quiting" << endl;
    }

    //Bind the socket to an ip address and port
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(54000);
    addr.sin_addr.S_un.S_addr = INADDR_ANY;
    bind(serverSock, (sockaddr *)&addr, sizeof(addr));

    //tell winsock the socket is for listening
    listen(serverSock, SOMACOMM);
    cout << "tcp server is listening at port 9999:" << endl;

    SOCKET clientSock;
    sockaddr_in clientaddr;
    int len = sizeof(clientaddr);

    char buf[] = "hello Server!";
    char recvBuf[512] = {0};
    while (true)
    {
        clientSock = accept(serverSock, (sockaddr *)&clientaddr, &len);
        if (clientSock == INVALID_SOCKET)
        {
            cout << "client:" << inet_ntoa(clientaddr.sin_addr) << clientaddr.sin_port << " is connected." << endl;
            int i = send(clientSock, buf, strlen(buf), 0);
            int recvLen = recv(clientSock, recvBuf, sizeof(recvBuf), 0);
            cout << recvBuf << endl;
            closesocket(clientSock);
        }
    }

    //close the socket
    closesocket(serverSock);
    //shutdown cleanup winsock
    WSACleanup();
    return 0;
}
