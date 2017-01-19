#include "CollabIGT_InputQueueManager.h"

InputQueueManager::InputQueueManager(){
    printTimer = new QTimer();
    //this->connect(printTimer, SIGNAL(timeout()), this, SLOT(print()));
    //printTimer->start(10);
}

int InputQueueManager::getLength(){
    mutex.lock();
    int ret = igtInputDataware.size();
    mutex.unlock();
    return ret;
}

int InputQueueManager::getDataArrayCountFromInputQueue(int index){
    mutex.lock();
    int ret = igtInputDataware.at(index)->getLength();
    mutex.unlock();
    return ret;
}

char* InputQueueManager::getDataArrayFromInputQueue(int index){
    mutex.lock();
    char * ret = igtInputDataware.at(index)->getLatestArray();
    mutex.unlock();
    return ret;
}

void  InputQueueManager::removeDataArrayFromInputQueue(int index){
    igtInputDataware.at(index)->deleteLatestArray();
}

void InputQueueManager::addIgtInputQueue(InputQueue* inputQueue){
    igtInputDataware.append(inputQueue);
}

void InputQueueManager::addDataArrayFromInputQueue(int index, char *receiveMessage){
    mutex.lock();
    if(index >= this->getLength() || receiveMessage == NULL){
        return;
    }
    this->igtInputDataware[index]->append(receiveMessage);
    mutex.unlock();
}

void InputQueueManager::print(){
    if(igtInputDataware.size()>0){
        //qDebug()<<"---------igtInputQueueManager---------";
        for(unsigned char cpt = 0; cpt < igtInputDataware.size(); cpt++){
            igtInputDataware.at(cpt)->print();
        }
        //qDebug()<<"_________igtInputQueueManager_________";
    }
}
