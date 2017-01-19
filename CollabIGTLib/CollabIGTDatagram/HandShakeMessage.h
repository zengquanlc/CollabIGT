#ifndef HANDSHAKEMESSAGE_H
#define HANDSHAKEMESSAGE_H

#include "CollabIGT_Datagram.h"
#include <QByteArray>
#include <QString>
#include <QStringList>
#include <QDebug>

class HandShakeMessage : public Datagram
{
public:
    QString getAddr();
    void  setAddr(QString address);
    int   getPort();
    void  setPort(int port);
//    QByteArray decode();
    QByteArray encode();

    //void printSelf();

private:
    unsigned char addr[4];//!4字节
    int port;       //!2字节

public:
    HandShakeMessage();
};

#endif // HANDSHAKEMESSAGE_H
