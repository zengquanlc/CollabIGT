#ifndef IGTOUTPUTQUEUE_H
#define IGTOUTPUTQUEUE_H
#include <QList>
#include <QByteArray>
#include "igtDataware.h"
#include <QMutex>
#include <QDebug>

class OutputQueue
{
private:
    QList<const char*> outputQueue;
    QMutex mutex;

public:
    const char* getLatestMessage();
    int getOutputQueueLength();
    void append(QList<const char *>* sendMessage);
    void deleteLatestFrame();

 public:
    OutputQueue();
};

#endif // IGTOUTPUTQUEUE_H
