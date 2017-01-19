#ifndef COLLABIGT_COMMUNICATIONSTACK_H
#define COLLABIGT_COMMUNICATIONSTACK_H

#include <QObject>
#include "igtDataware.h"

#ifdef Q_OS_MACOS

#else
    #include <WinSock2.h>
#endif


#include <CollabIGT_TcpServer.h>
#include "CollabIGT_ReceptionTask.h"
#include "CollabIGT_TransmissionTask.h"
#include "CollabIGT_EncodingTask.h"
#include "AddToDatawareTask.h"
#include "CollabIGT_InputQueueManager.h"

class CommunicationStack : public QObject{
    Q_OBJECT

public:
    void launch();
    void connectera(QString ip, int port);

private:
    TcpServer *serv;
    igtDataware *dataware;
    OutputQueueManager *outputQueueManager;
    InputQueueManager *inputQueueManager;

public:
    explicit CommunicationStack(igtDataware *dataware);

signals:

public slots:
#ifdef Q_OS_MACOS
    void newClient(int sClient);
#else
    void newClient(SOCKET sClient);
#endif
};

#endif // COLLABIGT_COMMUNICATIONSTACK_H
