#-------------------------------------------------
#
# Project created by QtCreator 2017-07-08T19:56:42
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = studenntManger
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


SOURCES += main.cpp\
        mainwindow.cpp \
    student.cpp \
    studentform.cpp \
    manger.cpp \
    globle.cpp \
    allstuinform.cpp \
    findscore.cpp \
    moneyfind.cpp \
    awardfind.cpp \
    dormfind.cpp \
    findclass.cpp \
    coursefind.cpp \
    userlogin.cpp \
    deletelogin.cpp \
    updatelogin.cpp \
    insertlogin.cpp \
    stuinformanage.cpp \
    seeallstuinfor.cpp \
    dormmanage.cpp \
    seedorminfor.cpp \
    awardmanage.cpp \
    scoremanage.cpp \
    coursemanage.cpp \
    classmanage.cpp \
    feemanage.cpp

HEADERS  += mainwindow.h \
    student.h \
    studentform.h \
    manger.h \
    globle.h \
    allstuinform.h \
    findscore.h \
    moneyfind.h \
    awardfind.h \
    dormfind.h \
    findclass.h \
    coursefind.h \
    userlogin.h \
    deletelogin.h \
    updatelogin.h \
    insertlogin.h \
    stuinformanage.h \
    seeallstuinfor.h \
    dormmanage.h \
    seedorminfor.h \
    awardmanage.h \
    scoremanage.h \
    coursemanage.h \
    classmanage.h \
    feemanage.h

FORMS    += mainwindow.ui \
    studentform.ui \
    manger.ui \
    allstuinform.ui \
    findscore.ui \
    moneyfind.ui \
    awardfind.ui \
    dormfind.ui \
    findclass.ui \
    coursefind.ui \
    userlogin.ui \
    deletelogin.ui \
    updatelogin.ui \
    insertlogin.ui \
    stuinformanage.ui \
    seeallstuinfor.ui \
    dormmanage.ui \
    seedorminfor.ui \
    awardmanage.ui \
    scoremanage.ui \
    coursemanage.ui \
    classmanage.ui \
    feemanage.ui

QT       += sql

