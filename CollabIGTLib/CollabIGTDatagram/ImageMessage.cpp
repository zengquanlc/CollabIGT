#include "ImageMessage.h"

ImageMessage::ImageMessage()
{

}

void ImageMessage::decode(){

}

void ImageMessage::encode(CTImage *input, QList<const char*>* output, int chunck_size){
    if(input == NULL || output == NULL || input->getCTImageLength() <=0){
        return;
    }
    const char* img = input->getCTImage();

    int loop_count = 0;
    int last_frame_dlc = 0;

    if((input->getCTImageLength()%(chunck_size - 21 ) == 0)&&(input->getCTImageLength()>(chunck_size - 21 ))){
        loop_count = input->getCTImageLength()/(chunck_size - 21);
        last_frame_dlc = (chunck_size - 21 );
    }
    else if((input->getCTImageLength()%(chunck_size - 21 ) > 0)&&(input->getCTImageLength()<(chunck_size - 21 ))){
        last_frame_dlc = input->getCTImageLength()%(chunck_size - 21 );
        loop_count = 1;
    }
    else if((input->getCTImageLength()%(chunck_size - 21 ) > 0)&&(input->getCTImageLength()>(chunck_size - 21 ))){
        last_frame_dlc = input->getCTImageLength()%(chunck_size - 21 );
        loop_count = input->getCTImageLength()/(chunck_size - 21 ) + 1;
    }
    //qDebug()<<"loop_count:"<<loop_count;

    for(int cpt = 0; cpt < loop_count; cpt++){
        char *dg = new char[chunck_size];
        //! header
        dg[0] = (uchar)(0x000000ff&this->getDataType());
        dg[1] = (uchar)((0x0000ff00&this->getDataType())>>8);
        dg[2] = (uchar)((0x0000000ff&this->getOrigineId()));
        dg[3] = (uchar)(0x000000ff&this->getTargetId());
        dg[4] = (uchar)(0x000000ff&this->getTimeStampes());
        dg[5] = (uchar)((0x0000ff00&this->getTimeStampes())>>8);
        dg[6] = (uchar)((0x00ff0000&this->getTimeStampes())>>16);
        dg[7] = (uchar)((0xff000000&this->getTimeStampes())>>24);
        dg[8] = (uchar)(0x000000ff&1003);
        dg[9] = (uchar)((0x0000ff00&1003)>>8);

        //! body:
        dg[10] = (uchar)(0x000000ff&input->getWidth());
        dg[11] = (uchar)((0x0000ff00&input->getWidth())>>8);
        dg[12] = (uchar)(0x000000ff&input->getHeight());
        dg[13] = (uchar)((0x0000ff00&input->getHeight())>>8);
        dg[14] = (uchar)(0x000000ff&input->getDepth());
        dg[15] = (uchar)((0x0000ff&input->getDepth())>>8);
        dg[16] = (uchar)(0x000000ff&input->getXSpacing());
        dg[17] = (uchar)(0x000000ff&input->getYSpacing());
        dg[18] = (uchar)(0x000000ff&input->getZSpacing());
        dg[19] = (uchar)(0x000000ff&input->getDatatype());
        dg[20] = (uchar)(0x000000ff&input->getMSB());

        if(cpt == loop_count-1){
            for(int j = 0; j < last_frame_dlc; j++){
                dg[8] = (uchar)(0x000000ff&last_frame_dlc);
                dg[9] = (uchar)((0x0000ff00&last_frame_dlc)>>8);
                dg[21+j] = img[cpt*(chunck_size - 21)+j];
            }
        }
        else{
            for(int j = 0; j < (chunck_size - 21 ); j++){
                dg[21+j] = img[cpt*(chunck_size - 21 )+j];
            }
        }


        output->append(dg);
    }
   //qDebug()<<"loop_count-----:"<<loop_count;

}


