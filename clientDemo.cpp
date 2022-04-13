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
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0); //AF_INET ipv4, SOCK_STREAM TCP
    if (listening == INVALID_SOCKET)
    {
        cerr << "Can't create a socket! Quiting" << endl;
    }

    //Bind the socket to an ip address and port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.S_un.S_addr = INADDR_ANY
        bind(listening, (sockaddr *)&hint, sizeof(hint));

    //tell winsock the socket is for listening
    listen(listening, SOMACOMM);

    //wait for a connection
    sockaddr_in client;
    int clienSize = sizeof(client);

    SOCKET clientSocket = accept(listening, (sockaddr *)&client, &clienSize);

    char host[NI_MAXHOST];    //client remote name
    char service[NI_MAXHOST]; //service(ie, port) the client is connect on

    ZeroMemory(host, NI_MAXHOST);
    ZeroMemory(service, NI_MAXHOST);

    if (getnameinfo((sockaddr *)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXHOST, 0) == 0)
    {
        cout << host << " connected on port" << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port" << ntohs(client.sin_port) << endl;
    }
    //close listening socket
    closesocket(listening);
    //while loop: accept and echo message back to client
    char buf[4096];
    while(true){
        ZeroMemory(buf, 4096);
        //wait for client to send data
        int byteReceived = recv(clientSocket, buf, 4096, 0);
        if(byteReceived == SOCKET_ERROR){
            cerr<<"Error in recv(). Quiting"<<endl;
            break;
        }
        if(byteReceived == 0){
            cout<<"Client disconnected"<<endl;
            break;
        }

        //Echo message back to client
        send(clientSocket, buf, byteReceived + 1, 0);
    }

    //close the socket
    closesocket(clientSocket);
    //shutdown cleanup winsock
    WSACleanup();
    return 0;
}