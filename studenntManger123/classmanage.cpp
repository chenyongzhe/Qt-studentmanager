#include "classmanage.h"
#include "ui_classmanage.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "manger.h"
classmanage::classmanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::classmanage)
{
    ui->setupUi(this);
}

classmanage::~classmanage()
{
    delete ui;
}

void classmanage::on_class_querypushButton_clicked()
{
    QString classid=ui->class_classIDlineEdit->text();
        ui->class_classnamelineEdit->clear();
        ui->class_majorlineEdit->clear();
        ui->class_membernumlineEdit->clear();
        ui->instructorlineEdit->clear();


    if(classid.compare("")==0)
    QMessageBox::information(this, "警告", "请输入编号");

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


   query.exec("select classname,major,membernum,instructor from class where classid='"+classid+"'");



    if(query.next())
    {
       qDebug()<<"第一条数据为"<<query.value(0).toString();
        ui->class_classnamelineEdit->setText(query.value(0).toString());
        ui->class_majorlineEdit->setText(query.value(1).toString());
         ui->class_membernumlineEdit->setText(query.value(2).toString());
          ui->instructorlineEdit->setText(query.value(3).toString());



    }

    else
    {
           if(classid.compare("")==0)
               return;

           else  QMessageBox::information(this, "警告", "不存在你所要查找的编号");
     }
}


void classmanage::on_class_addpushButton_clicked()
{
    QString classid=ui->class_classIDlineEdit->text();
    QString classname=ui->class_classnamelineEdit->text();
    QString major=ui->class_majorlineEdit->text();
    QString membernum=ui->class_membernumlineEdit->text();
    QString instructor=ui->instructorlineEdit->text();


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
    query.exec("select classid from class");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();


                   if(classid.compare(id1)==0)
                   {

                    QMessageBox::information(this ,tr("提示") , tr("该编号已存在不允许再次添加!"));
                      T2=false;
                   }
                 }
    if(T2==true)
    {
         QString sql;
         sql = QString("insert into class (classid,classname,major,membernum,instructor)"
                  " VALUES ('%1', '%2' , '%3', '%4', '%5' )")
            .arg(classid).arg(classname).arg(major).arg(membernum).arg(instructor);

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

void classmanage::on_class_deletepushButton_clicked()
{
    QString classid=ui->class_classIDlineEdit->text();

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
        query.exec("select classid from class");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();


                   if(classid.compare(id1)==0)
                  {
                       QString sql;
                       sql = QString("DELETE FROM class "
                                     " where classid = '%1' ").arg(classid);

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

void classmanage::on_class_upadatepushButton_clicked()
{
    QString classid=ui->class_classIDlineEdit->text();
    QString classname=ui->class_classnamelineEdit->text();
    QString major=ui->class_majorlineEdit->text();
    QString membernum=ui->class_membernumlineEdit->text();
    QString instructor=ui->instructorlineEdit->text();

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
        query.exec("select classid from class");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();


                   if(classid.compare(id1)==0)
                  {
                       QString sql;
                       sql = QString("UPDATE class "
                                     "set  classname= '%1',major='%2',membernum='%3',instructor='%4'"
                                     " where classid = '%5' ")
                               .arg(classname).arg(major).arg(membernum).arg(instructor).arg(classid);


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

void classmanage::on_class_backpushButton_clicked()
{
    this->hide();
    manger *wp=new  manger;
    wp->show();

}
