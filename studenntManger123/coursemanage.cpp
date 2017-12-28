#include "coursemanage.h"
#include "ui_coursemanage.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "manger.h"
coursemanage::coursemanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::coursemanage)
{
    ui->setupUi(this);
}

coursemanage::~coursemanage()
{
    delete ui;
}

void coursemanage::on_course_querypushButton_clicked()
{
    QString id=ui->course_IDlineEdit->text();


    if(id.compare("")==0)
    QMessageBox::information(this, "警告", "请输入课程号");

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


   query.exec("select object,teacher,coursetime,courseaddress,period,credit from course where id='"+id+"'");



    if(query.next()){
       qDebug()<<"第一条数据为"<<query.value(0).toString();
        ui->couresnamelineEdit->setText(query.value(0).toString());
        ui->course_teacherlineEdit->setText(query.value(1).toString());
        ui->course_timelineEdit->setText(query.value(2).toString());
        ui->course_addresslineEdit->setText(query.value(3).toString());
        ui->periodlineEdit->setText(query.value(4).toString());
        ui->creditlineEdit->setText(query.value(5).toString());



    }

    else{
           if(id.compare("")==0)
               return;

           else  QMessageBox::information(this, "警告", "不存在你所要查找的课程号");
      }
}

void coursemanage::on_course_addpushButton_clicked()
{
    QString id=ui->course_IDlineEdit->text();
    QString object=ui->couresnamelineEdit->text();
    QString teacher=ui->course_teacherlineEdit->text();
    QString coursetime=ui->course_timelineEdit->text();
    QString courseaddress=ui->course_addresslineEdit->text();
    QString period=ui->periodlineEdit->text();
    QString credit=ui->creditlineEdit->text();

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
    query.exec("select id from course");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();


                   if(id.compare(id1)==0)
                   {

                    QMessageBox::information(this ,tr("提示") , tr("该编号已存在不允许再次添加!"));
                      T2=false;
                   }
                 }
    if(T2==true)
    {
         QString sql;
         sql = QString("insert into course (id,object,teacher,coursetime,courseaddress,period,credit)"
                  " VALUES ('%1', '%2' , '%3', '%4', '%5', '%6', '%7' )")
            .arg(id).arg(object).arg(teacher).arg(coursetime).arg(courseaddress).arg(period).arg(credit);


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

void coursemanage::on_course_deletepushButton_clicked()
{
    QString id=ui->course_IDlineEdit->text();

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
        query.exec("select id from course");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();


                   if(id.compare(id1)==0)
                  {
                       QString sql;
                       sql = QString("DELETE FROM course "
                                     " where id = '%1' ").arg(id);

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

void coursemanage::on_course_updatepushButton_clicked()
{
    QString id=ui->course_IDlineEdit->text();
    QString object=ui->couresnamelineEdit->text();
    QString teacher=ui->course_teacherlineEdit->text();
    QString coursetime=ui->course_timelineEdit->text();
    QString courseaddress=ui->course_addresslineEdit->text();
    QString period=ui->periodlineEdit->text();
    QString credit=ui->creditlineEdit->text();
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
        query.exec("select id from course");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();


                   if(id.compare(id1)==0)
                  {
                       QString sql;
                       sql = QString("UPDATE course "
                                     "set  object= '%0',teacher= '%1',coursetime='%2',courseaddress='%3',period='%4',credit='%5'"
                                     " where id = '%6' ")
                               .arg(object).arg(teacher).arg(coursetime).arg(courseaddress).arg(period).arg(credit).arg(id);


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

void coursemanage::on_course_backpushButton_clicked()
{
    this->hide();
    manger *lk=new manger;
    lk->show();
}
