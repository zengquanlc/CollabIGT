#include "HandShakeMessage.h"

HandShakeMessage::HandShakeMessage()
{

}

QString HandShakeMessage::getAddr(){
    QString addrs ;
    addrs.append(addr[0]);
    addrs.append(",");
    addrs.append(addr[1]);
    addrs.append(",");
    addrs.append(addr[2]);
    addrs.append(",");
    addrs.append(addr[3]);
    return addrs;
}

void HandShakeMessage::setAddr(QString address){
//    qDebug()<<address;
    QStringList addrs = address.split(".");
//    qDebug()<<addrs;
    addr[0] = (uchar)addrs[0].toInt();
    addr[1] = (uchar)addrs[1].toInt();
    addr[2] = (uchar)addrs[2].toInt();
    addr[3] = (uchar)addrs[3].toInt();
//    qDebug()<<addrs;
}

int HandShakeMessage::getPort(){
    int ret = this->port;
    return ret;
}

void HandShakeMessage::setPort(int port){
    this->port = port;
}

//QByteArray HandShakeMessage::decode(){}

QByteArray HandShakeMessage::encode(){

   QByteArray encodeByteArray;
   encodeByteArray.resize(1024);

   encodeByteArray[0] = (uchar)(0x000000ff&this->getDataType());
   encodeByteArray[1] = (uchar)((0x0000ff00&this->getDataType())>>8);

   encodeByteArray[2] = (uchar)((0x0000000ff&this->getOrigineId()));

   encodeByteArray[3] = (uchar)((0x000000ff&this->getTargetId()));

   encodeByteArray[4] = (uchar)((0x000000ff&this->getTimeStampes()));
   encodeByteArray[5] = (uchar)((0x0000ff00&this->getTimeStampes())>>8);
   encodeByteArray[6] = (uchar)((0x00ff0000&this->getTimeStampes())>>16);
   encodeByteArray[7] = (uchar)((0xff000000&this->getTimeStampes())>>24);

   encodeByteArray[8] = (uchar)((0x000000ff&this->getDLC()));
   encodeByteArray[9] = (uchar)((0x0000ff00&this->getDLC())>>8);

   encodeByteArray[10] = (uchar)((0x000000ff&this->addr[0]));
   encodeByteArray[11] = (uchar)((0x000000ff&this->addr[1]));
   encodeByteArray[12] = (uchar)((0x000000ff&this->addr[2]));
   encodeByteArray[13] = (uchar)((0x000000ff&this->addr[3]));

   encodeByteArray[14] = (uchar)((0x000000ff&this->getPort()));
   encodeByteArray[15] = (uchar)((0x0000ff00&this->getPort())>>8);


//   for(int count = 0; count < 30; count ++){
//       qDebug()<<count<<" "<<unsigned char(encodeByteArray[count]);
//   }


   return encodeByteArray;
}
