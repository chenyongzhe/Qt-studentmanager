#include "findscore.h"
#include "ui_findscore.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "studentform.h"
findscore::findscore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findscore)
{
    ui->setupUi(this);
    setWindowTitle(QString("设计者8001716066，陈永喆"));
}

findscore::~findscore()
{
    delete ui;
}

void findscore::on_findscoreButton_clicked()
{
    QString id=ui->lineEdit_findscore_id->text();
    QString object=ui->lineEdit_findscore_object->text();
    QString time=ui->lineEdit_findscore_time->text();
    if(id.compare("")==0||object.compare("")==0||time.compare("")==0)
    QMessageBox::information(this, "警告", "查询条件输入不足");

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    db = QSqlDatabase::database("qt_sql_default_connection");
    else
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("studentmanager");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    if (!db.open())
    qDebug() << "Failed to connect to root mysql admin";
     else qDebug() << "open";


    QSqlQuery query(db);
    db.exec("SET NAMES 'GBK'");
  qDebug()<<":"<<id<<":"<<object<<":"<<time;

   query.exec("select id,object,time,banji,teacher,score from score where id='"+id+"' and object='"+object+"' and time='"+time+"'");



    if(query.next()){
       qDebug()<<"第一条数据为"<<query.value(0).toString();
        ui->lineEdit_findscore_id->setText(query.value(0).toString());
        ui->lineEdit_findscore_object->setText(query.value(1).toString());
        ui->lineEdit_findscore_time->setText(query.value(2).toString());
        ui->lineEdit_findscore_class->setText(query.value(3).toString());
        ui->lineEdit_findscore_teacher->setText(query.value(4).toString());
        ui->lineEdit_findscore_score->setText(query.value(5).toString());



    }
        else
         {
           if(id.compare("")==0||object.compare("")==0||time.compare("")==0)

                     return;

           else   QMessageBox::information(this, "警告", "不存在你所要查找的数据");

         }
}

void findscore::on_pushButton_findcore_back_clicked()
{
    this->hide();
    studentForm *ww=new studentForm;
    ww->show();
}
