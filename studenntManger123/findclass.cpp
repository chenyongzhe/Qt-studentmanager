#include "findclass.h"
#include "ui_findclass.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "studentform.h"
findclass::findclass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findclass)
{
    ui->setupUi(this);
}

findclass::~findclass()
{
    delete ui;
}

void findclass::on_stu_find_classqueryButton_clicked()
{
    QString id=ui->stu_find_classidIlineEdit->text();


    if(id.compare("")==0)
    QMessageBox::information(this, "警告", "请输入班级号");

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


   query.exec("select classname,major,membernum,instructor from class where classid='"+id+"'");



    if(query.next()){
       qDebug()<<"第一条数据为"<<query.value(0).toString();
        ui->stu_find_class_namelineEdit->setText(query.value(0).toString());
        ui->stu_find_class_majorlineEdit->setText(query.value(1).toString());
        ui->stu_find_class_numlineEdit->setText(query.value(2).toString());
        ui->stu_find_class_instructorlineEdit->setText(query.value(3).toString());





    }

    else{
           if(id.compare("")==0)
               return;

           else  QMessageBox::information(this, "警告", "不存在你所要查找的班级号");
      }
}

void findclass::on_stu_findclassbackButton_clicked()
{
    this->hide();
    studentForm *wi=new studentForm;
    wi->show();
}
