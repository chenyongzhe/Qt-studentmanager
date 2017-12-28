#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
   // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
 //   QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

  //  QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
 //   QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
 //   QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));


    MainWindow w;
    w.show();

    return a.exec();
}
