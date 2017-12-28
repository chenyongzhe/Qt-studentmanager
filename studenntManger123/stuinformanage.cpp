#include "stuinformanage.h"
#include "ui_stuinformanage.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "manger.h"
#include "seeallstuinfor.h"
stuinformanage::stuinformanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stuinformanage)
{
    ui->setupUi(this);
}

stuinformanage::~stuinformanage()
{
    delete ui;
}

void stuinformanage::on_infor_querypushButton_clicked()
{
    QString id=ui->infor_input_IDlineEdit->text();
        ui->infor_outputlineEdit->clear();
        ui->infor_classlineEdit->clear();
        ui->infor_namelineEdit->clear();
        ui->infor_majorlineEdit->clear();
        ui->infor_sexlineEdit->clear();
        ui->infor_adresslineEdit->clear();
        ui->infor_agelineEdit->clear();
        ui->infor_phonenumlineEdit->clear();


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


   query.exec("select id,name,sex,age,major,banji,address,phonenumber from student where id='"+id+"'");



    if(query.next())
    {
       qDebug()<<"第一条数据为"<<query.value(0).toString();
        ui->infor_outputlineEdit->setText(query.value(0).toString());
        ui->infor_namelineEdit->setText(query.value(1).toString());
        ui->infor_sexlineEdit->setText(query.value(2).toString());
        ui->infor_agelineEdit->setText(query.value(3).toString());
        ui->infor_majorlineEdit->setText(query.value(4).toString());
        ui->infor_classlineEdit->setText(query.value(5).toString());
        ui->infor_adresslineEdit->setText(query.value(6).toString());
        ui->infor_phonenumlineEdit->setText(query.value(7).toString());


    }

    else
    {
           if(id.compare("")==0)
               return;

           else  QMessageBox::information(this, "警告", "不存在你所要查找的编号");
     }
}

void stuinformanage::on_infor_addButton_clicked()
{
    QString id=ui->infor_input_IDlineEdit->text();
    QString name=ui->infor_namelineEdit->text();
    QString banji=ui->infor_classlineEdit->text();
    QString major=ui->infor_majorlineEdit->text();
    QString sex=ui->infor_sexlineEdit->text();
    QString address=ui->infor_adresslineEdit->text();
    QString age=ui->infor_agelineEdit->text();
    QString phonenumber=ui->infor_phonenumlineEdit->text();
    QString id2=ui->infor_outputlineEdit->text();

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


                   if(id2.compare(id1)==0)
                   {

                    QMessageBox::information(this ,tr("提示") , tr("该编号已存在不允许再次添加!"));
                      T2=false;
                   }
                 }
    if(T2==true)
    {
         QString sql;
         sql = QString("insert into student (id,name,sex,age,major,banji,address,phonenumber)"
                  " VALUES ('%1', '%2' , '%3','%4','%5','%6','%7','%8' )")
            .arg(id2).arg(name).arg(sex).arg(age).arg(major).arg(banji).arg(address).arg(phonenumber);


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

void stuinformanage::on_infor_deletepushButton_clicked()
{
    QString id=ui->infor_input_IDlineEdit->text();



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
        query.exec("select id from student");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();


                   if(id.compare(id1)==0)
                  {
                       QString sql;
                       sql = QString("DELETE FROM student "
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

void stuinformanage::on_infor_updatepushButton_clicked()
{
    QString id=ui->infor_input_IDlineEdit->text();
    QString banji=ui->infor_classlineEdit->text();
    QString name=ui->infor_namelineEdit->text();
    QString major=ui->infor_majorlineEdit->text();
    QString sex=ui->infor_sexlineEdit->text();
    QString address=ui->infor_adresslineEdit->text();
    QString age=ui->infor_agelineEdit->text();
    QString phonenumber=ui->infor_phonenumlineEdit->text();
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
        query.exec("select id from student");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();


                   if(id.compare(id1)==0)
                  {
                       QString sql;
                       sql = QString("UPDATE student "
                                     "set name = '%0',banji = '%1',major='%2',sex='%3',address='%4',age='%5',phonenumber='%6'"
                                     " where id = '%7' ")
                               .arg(name).arg(banji).arg(major).arg(sex).arg(address).arg(age).arg(phonenumber).arg(id);


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

void stuinformanage::on_infor_backpushButton_clicked()
{
    this->hide();
    manger *dg=new manger;
    dg->show();
}

void stuinformanage::on_infor_see_inforpushButton_clicked()
{
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
    query.exec("select id,name,sex,age,major,banji,address,phonenumber,beizhu from student");

    while(query.next())
               {
                   QStringList q;
                   q.clear();
                  QString id = query.value(0).toString();
                   QString user = query.value(1).toString();
                   QString pass = query.value(2).toString();
                   QString sex =query.value(3).toString();
                   QString age=query.value(4).toString();
                   QString major=query.value(5).toString();
                   QString banji=query.value(6).toString();
                   QString address=query.value(7).toString();
                     QString phonenumber=query.value(8).toString();
                      QString beizhu=query.value(9).toString();
                      q<<id<<user<<pass<<sex<<age<<major<<banji<<address<<phonenumber<<beizhu;
                      list_all_student.append(q);




              }


      for(int i=0;i<list_all_student.size();i++){
          qDebug()<<list_all_student[i];

      }



    this->hide();
    seeallstuinfor *rt=new seeallstuinfor;
    rt->show();
}
