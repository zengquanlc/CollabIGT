#include "CollabIGT_EncodingTask.h"

EncodingTask::EncodingTask(igtDataware *dataware, OutputQueueManager *outputQueueManager)
{
    if(dataware == NULL || outputQueueManager == NULL){
        return;
    }
    this->dataware = dataware;
    this->outputQueueManager = outputQueueManager;
    this->flag = true;
    this->global_datagram_size = MAX_PACKET_SIZE;
}

//! ------------------------------------------------------------
//!
//! \brief igtEncodingTask::run
//!
//! Task to fetch
//!
void EncodingTask::run(){
    while(flag){

        if(this->outputQueueManager->getOutputQueueManagerLength() == 0 || this->dataware->getDatawareLength() == 0){
            continue;
        }

        //qDebug()<< "fetch the first image in the sequence and encode it in chunks of 64k";
        this->encodeImageData(dataware->fetchLatestImageToSend(), MAX_PACKET_SIZE);

        this->dataware->deleteLatest();

        msleep(500);
    }
}

//! ------------------------------------------------------------
//!
//! \brief igtEncodingTask::encode
//! \param img
//!
void EncodingTask::encodeImageData(CTImage *img, int global_datagram_size){
    //!encode an ct image to a list of ImageMessage
    if(img == NULL){
        return;
    }

    QList<const char*> ret;

    ImageMessage *image = new ImageMessage();
    image->setDataType(256);
    image->setOrigineId(1);
    image->setTargetId(2);
    image->setTimeStampes(12346);
    image->encode(img, &ret, global_datagram_size);

    this->outputQueueManager->setMessageToSendByTargetId(0, &ret);

}

void EncodingTask::stop(){
    flag = false;
}

