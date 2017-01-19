#ifndef IGTDATAWARE_H
#define IGTDATAWARE_H

#include <QVector>
#include "CTImage.h"


class igtDataware
{
private:
    QVector<CTImage*> imageSequenceToSend;

public:
    void appendAnCTImage(CTImage* img);
    CTImage* fetchLatestImageToSend();
    void deleteLatest();
    int getDatawareLength();

public:
    igtDataware();
};

#endif // IGTDATAWARE_H
