#ifndef COLLABIGT_TRANSMISSIONTASK_H
#define COLLABIGT_TRANSMISSIONTASK_H

//!-----------------------------------------------------------------------------------------------
//! refrence
//! https://www.codeproject.com/Articles/412511/Simple-client-server-network-using-Cplusplus-and-W
//!
//!
//!
//! ----------------------------------------------------------------------------------------------


/*
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main (int argc, const char * argv[])
{
    struct sockaddr_in server_addr;
    server_addr.sin_len = sizeof(struct sockaddr_in);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(11332);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(&(server_addr.sin_zero),8);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket error");
        return 1;
    }
    char recv_msg[1024];
    char reply_msg[1024];

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in))==0)     {
    //connect 成功之后，其实系统将你创建的socket绑定到一个系统分配的端口上，且其为全相关，包含服务器端的信息，可以用来和服务器端进行通信。
        while (1) {
            bzero(recv_msg, 1024);
            bzero(reply_msg, 1024);
            long byte_num = recv(server_socket,recv_msg,1024,0);
            recv_msg[byte_num] = '\0';
            printf("server said:%s\n",recv_msg);

            printf("reply:");
            scanf("%s",reply_msg);
            if (send(server_socket, reply_msg, 1024, 0) == -1) {
                perror("send error");
            }
        }

    }

    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
*/

#include <QtGlobal>

#ifdef Q_OS_MACOS
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
#else
    #pragma comment(lib,"WS2_32")
    #pragma comment (lib, "Ws2_32.lib")
    #pragma comment (lib, "Mswsock.lib")
    #pragma comment (lib, "AdvApi32.lib")
    #include <WinSock2.h>
    #include <Windows.h>
    #include <ws2tcpip.h>

#endif 

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <QThread>
#include <QString>
#include <QStringList>
#include <QTimer> 
#include <QDebug>
#include <QByteArray>
#include "CollabIGT_OutputQueueManager.h"
#include "CGlobal.h"


class TransmissionTask : public QThread{
    Q_OBJECT
private:
#ifdef Q_OS_MACOS
    int connectSocket;
#else
    SOCKET connectSocket;
#endif
    bool flag;
    const char* addr;
    OutputQueueManager *outputQueueManager;

public:
    void init();
    void connectToServer(QString ip, unsigned short port);
    void run();
    void stop();

public:
    TransmissionTask(OutputQueueManager *outputQueueManager);
};

#endif // COLLABIGT_TRANSMISSIONTASK_H
