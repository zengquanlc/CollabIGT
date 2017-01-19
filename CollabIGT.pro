#-------------------------------------------------
#
# Project created by QtCreator 2017-01-06T13:53:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CollabIGT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += CollabIGTLib
INCLUDEPATH += CollabIGTLib/CollabIGTSocket
INCLUDEPATH += CollabIGTLib/CollabIGTTask
INCLUDEPATH += CollabIGTLib/CollabIGTStructure
INCLUDEPATH += igtDataware
INCLUDEPATH += CollabIGTLib/CollabIGTDatagram


SOURCES += main.cpp\
           mainwindow.cpp \
           CollabIGTLib/CollabIGTSocket/CollabIGT_TcpServer.cpp \
           CollabIGTLib/CollabIGT_CommunicationStack.cpp \
           CollabIGTLib/CollabIGTTask/CollabIGT_ReceptionTask.cpp \
           CollabIGTLib/CollabIGTTask/CollabIGT_TransmissionTask.cpp \
           igtDataware/CTImage.cpp \
           igtDataware/igtDataware.cpp \
           CollabIGTLib/CollabIGTDatagram/HandShakeMessage.cpp \
           CollabIGTLib/CollabIGTDatagram/HelloMessage.cpp \
           CollabIGTLib/CollabIGTDatagram/ImageMessage.cpp \
           AddToDatawareTask.cpp \
           CollabIGTLib/CGlobal.cpp \
    CollabIGTLib/CollabIGTTask/CollabIGT_DecodingTask.cpp \
    CollabIGTLib/CollabIGTTask/CollabIGT_EncodingTask.cpp \
    CollabIGTLib/CollabIGTDatagram/CollabIGT_Datagram.cpp \
    CollabIGTLib/CollabIGTDatagram/CollabIGT_DatagramAnalyser.cpp \
    CollabIGTLib/CollabIGTStructure/CollabIGT_InputQueue.cpp \
    CollabIGTLib/CollabIGTStructure/CollabIGT_InputQueueManager.cpp \
    CollabIGTLib/CollabIGTStructure/CollabIGT_OutputQueue.cpp \
    CollabIGTLib/CollabIGTStructure/CollabIGT_OutputQueueManager.cpp


HEADERS  += mainwindow.h \
            CollabIGTLib/CollabIGTSocket/CollabIGT_TcpServer.h \
            CollabIGTLib/CollabIGT_CommunicationStack.h \
            CollabIGTLib/CollabIGTTask/CollabIGT_ReceptionTask.h \
            CollabIGTLib/CollabIGTTask/CollabIGT_TransmissionTask.h \
            igtDataware/CTImage.h \
            igtDataware/igtDataware.h \
            CollabIGTLib/CollabIGTDatagram/BidimentionalCTImageMessage.h \
            CollabIGTLib/CollabIGTDatagram/HandShakeMessage.h \
            CollabIGTLib/CollabIGTDatagram/HelloMessage.h \
            CollabIGTLib/CollabIGTDatagram/ImageMessage.h \
            AddToDatawareTask.h \
            CollabIGTLib/CGlobal.h \
    CollabIGTLib/CollabIGTTask/CollabIGT_DecodingTask.h \
    CollabIGTLib/CollabIGTTask/CollabIGT_EncodingTask.h \
    CollabIGTLib/CollabIGTDatagram/CollabIGT_Datagram.h \
    CollabIGTLib/CollabIGTDatagram/CollabIGT_DatagramAnalyser.h \
    CollabIGTLib/CollabIGTStructure/CollabIGT_InputQueue.h \
    CollabIGTLib/CollabIGTStructure/CollabIGT_InputQueueManager.h \
    CollabIGTLib/CollabIGTStructure/CollabIGT_OutputQueue.h \
    CollabIGTLib/CollabIGTStructure/CollabIGT_OutputQueueManager.h
