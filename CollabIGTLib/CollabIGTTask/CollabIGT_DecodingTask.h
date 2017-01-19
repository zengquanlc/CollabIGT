#ifndef IGTDECODINGTASK_H
#define IGTDECODINGTASK_H

#include <QThread>
#include "CollabIGT_InputQueueManager.h"


class DecodingTask : public QThread
{
    Q_OBJECT
public:
    void run();
    void stop();

private:
    InputQueueManager *inputQueueManager;
    bool flag;

public:
    explicit DecodingTask(InputQueueManager *inputQueueManager);

signals:

public slots:
};

#endif // IGTDECODINGTASK_H
