#ifndef BIDIMENTIONALCTIMAGE_H
#define BIDIMENTIONALCTIMAGE_H

#include "CollabIGT_Datagram.h"
#include "CTImage.h"
#include <QByteArray>
#include <QFile>
#include <QList>
#include <QDebug>

class ImageMessage:public Datagram
{

public:
    void encode(CTImage *input, QList<const char*>* output, int chunck_size);
    void decode();

public:
    ImageMessage();
};

#endif // BIDIMENTIONALCTIMAGE_H
