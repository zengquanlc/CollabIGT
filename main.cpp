#include "CollabIGT_CommunicationStack.h"
#include <QApplication>
#include <QThread>
#include "igtDataware.h"
#include <QString>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug()<<"instantiate dataware";
    igtDataware *dataware = new igtDataware();

    qDebug()<<"load ct image sequence into dataware";
    QString filePath = "./reconstruct";
    AddToDatawareTask *addToDatawareTask = new AddToDatawareTask(dataware, filePath);
    addToDatawareTask->start();

    qDebug()<<"lancer le serveur";
    CommunicationStack *comStack = new CommunicationStack(dataware);
    comStack->launch();

    qDebug()<<"temporisation ...";
    QThread::sleep(1);

    qDebug()<<"connecter au serveur";
    comStack->connectera("127.0.0.1", 10703);

    return a.exec();
}
