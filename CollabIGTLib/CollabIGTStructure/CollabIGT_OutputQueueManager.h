#ifndef IGTOUTPUTQUEUEMANAGER_H
#define IGTOUTPUTQUEUEMANAGER_H

#include <QObject>
#include <QMutex>
#include "CollabIGT_OutputQueue.h"
#include <QVector>
#include "ImageMessage.h"

class OutputQueueManager : public QObject
{
    Q_OBJECT
public:
    explicit OutputQueueManager(QObject *parent = 0);
    void addIgtOutputQueue(OutputQueue* outPutQueue);

    void setMessageToSendByTargetId(int ret, QList<const char*>* sendMessage);
    const char* getLatestMessageByOutputQueueIndex(int index);
    void deleteLatestMessageByOutputQueueIndex(int index);
    int getLatestMessageLengthByOutputQueueIndex(int index);
    int getOutputQueueManagerLength();
signals:

public slots:
private:
    QVector<OutputQueue*> outputQueueManager;
    int outputQueueManagerLength;
    QMutex mutex;
};

#endif // IGTOUTPUTQUEUEMANAGER_H
