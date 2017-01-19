#include "CollabIGT_TcpServer.h"


/**
 * @brief TcpServer::TcpServer
 * @param port
 */
TcpServer::TcpServer(unsigned short port){
    flag = true;
    this->port = port;
    init();
}

//! ------------------------------------------------------------------------------
//!
//! \brief TcpServer::init
//!
bool TcpServer::init(){

#ifdef Q_OS_MACOS
    struct sockaddr_in server_addr;
    server_addr.sin_len = sizeof(struct sockaddr_in);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(&(server_addr.sin_zero),8);

    socketServer = socket(AF_INET, SOCK_STREAM, 0);
    if (socketServer == -1) {
        return false;
    }

    int bind_result = bind(socketServer, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bind_result == -1) {
        return false;
    }

    if (listen(socketServer, 5) == -1) {
        return false;
    }
#else
    qDebug()<<"init socket in windows";
    socketServer = INVALID_SOCKET;
    
    //!create WSADATA
    WSADATA wsaData;
    
    //! address info for the server to listen to
    struct addrinfo *result = NULL;
    struct addrinfo hints;
    
    //! initialize Winsock
    int iResult;
    iResult = WSAStartup(MAKEWORD(2, 2), (LPWSADATA)&wsaData);

    if(iResult != 0){
        printf("WSAStartup failed with error: %d\n", iResult);
        exit(1);
    }
    
    //! set address information
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;//!Tcp connection
    hints.ai_flags = AI_PASSIVE;
    
    //! Resolve the server address and port
    QString temp = QString::number(this->port, 10);
    QByteArray temp1 = temp.toLatin1();
    const char *port_str = temp1.data();

    qDebug()<<"port:"<<port_str;
    iResult = getaddrinfo(NULL, port_str, &hints, &result);


    qDebug()<<"getaddrinfo";
    qDebug()<<"iResult:"<<iResult;

    if(iResult != 0){
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        exit(1);
    }
    

    //!Create a　SOCKET for connecting to server
    socketServer = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if( SOCKET_ERROR == socketServer){
        printf("socket failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        exit(1);
    }

    qDebug()<<"Create a　SOCKET";

    //!set the mode of the socket to be nonblocking
    /*u_long iMode =1;

    iResult = ioctlsocket(socketServer, FIONBIO, &iMode);
    if(iResult == SOCKET_ERROR){
        printf("ioctlsocket failed with error: %d\n",WSAGetLastError());
        closesocket(socketServer);
        WSACleanup();
        exit(1);
    }*/
    
    //! bind
    if(SOCKET_ERROR == bind(socketServer, result->ai_addr, (int)result->ai_addrlen)){
        printf("Bind error\n");
        freeaddrinfo(result);
        closesocket(socketServer);
        WSACleanup();
        exit(1);
    }

    //!no longer need address information
    freeaddrinfo(result);

    //! listen
    if(SOCKET_ERROR == listen(socketServer, 4)){
        printf("Listen error\n");
        closesocket(socketServer);
        WSACleanup();
        exit(1);
    }

#endif
    return true;
}

//! ----------------------------------------------------------------------------
//!
//! \brief TcpServer::launchServer
//! \return
//!
bool TcpServer::launchServer(){
    this->start();
    return true;
}

//! ----------------------------------------------------------------------------
//!
//! \brief TcpServer::run
//!
void TcpServer::run(){
    while(flag){

#ifdef Q_OS_MACOS
        struct sockaddr_in client_address;
        socklen_t address_len;
        qDebug()<<"waiting for new client";
        int sClient = accept(socketServer, (struct sockaddr *)&client_address, &address_len);
        qDebug()<<"new client arrived";

        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 100;
        setsockopt(sClient, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

        emit incomingConnection(sClient);
#else
        sleep(1);
        SOCKET sClient;
        if(INVALID_SOCKET == (sClient = ::accept(socketServer, NULL, NULL))){
            qDebug()<<"invalid socket arriving";
            continue;
        }
        qDebug()<<"new client arrived";

        //! disable nagle
        char value = 1;
        setsockopt(sClient, IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));

        //! Set the mode of the scoket to be nonblocking
        u_long iMode = 1;
        int iResult = ioctlsocket(sClient, FIONBIO, &iMode);
        if(iResult == SOCKET_ERROR){
            printf("ioctlsocket failed with error: %d\n",WSAGetLastError());
            closesocket(sClient);
            WSACleanup();
            //exit(1);
        }
        emit incomingConnection(sClient);
#endif
    }

}





















