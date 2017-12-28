#include "insertlogin.h"
#include "ui_insertlogin.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "userlogin.h"

insertlogin::insertlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insertlogin)
{
    ui->setupUi(this);
}

insertlogin::~insertlogin()
{
    delete ui;
}

void insertlogin::on_insertloginqueryButton_clicked()
{
    QString id=ui->inster_IdlineEdit->text();


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
        ui->insert_namelineEdit_->setText(query.value(0).toString());
        ui->insert_passwordlineEdit->setText(query.value(1).toString());


    }

    else
    {
           if(id.compare("")==0)
               return;

           else  QMessageBox::information(this, "警告", "不存在你所要查找的编号");
     }
}

void insertlogin::on_insertloginButton_clicked()
{
    QString id=ui->inster_IdlineEdit->text();
    QString username=ui->insert_namelineEdit_->text();
    QString password=ui->insert_passwordlineEdit->text();

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

                    QMessageBox::information(this ,tr("提示") , tr("该编号已存在不允许再次添加!"));
                      T2=false;
                   }
                 }
    if(T2==true)
    {
         QString sql;
         sql = QString("insert into admin (id,username,password)"
                  " VALUES ('%1', '%2' , '%3' )")
            .arg(id).arg(username).arg(password);


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



void insertlogin::on_insert_back_Button_clicked()
{
    this->hide();
    userlogin *qu=new userlogin;
    qu->show();
}
