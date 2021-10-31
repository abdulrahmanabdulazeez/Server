/*Simple live server code::*/
#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib");

using namespace std;

void head(){
    cout << "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
    cout << "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
    cout << "'''''''''''''''''''''''''LIVE SERVER''''''''''''''''''''''''''''''\n";
    cout << "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
    cout << "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
}

int main(){
    head();
    system("color a");
    WSADATA wdat;
    SOCKET soc, nsock;
    struct sockaddr_in server, client;
    char *message;
    char *c_IP;
    char client_reply[50000];
    int rec_sze;
    int a;

    c_IP=inet_ntoa(client.sin_addr);

    cout << "[*]Initializing WinSock......\n";
        if(WSAStartup(MAKEWORD(2,2),&wdat)!=0){
            cerr << "[!]Failed to initialize winsock!!! Error code: " << WSAGetLastError() << endl;
            cout << "\n";
            system("pause");
            return 0;
        }
    cout << "[*]WinSock initialization successful!!!\n\n";
    cout << "[*]Creating a socket.......\n";
        if((soc=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==INVALID_SOCKET){
            cerr << "[!]Socket creation unsuccessful!!! Error code: " << WSAGetLastError() << endl;
            cout << "\n";
            system("pause");
            return 0;
        }
    cout << "[*]Socket creation successful!!!\n\n";

    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_family=AF_INET;
    server.sin_port=htons(80);

    cout << "[*]Binding Socket.........\n";
        if(bind(soc, (struct sockaddr *)&server, sizeof(server))==SOCKET_ERROR){
            cerr << "[!]Failed to bind socket!!! Error code: " << WSAGetLastError() << endl;
            cout << "\n";
            system("pause");
            return 0;
        }
    cout << "[*]Socket binded successfully!!!\n\n";
    listen(soc, 3);
    cout << "[*]Listening for any available connection(s).....\n";

    a=sizeof(struct sockaddr_in);
    while (nsock=accept(soc, (struct sockaddr*)&client, &a)){
        if(nsock==INVALID_SOCKET){
            cerr << "[!]Failed to accept connection(s)!!! Error code: " << WSAGetLastError() << endl;
            cout << "\n";
            system("pause");
            return 0;
        }

    cout << "[*]Connection found!!!\n";
    cout << "[|]connection's IP Address: " << c_IP << endl;
    cout << "[*]Connection accepted!!!\n\n";
    cout << "[*]Sending data......\n";
    message="\nNo problem client, what are we friends for.!!\n\n";
        if(send(nsock, message, strlen(message),0)<0){
            cerr << "[!]Failed to send message!!! Error code: " << WSAGetLastError() << endl;
            cout << "\n";
            system("pause");
            return 0;
        }
    cout << "[*]Data sent!!!\n\n";

    cout << "[*]Receiving Reply.......\n";
        if((rec_sze=recv(nsock, client_reply, 50000, 0))==SOCKET_ERROR){
            cerr << "[!]Error receiving reply!!! Error code: " << WSAGetLastError() << endl;
            cout << "\n";
            system("pause");
            return 0;
        }

    cout << "[*]Data Received!!!\n\n";
    client_reply[rec_sze];
    cout << "[Data Received from client (" << c_IP << ")]:" << client_reply;
    cout << "\n\n";

    cout << "[*]Listening for any available connection(s).....\n";
    }
    system("pause");
    closesocket;
    WSACleanup();

return 0;
}


