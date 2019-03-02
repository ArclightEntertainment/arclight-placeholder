#-------------------------------------------------
#
# Project created by QtCreator 2019-02-11T05:58:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cuACS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -lsqlite3

SOURCES += \
    data/DatabaseInterface.cpp \
    interface/main.cpp \
    interface/Animal.cpp \
    interface/AnimalManager.cpp \
    interface/MainWindow.cpp \
    interface/AnimalInputDiag.cpp \
    interface/AnimalListView.cpp \
    interface/AnimalDetailDiag.cpp \
    interface/Species.cpp \
    interface/ClientInputDialog.cpp

HEADERS += \
    data/DatabaseInterface.h \
    interface/Animal.h \
    interface/AnimalManager.h \
    interface/MainWindow.h \
    interface/AnimalInputDiag.h \
    interface/AnimalListView.h \
    interface/AnimalDetailDiag.h \
    interface/Species.h \
    interface/ClientInputDialog.h

FORMS += \
    interface/listview.ui \
    interface/mainwindow.ui \
    interface/animaldetaildialog.ui \
    interface/animalinputdialog.ui \
    interface/clientinputdialog.ui