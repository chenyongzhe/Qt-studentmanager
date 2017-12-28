#include "updatelogin.h"
#include "ui_updatelogin.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "userlogin.h"
updatelogin::updatelogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updatelogin)
{
    ui->setupUi(this);
}

updatelogin::~updatelogin()
{
    delete ui;
}

void updatelogin::on_login_update_queryButton_clicked()
{
    QString id=ui->login_update_IDlineEdit->text();
     ui->login_updatenamelineEdit->clear();
     ui->update_loginpasswordlineEdit->clear();
    if(id.compare("")==0)
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


   query.exec("select username,password from admin where id='"+id+"'");



    if(query.next())
    {
       qDebug()<<"第一条数据为"<<query.value(0).toString();
        ui->login_updatenamelineEdit->setText(query.value(0).toString());
        ui->update_loginpasswordlineEdit->setText(query.value(1).toString());


    }

    else
    {
           if(id.compare("")==0)
               return;

           else  QMessageBox::information(this, "警告", "不存在你所要查找的编号");
     }
}

void updatelogin::on_login_updatepushButton_clicked()
{
    QString id=ui->login_update_IDlineEdit->text();
    QString username=ui->login_updatenamelineEdit->text();
    QString password=ui->update_loginpasswordlineEdit->text();

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
        query.exec("select id from admin");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();


                   if(id.compare(id1)==0)
                  {
                       QString sql;
                       sql = QString("UPDATE admin "
                                     "set username = '%0',password = '%1'"
                                     " where id = '%2' ")
                               .arg(username).arg(password).arg(id);


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

void updatelogin::on_loginupdatebackButton_clicked()
{
    this->hide();
    userlogin *ty=new userlogin;
    ty->show();
}
