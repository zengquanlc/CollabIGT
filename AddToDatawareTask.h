#ifndef ADDTODATAWARETASK_H
#define ADDTODATAWARETASK_H
#include <QThread>
#include "igtDataware.h"
#include "CTImage.h"
#include <QString>
#include <QDir>

class AddToDatawareTask : public QThread
{
    Q_OBJECT

private:
    igtDataware *dataware;
    QString filePath;
public:
    void run();
public:
    AddToDatawareTask(igtDataware *dataware, QString filePath);
};

#endif // ADDTODATAWARETASK_H
