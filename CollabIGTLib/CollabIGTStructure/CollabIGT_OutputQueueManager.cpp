#include "CollabIGT_OutputQueueManager.h"


OutputQueueManager::OutputQueueManager(QObject *parent) : QObject(parent)
{
    this->outputQueueManagerLength = 0;
}

void OutputQueueManager::addIgtOutputQueue(OutputQueue* outPutQueue){
    mutex.lock();
    if(outPutQueue == NULL){
        return;
    }
    outputQueueManager.append(outPutQueue);
    this->outputQueueManagerLength++;
    mutex.unlock();
}

void OutputQueueManager::setMessageToSendByTargetId(int ret, QList<const char *> *sendMessage){
    mutex.lock();
    if(sendMessage == NULL || this->outputQueueManagerLength <=0 || ret >= this->outputQueueManagerLength){
        return;
    }
    outputQueueManager[ret]->append(sendMessage);
    mutex.unlock();
}

const char* OutputQueueManager::getLatestMessageByOutputQueueIndex(int index){
    mutex.lock();
    const char* ret = this->outputQueueManager[index]->getLatestMessage();
    mutex.unlock();
    return ret;
}

void OutputQueueManager::deleteLatestMessageByOutputQueueIndex(int index){
    mutex.lock();
    if(index >= this->outputQueueManagerLength){
        return;
    }
    this->outputQueueManager[index]->deleteLatestFrame();
    mutex.unlock();
}

int OutputQueueManager::getLatestMessageLengthByOutputQueueIndex(int index){

    mutex.lock();
    if(index >= this->outputQueueManagerLength){
        return -1;
    }
    int ret;
    ret = outputQueueManager[index]->getOutputQueueLength();
    mutex.unlock();
    return ret;
}

int OutputQueueManager::getOutputQueueManagerLength(){
    int ret ;
    mutex.lock();
    ret = this->outputQueueManagerLength;
    mutex.unlock();
    return ret;
}
