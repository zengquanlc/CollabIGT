#include "CTImage.h"


CTImage::CTImage()
{

}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::CTImage
//! \param filePath
//!
CTImage::CTImage(QString filePath)
{
    this->doReadCTImageByPath(filePath);
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::setWidth
//! \param width
//!
void CTImage::setWidth(int width){
    this->width = width;

}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::getWidth
//! \return
//!
int CTImage::getWidth(){
    int ret = this->width;
    return ret;
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::setHeight
//! \param height
//!
void CTImage::setHeight(int height){
    this->height = height;
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::getHeight
//! \return
//!
int CTImage::getHeight(){
    int ret = this->height;
    return ret;
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::setDepth
//! \param depth
//!
void CTImage::setDepth(int depth){
    this->depth = depth;

}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::getDepth
//! \return
//!
int CTImage::getDepth(){
    int ret = this->depth;
    return ret;
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::setXSpacing
//! \param xSpacing
//!
void CTImage::setXSpacing(int xSpacing){
    this->xSpacing = xSpacing;

}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::getXSpacing
//! \return
//!
int CTImage::getXSpacing(){
    int ret = this->xSpacing;
    return ret;
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::setYSpacing
//! \param ySpacing
//!
void CTImage::setYSpacing(int ySpacing){
    this->ySpacing = ySpacing;

}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::getYSpacing
//! \return
//!
int CTImage::getYSpacing(){
    int ret = ySpacing;
    return ret;
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::setZSpacing
//! \param zSpacing
//!
void CTImage::setZSpacing(int zSpacing){
    this->zSpacing = zSpacing;

}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::getZSpacing
//! \return
//!
int CTImage::getZSpacing(){
    int ret = zSpacing;
    return ret;
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::setDatatype
//! \param datatype
//!
void CTImage::setDatatype(int datatype){
    this->datatype = datatype;
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::getDatatype
//! \return
//!
int CTImage::getDatatype(){
    int ret = this->datatype;
    return ret;
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::setMSB
//! \param MSB
//!
void CTImage::setMSB(int MSB){
    this->MSB = MSB;

}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::getMSB
//! \return
//!
int CTImage::getMSB(){
    int ret = this->MSB;
    return ret;
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::doReadCTImageByPath
//! \param CTImagePath
//!
void CTImage::doReadCTImageByPath(QString CTImagePath){
    //qDebug()<<CTImagePath;
    QFile *ctImageMessageFile = new QFile(CTImagePath);

    if(!ctImageMessageFile->open(QIODevice::ReadOnly/* | QIODevice::Truncate*/)){
        return;
    }

    QByteArray msg = ctImageMessageFile->readAll();

    //! convert msg from QByteArray into (const char *)
    ctImageMsgBody = new char[msg.size()];
    const char *ret = msg.constData();
    memcpy(ctImageMsgBody,ret,msg.size());
    ctImageSize = msg.size();
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::getCTImage
//! \return
//!
const char* CTImage::getCTImage(){
    return ctImageMsgBody;
}

//! -------------------------------------------------------------------------------------
//!
//! \brief CTImage::getCTImageLength
//! \return
//!
int CTImage::getCTImageLength(){
    return ctImageSize;
}
