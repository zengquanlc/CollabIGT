#include "CollabIGT_Datagram.h"

Datagram::Datagram()
{
    datagram_head_size = 10;
}

int Datagram::getDataType(){
    int ret = this->dataType;
    return ret;
}

void Datagram::setDataType(int dataType){
    this->dataType = dataType;
}

int Datagram::getTargetId(){
    int ret = this->targetId;
    return ret;
}

void Datagram::setTargetId(int targetId){
   this->targetId = targetId;
}

int Datagram::getOrigineId(){
    int ret = this->origineId;
    return ret;
}

void Datagram::setOrigineId(int origineId){
    this->origineId = origineId;
}

int Datagram::getTimeStampes(){
    int ret = this->timeStampes;
    return ret;
}

void Datagram::setTimeStampes(int timeStampes){
    this->timeStampes = timeStampes;
}

int Datagram::getDLC(){
    int ret = this->DLC;
    return ret;
}

void Datagram::setDLC(int DLC){
    this->DLC = DLC;
}
