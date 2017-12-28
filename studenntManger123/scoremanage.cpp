#include "scoremanage.h"
#include "ui_scoremanage.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "manger.h"
scoremanage::scoremanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scoremanage)
{
    ui->setupUi(this);
}

scoremanage::~scoremanage()
{
    delete ui;
}

void scoremanage::on_score_querypushButton_clicked()
{
    QString id=ui->score_IDlineEdit->text();
    QString object=ui->score_objectlineEdit->text();
    QString time=ui->score_termlineEdit->text();
    ui->score_teacherlineEdit->clear();
    ui->score_classlineEdit->clear();
    ui->score_scorelineEdit->clear();
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
        ui->score_IDlineEdit->setText(query.value(0).toString());
        ui->score_objectlineEdit->setText(query.value(1).toString());
        ui->score_termlineEdit->setText(query.value(2).toString());
        ui->score_classlineEdit->setText(query.value(3).toString());
        ui->score_teacherlineEdit->setText(query.value(4).toString());
        ui->score_scorelineEdit->setText(query.value(5).toString());



    }
        else
         {
           if(id.compare("")==0||object.compare("")==0||time.compare("")==0)

                     return;

           else   QMessageBox::information(this, "警告", "不存在你所要查找的数据");

         }
}

void scoremanage::on_score_addpushButton_clicked()
{
    QString id=ui->score_IDlineEdit->text();
    QString object=ui->score_objectlineEdit->text();
    QString term=ui->score_termlineEdit->text();
    QString banji=ui->score_classlineEdit->text();
    QString teacher=ui->score_teacherlineEdit->text();
    QString score=ui->score_scorelineEdit->text();




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
    query.exec("select id,time,object from score");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();
                   QString time1= query.value(1).toString();
                   QString object1= query.value(2).toString();


                   if(id.compare(id1)==0&&term.compare(time1)==0&&object.compare(object1)==0)
                   {

                    QMessageBox::information(this ,tr("提示") , tr("该编号已存在不允许再次添加!"));
                      T2=false;
                   }
                 }
    if(T2==true)
    {
         QString sql;
         sql = QString("insert into score ( id,object,banji,time,teacher,score)"
                  " VALUES ('%1', '%2' , '%3', '%4', '%5','%6' )")
            .arg(id).arg(object).arg(banji).arg(term).arg(teacher).arg(score);


        bool ok = query.exec(sql);
       if(ok)
       {

        QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
      }
      else
      {
        QMessageBox::information(this ,tr("提示") , tr("添加失败!"));
      }
   }
}

void scoremanage::on_score_deletepushButton_clicked()
{
    QString id=ui->score_IDlineEdit->text();
    QString term=ui->score_termlineEdit->text();
    QString object=ui->score_objectlineEdit->text();
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
        query.exec("select id,time,object from score");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();
                   QString term1= query.value(1).toString();
                   QString object1= query.value(2).toString();

                   if(id.compare(id1)==0&&term.compare(term1)==0&&object.compare(object1)==0)
                  {
                       QString sql;
                       sql = QString("DELETE FROM score "
                                     " where id='"+id+"' and object='"+object+"' and time='"+term+"'");
                       QSqlQuery query;
                       bool ok = query.exec(sql);
                       if(ok)
                       {

                           QMessageBox::information(this ,tr("提示") , tr("删除成功!"));
                           T2=false;
                       }
                       else
                       {
                           QMessageBox::information(this ,tr("提示") , tr("删除失败!"));
                           T2=false;
                       }

                   }
                 }
    if(T2==true)
    {

       QMessageBox::information(this ,tr("提示") , tr("改编号不存在无法删除"));


    }
}

void scoremanage::on_score_upadtepushButton_clicked()
{
    QString id=ui->score_IDlineEdit->text();
    QString term=ui->score_termlineEdit->text();
    QString object=ui->score_objectlineEdit->text();
    QString score=ui->score_scorelineEdit->text();
    QString teacher=ui->score_teacherlineEdit->text();
    QString banji=ui->score_classlineEdit->text();
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
        query.exec("select id,time,object from score");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();
                   QString term1= query.value(1).toString();
                   QString object1= query.value(2).toString();


                   if(id.compare(id1)==0&&term.compare(term1)==0&&object.compare(object1)==0)
                  {
                       QString sql;
                       sql = QString("UPDATE score "
                                     "set  score= '%0',banji= '%1',teacher='%2'"
                                     " where id='"+id+"' and object='"+object+"' and time='"+term+"'")
                               .arg(score).arg(banji).arg(teacher);



                       QSqlQuery query;
                       bool ok = query.exec(sql);
                       if(ok)
                       {

                           QMessageBox::information(this ,tr("提示") , tr("更改成功!"));
                           T2=false;
                       }
                       else
                       {
                           QMessageBox::information(this ,tr("提示") , tr("更改失败!"));
                           T2=false;
                       }

                   }
                 }
    if(T2==true)
    {

       QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法更改"));


    }
}

void scoremanage::on_score_backpushButton_clicked()
{
    this->hide();
    manger *yh=new manger;
    yh->show();
}
