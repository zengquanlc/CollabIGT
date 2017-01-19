#ifndef COLLABIGT_TCPSERVER_H
#define COLLABIGT_TCPSERVER_H

//! ---------------------------------------------------------------------------------
//! presentation de class
//!
//!https://www.codeproject.com/Articles/412511/Simple-client-server-network-using-Cplusplus-and-W
//!
//!
//!----------------------------------------------------------------------------------


#include <QtGlobal>
#include <QThread>
#include <QDebug>

#ifdef Q_OS_MACOS
    #include <stdio.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
#else
    #pragma comment(lib,"WS2_32")
    #include <WinSock2.h>
    #include <Windows.h>
    #include <ws2tcpip.h>
    #include <iostream>
    #include <stdio.h>
    #include <assert.h>

#endif

class TcpServer : public QThread{
    Q_OBJECT
public:
    void run();
    bool init();
    bool launchServer();

private:
#ifdef Q_OS_MACOS
    int socketServer;
#else
    SOCKET socketServer;
#endif
    bool flag;
    unsigned short port;

public:
    TcpServer(unsigned short port);

signals:
#ifdef Q_OS_MACOS
    void incomingConnection(int sClient);
#else
    void incomingConnection(SOCKET sClient);
#endif
};



#endif // COLLABIGT_TCPSERVER_H
