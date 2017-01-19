#ifndef IGTDATAGRAM_H
#define IGTDATAGRAM_H
#include <QByteArray>

class Datagram
{
private:
    //! datagram head
    int datagram_head_size; //2 + 1 + 1 + 4 + 2
    int dataType;   // 2 bytes
    int origineId;  // 1 byte
    int targetId;   // 1 byte
    int timeStampes;// 4 bytes
    int DLC;        // 2 byte;

    //! data body
    QByteArray body[1014];

public:
    int getDataType();
    void setDataType(int dataType);

    int getTargetId();
    void setTargetId(int targetId);

    int getOrigineId();
    void setOrigineId(int origineId);

    int getTimeStampes();
    void setTimeStampes(int timeStampes);

    int getDLC();
    void setDLC(int DLC);
public:
    Datagram();
};

#endif // IGTDATAGRAM_H
