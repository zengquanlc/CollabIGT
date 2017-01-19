#include "BidimentionalCTImageMessage.h"

BidimentionalCTImageMessage::BidimentionalCTImageMessage()
{

}

void BidimentionalCTImageMessage::setWidth(int width){
    this->width = width;

}

int BidimentionalCTImageMessage::getWidth(){
    int ret = this->width;
    return ret;
}

void BidimentionalCTImageMessage::setHeight(int height){
    this->height = height;

}

int BidimentionalCTImageMessage::getHeight(){
    int ret = this->height;
    return ret;
}

void BidimentionalCTImageMessage::setDepth(int depth){
    this->depth = depth;

}

int BidimentionalCTImageMessage::getDepth(){
    int ret = this->depth;
    return ret;
}

void BidimentionalCTImageMessage::setXSpacing(int xSpacing){
    this->xSpacing = xSpacing;

}

int BidimentionalCTImageMessage::getXSpacing(){
    int ret = this->xSpacing;
    return ret;
}

void BidimentionalCTImageMessage::setYSpacing(int ySpacing){
    this->ySpacing = ySpacing;

}

int BidimentionalCTImageMessage::getYSpacing(){
    int ret = ySpacing;
    return ret;
}

void BidimentionalCTImageMessage::setZSpacing(int zSpacing){
    this->zSpacing = zSpacing;

}

int BidimentionalCTImageMessage::getZSpacing(){
    int ret = zSpacing;
    return ret;
}

void BidimentionalCTImageMessage::setDatatype(int datatype){
    this->datatype = datatype;

}

int BidimentionalCTImageMessage::getDatatype(){
    int ret = this->datatype;
    return ret;
}

void BidimentionalCTImageMessage::setMSB(int MSB){
    this->MSB = MSB;

}

int BidimentionalCTImageMessage::getMSB(){
    int ret = this->MSB;
    return ret;
}

void BidimentionalCTImageMessage::setCTImageMessageBody(QString CTImagePath){
    QFile *CTImageMessage = new QFile(CTImagePath);
    CTImageMessageBody = CTImageMessage->readAll();

}

char * BidimentionalCTImageMessage::getCTImageMessageBody(){
    char * ret = CTImageMessageBody;
    return ret;
}

QList<char *>* BidimentionalCTImageMessage::encode(){
    QList<char *> encodeByteArray;
    int temp = CTImageMessageBody.size()/1003;
    for(int i=0; i<temp; i++){0
        encodeByteArray.at(i).at(0) = (uchar)(0x000000ff&this->getDataType());
        encodeByteArray.at(i).at(1) = (uchar)((0x0000ff00&this->getDataType())>>8);

        encodeByteArray.at(i).at(2) = (uchar)((0x0000000ff&this->getOrigineId()));

        encodeByteArray.at(i).at(3) = (uchar)((0x000000ff&this->getTargetId()));

        encodeByteArray.at(i).at(4) = (uchar)((0x000000ff&this->getTimeStampes()));
        encodeByteArray.at(i).at(5) = (uchar)((0x0000ff00&this->getTimeStampes())>>8);
        encodeByteArray.at(i).at(6) = (uchar)((0x00ff0000&this->getTimeStampes())>>16);
        encodeByteArray.at(i).at(7) = (uchar)((0xff000000&this->getTimeStampes())>>24);

        encodeByteArray.at(i).at(8) = (uchar)((0x000000ff&1003));
        encodeByteArray.at(i).at(9) = (uchar)((0x0000ff00&1003)>>8);

        encodeByteArray.at(i).at(10) = (uchar)(0x000000ff&this->getWidth());
        encodeByteArray.at(i).at(11) = (uchar)((0x0000ff00&this->getWidth())>>8);

        encodeByteArray.at(i).at(12) = (uchar)(0x000000ff&this->getHeight());
        encodeByteArray.at(i).at(13) = (uchar)((0x0000ff00&this->getHeight())>>8);

        encodeByteArray.at(i).at(14) = (uchar)(0x000000ff&this->getDepth());
        encodeByteArray.at(i).at(15) = (uchar)((0x0000ff00&this->getDepth()));

        encodeByteArray.at(i).at(16) = (uchar)(0x000000ff&this->getXSpacing());

        encodeByteArray.at(i).at(17) = (uchar)(0x000000ff&this->getYSpacing());

        encodeByteArray.at(i).at(18) = (uchar)(0x000000ff&this->getZSpacing());

        encodeByteArray.at(i).at(19) = (uchar)(0x000000ff&this->getDatatype());

        encodeByteArray.at(i).at(20) = (uchar)(0x000000ff&this->getMSB());
        for(int y=0; y<1003; y++)
        {
            encodeByteArray.at(i).append(1003*i+y);
        }
    }




    return encodeByteArray;
}
