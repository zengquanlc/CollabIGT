#include "CollabIGT_ReceptionTask.h"


/**
* @brief ReceptionTask::ReceptionTask
* @param recSoc
*/
#ifdef Q_OS_MACOS
    ReceptionTask::ReceptionTask(int recSoc){
        this->recSoc = recSoc;
        flag = true;
    }
#else
    ReceptionTask::ReceptionTask(SOCKET recSoc, InputQueueManager *inputQueueManager){
        this->recSoc = recSoc;
        this->inputQueueManager = inputQueueManager;
        flag = true;
    }
#endif

//! --------------------------------------------------------------------------
//!
//! \brief ReceptionTask::run
//!
void ReceptionTask::run(){
    while (flag) {

        char chunk[MAX_PACKET_SIZE+1];
        int nRecv = ::recv(this->recSoc, chunk, MAX_PACKET_SIZE+1, 0);

        if(nRecv > 0){
            qDebug()<<"message arrive";
            chunk[MAX_PACKET_SIZE] = '\0';
            //this->inputQueueManager->addDataArrayFromInputQueue(0, chunk);
        }
        else{
            qDebug()<<"no msg yet..";
        }

        msleep(200);
    }
}

//! --------------------------------------------------------------------------
//!
//! \brief ReceptionTask::stop
//!
void ReceptionTask::stop(){
    this->flag = false;
}
