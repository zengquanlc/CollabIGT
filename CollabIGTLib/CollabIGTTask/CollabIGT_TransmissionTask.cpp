#include "CollabIGT_TransmissionTask.h"


/**
 * @brief TransmissionTask::TransmissionTask
 * @param ip
 * @param port
 */
TransmissionTask::TransmissionTask(OutputQueueManager *outputQueueManager)
{
    flag = true;
    this->outputQueueManager = outputQueueManager;
    init();

//    QStringList ips = ip.split('.');
//    qDebug()<<ips;
//    addr[0] = char(ips.at(0).toInt(0,10));
//    addr[1] = char(ips.at(1).toInt(0,10));
//    addr[2] = char(ips.at(2).toInt(0,10));
//    addr[3] = char(ips.at(3).toInt(0,10));


    //! socket
    // connectSocket = INVALID_SOCKET;
}

//! ---------------------------------------------------------------------------------
//!
//! \brief TransmissionTask::connectToServer
//! \param ip
//! \param port
//!
void TransmissionTask::connectToServer(QString ip, unsigned short port){

    //! transform ip and port to char*
    QByteArray addr1 = ip.toLatin1();
    addr = addr1.data();
    QString temp = QString::number(port, 10);
    QByteArray temp1 = temp.toLatin1();
    const char *port_str = temp1.data();

#ifdef Q_OS_MACOS
    struct sockaddr_in server_addr;
    server_addr.sin_len = sizeof(struct sockaddr_in);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(this->ip.toLocal8Bit().data());
    bzero(&(server_addr.sin_zero),8);

    connectSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (connectSocket != -1) {
        qDebug()<<"before connect";
        ::connect(connectSocket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in));
        qDebug()<<"after connect";
    }

#else
    //! holds address info for socket to connect to
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;


    //! set address info
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;  //!TCP connection


    //! resolve server address and port
    int iResult;
    iResult = getaddrinfo((PCSTR)addr, (PCSTR)port_str, &hints, &result);
    //qDebug()<<"getaddrinfo iResult:"<<iResult;

    if(iResult != 0){
        printf("getaddrinfo failed with error: %d\n", iResult);
        exit(1);
    }

    //! Attempt to connect to an address until one succeeds
    for(ptr = result; ptr != NULL; ptr = ptr->ai_next){


        //! Create a SOCKET for connecting to server
        connectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

        if(INVALID_SOCKET == connectSocket){
            printf("socket failed with error: %d\n", WSAGetLastError());
            WSACleanup();
            exit(1);
        }


        //! Connect to server
        iResult = ::connect(connectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        //qDebug()<<"connect iResult:"<<iResult;

        if(iResult == SOCKET_ERROR){
            closesocket(connectSocket);
            connectSocket = INVALID_SOCKET;
            printf("The server is down... did not connect\n");
        }
    }


    //! no longer need address info for server
    freeaddrinfo(result);


    //! if connection failed
    if(connectSocket == INVALID_SOCKET){
        printf("Unable to connect to server!\n");
        WSACleanup();
        exit(1);
    }


//    //! Set the mode of the scoket to be nonblocking
//    u_long iMode = 1;

//    iResult = ioctlsocket(connectSocket, FIONBIO, &iMode);
//    if(iResult == SOCKET_ERROR){
//        printf("ioctlsocket failed with error: %d\n",WSAGetLastError());
//        closesocket(connectSocket);
//        WSACleanup();
//        exit(1);
//    }

//    //! disable nagle
//    char value = 1;
//    setsockopt(connectSocket, IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));

    this->start();
#endif

}


void TransmissionTask::run(){
    while(this->flag){
        if(this->outputQueueManager->getOutputQueueManagerLength() ==0 ||this->outputQueueManager->getLatestMessageLengthByOutputQueueIndex(0) ==0){
           continue;
        }
        qDebug()<<"transmit: "<<this->outputQueueManager->getLatestMessageLengthByOutputQueueIndex(0);
        int iResult =::send(this->connectSocket, this->outputQueueManager->getLatestMessageByOutputQueueIndex(0), MAX_PACKET_SIZE+1, 0);
        this->outputQueueManager->deleteLatestMessageByOutputQueueIndex(0);
        msleep(200);

    }
}

void TransmissionTask::stop(){
    this->flag = false;
}

void TransmissionTask::init(){
#ifdef Q_OS_MACOS

#else
    //! create WSADATA object
    WSADATA wsaData;


    //! Initialize Winsock
    int iResult;
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);


    if(iResult != 0){
        printf("WSAStartup failed with error: %d\n", iResult);
        exit(1);
    }
#endif
}

