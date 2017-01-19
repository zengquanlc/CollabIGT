#ifndef COLLABIGT_RECEPTIONTASK_H
#define COLLABIGT_RECEPTIONTASK_H


#include <QtGlobal>
#include <QThread>
#include <QDebug>
#include "CGlobal.h"
#include "CollabIGT_InputQueueManager.h"

#ifdef Q_OS_MACOS
    #include <stdio.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
#else
    #pragma comment(lib,"WS2_32")
    #include <WinSock2.h>
#endif




class ReceptionTask : public QThread
{

public:
    void run();

private:
#ifdef Q_OS_MACOS
    int recSoc;
#else
    SOCKET recSoc;
#endif

    bool flag;
    InputQueueManager *inputQueueManager;

public:
#ifdef Q_OS_MACOS
    ReceptionTask(int recSoc);
#else
    ReceptionTask(SOCKET recSoc, InputQueueManager *inputQueueManager);
#endif
    void stop();

};

#endif // COLLABIGT_RECEPTIONTASK_H
