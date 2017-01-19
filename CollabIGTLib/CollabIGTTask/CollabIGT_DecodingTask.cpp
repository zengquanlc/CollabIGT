#include "CollabIGT_DecodingTask.h"

DecodingTask::DecodingTask(InputQueueManager *inputQueueManager)
{
    this->inputQueueManager = inputQueueManager;
    flag = true;
}

void DecodingTask::run(){
    while(flag){
        if(inputQueueManager->getLength() > 0){
            //qDebug()<<"-----------igtDecodingTask---------";
            for(unsigned char cpt = 0; cpt < inputQueueManager->getLength(); cpt++){

                if(inputQueueManager->getDataArrayCountFromInputQueue(cpt) == 0){
                    continue;
                }

                char* ret = inputQueueManager->getDataArrayFromInputQueue(cpt);


                qDebug()<<"size:"<<", value:"
                        <<((unsigned char)ret[0]) + ((unsigned char)ret[1])*256
                        <<(unsigned char)ret[2]
                        <<(unsigned char)ret[3]
                        <<(unsigned char)ret[4]
                        <<(unsigned char)ret[5]
                        <<(unsigned char)ret[6]
                        <<(unsigned char)ret[7]
                        <<(unsigned char)ret[8]
                        <<(unsigned char)ret[9]
                        <<(unsigned char)ret[10];
                inputQueueManager->removeDataArrayFromInputQueue(cpt);


            }
            //qDebug()<<"-----------igtDecodingTask---------";
        }
        usleep(10);
    }
}

void DecodingTask::stop(){
    flag = false;
}
