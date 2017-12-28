#include "coursefind.h"
#include "ui_coursefind.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "studentform.h"
coursefind::coursefind(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::coursefind)
{
    ui->setupUi(this);
    setWindowTitle(QString("设计者8001716066，陈永喆"));
}

coursefind::~coursefind()
{
    delete ui;
}

void coursefind::on_stu_query_courseButton_clicked()
{
    QString id=ui->stu_course_IDlineEdit->text();


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
        ui->stu_course_namelineEdit->setText(query.value(0).toString());
        ui->stu_teacher_namelineEdit->setText(query.value(1).toString());
        ui->stu_course_timelineEdit->setText(query.value(2).toString());
        ui->stu_course_addresslineEdit->setText(query.value(3).toString());
        ui->stu_course_periodlineEdit->setText(query.value(4).toString());
        ui->stu_course_creditlineEdit->setText(query.value(5).toString());



    }

    else{
           if(id.compare("")==0)
               return;

           else  QMessageBox::information(this, "警告", "不存在你所要查找的课程号");
      }

}

void coursefind::on_stu_course_backButton_clicked()
{
    this->hide();
    studentForm *st=new studentForm;
    st->show();
}
