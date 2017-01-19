#include "igtDataware.h"

igtDataware::igtDataware()
{

}

void igtDataware::appendAnCTImage(CTImage* img){
    if(img==NULL){
        return;
    }
    imageSequenceToSend.append(img);
}

//!
//! \brief igtDataware::fetchImageToSend
//! \return
//!
CTImage* igtDataware::fetchLatestImageToSend(){
    if(imageSequenceToSend.size() > 0){
        CTImage* ret = imageSequenceToSend[0];
        return ret;
    }
    return NULL;
}

//! delete lastest image
void igtDataware::deleteLatest(){
    if(imageSequenceToSend.size() > 0){
        imageSequenceToSend.remove(0);
    }
}

int igtDataware::getDatawareLength(){
    int ret;
    ret= this->imageSequenceToSend.size();
    return ret;
}

