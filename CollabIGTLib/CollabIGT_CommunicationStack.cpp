#include "CollabIGT_CommunicationStack.h"


/**
 * @brief CommunicationStack::CommunicationStack
 * @param parent
 */
CommunicationStack::CommunicationStack(igtDataware *dataware){

    //! to access system dataware
    this->dataware = dataware;

    this->outputQueueManager = new OutputQueueManager();
    this->inputQueueManager = new InputQueueManager();

    EncodingTask *encodingTask = new EncodingTask(this->dataware, this->outputQueueManager);
    encodingTask->start();

    //! tcp server
    unsigned short port=10703;
    serv = new TcpServer(port);



#ifdef Q_OS_MACOS
    this->connect(serv, SIGNAL(incomingConnection(int)), this, SLOT(newClient(int)));
#else
    qRegisterMetaType<SOCKET>("SOCKET");
    this->connect(serv, SIGNAL(incomingConnection(SOCKET)), this, SLOT(newClient(SOCKET)));
#endif
}

//! -------------------------------------------------------------------------------------------
//!
//! \brief CommunicationStack::launch
//!
void CommunicationStack::launch(){
    serv->launchServer();
}

//! --------------------------------------------------------------------------------------------
//!
//! \brief CommunicationStack::newClient
//! \param sClient
//!
#ifdef Q_OS_MACOS
    void CommunicationStack::newClient(int sClient){
        qDebug()<<"incomming connection"<<sClient;
        igtInputQueue *inputQueue = new igtInputQueue();
        this->inputQueueManager->addIgtInputQueue(inputQueue);
        ReceptionTask *receptionTask = new ReceptionTask(sClient);
        receptionTask->start();
        return;
    }
#else
    void CommunicationStack::newClient(SOCKET sClient){
        qDebug()<<"launch a new reception task";
        InputQueue *inputQueue = new InputQueue();
        this->inputQueueManager->addIgtInputQueue(inputQueue);
        ReceptionTask *receptionTask = new ReceptionTask(sClient, this->inputQueueManager);
        receptionTask->start();
        return;
    }
#endif

//! ----------------------------------------------------------------------------------------------
//!
//! \brief CommunicationStack::connectera
//! \param ip
//! \param port
//!
void CommunicationStack::connectera(QString ip, int port){

    OutputQueue *outputQueue = new OutputQueue();
    this->outputQueueManager->addIgtOutputQueue(outputQueue);

     TransmissionTask *transmissionTask = new TransmissionTask(this->outputQueueManager);
     transmissionTask->connectToServer(ip, port);
}
