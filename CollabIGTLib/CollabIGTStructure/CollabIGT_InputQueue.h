#ifndef IGTINPUTQUEUE_H
#define IGTINPUTQUEUE_H

#include <QList>
#include <QDebug>
#include <QMutex>


class InputQueue
{
public:
    void append(char*values);
    void print();
    char* getLatestArray();
    void deleteLatestArray();
    int getLength();

private:
    QMutex mutex;
    QList<char*> inputQueue;

public:
    InputQueue();
};

#endif // IGTINPUTQUEUE_H
