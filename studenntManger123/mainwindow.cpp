#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include<globle.h>
#include "manger.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // connect(ui->LoginButton, SIGNAL(clicked()), this, SLOT(on_LoginButton_clicked()));
   // ui->hide();
   // connect(ui->LoginButton, SIGNAL(clicked()), this, SLOT(show2()));
    ui->Login_password->setEchoMode(QLineEdit::Password);
  ui->Login_username->setText("xh");
  ui->Login_password->setText("1234567");
  ui->radioButton_2->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoginButton_clicked()
{
   QString username = ui->Login_username->text();
   QString password = ui->Login_password->text();
   qDebug()<<"用户名："<<username<<"密码:"<<password;
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
   if( ui->radioButton->isChecked()){
       QSqlQuery query(db);
       db.exec("SET NAMES 'GBK'");
       query.exec("select id,username,password from admin");
       bool T1=false;
       while(query.next())
                  {
                      QString user = query.value(1).toString();
                      QString pass = query.value(2).toString();
                      qDebug() << user << pass ;
                      if(username.compare(user)==0&&password.compare(pass)==0){
                          password_qj=password;
                          username_qj=username;
                          T1=true;
                          this->hide();
                          m=new manger;
                      //    emit sendData(username+"&"+password);
                          m->show();
                      }


                 }


       if(T1==false)
        QMessageBox::information(this, "警告", "用户名或密码错误");


}

   if( ui->radioButton_2->isChecked()){


   QSqlQuery query(db);
   db.exec("SET NAMES 'GBK'");
   query.exec("select id,name,password from student");
   bool T=false;
   while(query.next())
              {
                  QString user = query.value(1).toString();
                  QString pass = query.value(2).toString();
                  qDebug() << user << pass ;
                  if(username.compare(user)==0&&password.compare(pass)==0){
                      password_qj=password;
                      username_qj=username;
                      T=true;
                      this->hide();
                      f=new studentForm;
                 //     emit sendData(username+"&"+password);
                      f->show();

                  }
              }

   if(T==false)
    QMessageBox::information(this, "警告", "用户名或密码错误");


   }



}

void MainWindow::show2(){
 this->hide();
  f=new studentForm;
//  connect(f-)

   f->show();


}



void MainWindow::on_remitButton_clicked()
{
    ui->Login_username->clear();
    ui->Login_password->clear();
}
