#include "CollabIGT_OutputQueue.h"

OutputQueue::OutputQueue()
{

}
void OutputQueue::append(QList<const char*> *sendMessage){
    this->outputQueue.append(*sendMessage);
    return;
}

const char* OutputQueue::getLatestMessage(){
    mutex.lock();
    const char* ret = this->outputQueue[0];
    mutex.unlock();
    return ret;
}


//! delete latest frame : this->outputQueue.removeAt(0

void OutputQueue::deleteLatestFrame(){
    this->outputQueue.removeAt(0);

}

int OutputQueue::getOutputQueueLength(){
    int ret;
    mutex.lock();
    ret = this->outputQueue.size();
    mutex.unlock();
    return ret;
}
