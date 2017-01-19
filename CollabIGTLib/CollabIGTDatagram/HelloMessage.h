#ifndef HELLOMESSAGE_H
#define HELLOMESSAGE_H

#include "CollabIGT_Datagram.h"

class HelloMessage : public Datagram
{
private:
    long count;
    int connectionState;
public:
    //get set

public:
    HelloMessage();
};

#endif // HELLOMESSAGE_H
