#include "awardfind.h"
#include "ui_awardfind.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "studentform.h"
awardfind::awardfind(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::awardfind)
{
    ui->setupUi(this);


}

awardfind::~awardfind()
{
    delete ui;
}

void awardfind::on_stu_award_querypushButton_clicked()
{
    QString id=ui->stu_award_Input_IDlineEdit->text();


    if(id.compare("")==0)
    QMessageBox::information(this, "警告", "请输入学号");

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

    qDebug()<<"ID为"<<id;
    QSqlQuery query(db);
    db.exec("SET NAMES 'GBK'");


   query.exec("select name,banji,major,award,punish from student where id='"+id+"'");



    if(query.next())
       {
        qDebug()<<"第一条数据为"<<query.value(0).toString();
        ui->stu_award_out_IDlineEdit->setText(id);
        ui->stu_award_namelineEdit->setText(query.value(0).toString());
        ui->stu_award_class_lineEdit->setText(query.value(1).toString());
        ui->stu_award_majorlineEdit->setText(query.value(2).toString());
        ui->stu_award_awardlineEdit->setText(query.value(3).toString());
        ui->stu_award_puishlineEdit->setText(query.value(4).toString());




         }

    else{
           if(id.compare("")==0)
               return;

           else  QMessageBox::information(this, "警告", "不存在你所要查找的学号");
         }

}

void awardfind::on_stu_award_backpushButton_clicked()
{
    this->hide();
    studentForm *sr=new studentForm;
    sr->show();
}
