#ifndef IGTINPUTQUEUEMANAGER_H
#define IGTINPUTQUEUEMANAGER_H

#include <QVector>
#include <QObject>
#include <QTimer>
#include <QMutex>
#include "CollabIGT_InputQueue.h"

class InputQueueManager:public QObject
{
    Q_OBJECT

public:
    void addIgtInputQueue(InputQueue* inputQueue);
    int getLength();

    int getDataArrayCountFromInputQueue(int index);
    char* getDataArrayFromInputQueue(int index);
    void removeDataArrayFromInputQueue(int index);
    void addDataArrayFromInputQueue(int index, char *receiveMessage);


public slots:
    void print();

private:
    QVector<InputQueue*>igtInputDataware;
    QTimer *printTimer;
    QMutex mutex;


public:
    InputQueueManager();
};

#endif // IGTINPUTQUEUEMANAGER_H
