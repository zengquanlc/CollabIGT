#ifndef CTIMAGE_H
#define CTIMAGE_H

#include <QByteArray>
#include <QString>
#include <QFile>
#include <QDebug>
#include <cstring>
class CTImage
{

public:
    void setWidth(int width);   //!2 byte
    int getWidth();

    void setHeight(int height); //!2 byte
    int getHeight();

    void setDepth(int depth);   //!2 byte
    int getDepth();

    void setXSpacing(int xSpacing);//!1 byte
    int getXSpacing();

    void setYSpacing(int ySpacing);//!1 byte
    int getYSpacing();

    void setZSpacing(int zSpacing);//!1 byte
    int getZSpacing();

    void setDatatype(int datatype);//!1 byte char int short ....
    int getDatatype();

    void setMSB(int MSB);           //!1 byte
    int getMSB();

    void doReadCTImageByPath(QString CTImagePath);
    const char* getCTImage();

    int getCTImageLength();
private:
    int width;
    int height;
    int depth;
    int xSpacing;
    int ySpacing;
    int zSpacing;
    int datatype;
    int MSB;

    char *ctImageMsgBody;
    qint64 ctImageSize;

public:
    CTImage();
    CTImage(QString filePath);
};

#endif // CTIMAGE_H
