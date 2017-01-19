#ifndef IGTENCODINGTASK_H
#define IGTENCODINGTASK_H

#include <QThread>
#include "igtDataware.h"
#include "CollabIGT_OutputQueueManager.h"
#include "ImageMessage.h"
#include "CGlobal.h"


class EncodingTask : public QThread
{
    Q_OBJECT

private:
    igtDataware *dataware;
    OutputQueueManager *outputQueueManager;
    bool flag;
    int global_datagram_size;

public:
    void run();
    void stop();
    void encodeImageData(CTImage *img, int global_datagram_size);

signals:

public slots:

public:
    explicit EncodingTask(igtDataware *dataware, OutputQueueManager *outputQueueManager);
};

#endif // IGTENCODINGTASK_H
