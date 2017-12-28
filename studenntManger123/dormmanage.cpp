#include "dormmanage.h"
#include "ui_dormmanage.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "seedorminfor.h"
dormmanage::dormmanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dormmanage)
{
    ui->setupUi(this);
}

dormmanage::~dormmanage()
{
    delete ui;
}

void dormmanage::on_dorm_queryButton_clicked()
{
    QString id=ui->dorm_inputlineEdit->text();
        ui->dormqingshi_numlineEdit->clear();
        ui->dorm_outIDlineEdit->clear();
        ui->dorm_namelineEdit->clear();
        ui->dorm_sexlineEdit->clear();
        ui->dorm_bednumlineEdit->clear();

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


   query.exec("select dormnum,id,name,sex,bednum from student where id='"+id+"'");



    if(query.next())
    {
       qDebug()<<"第一条数据为"<<query.value(0).toString();
        ui->dormqingshi_numlineEdit->setText(query.value(0).toString());
        ui->dorm_outIDlineEdit->setText(query.value(1).toString());
         ui->dorm_namelineEdit->setText(query.value(2).toString());
          ui->dorm_sexlineEdit->setText(query.value(3).toString());
           ui->dorm_bednumlineEdit->setText(query.value(4).toString());


    }

    else
    {
           if(id.compare("")==0)
               return;

           else  QMessageBox::information(this, "警告", "不存在你所要查找的编号");
     }
}

void dormmanage::on_dorm_addButton_clicked()
{
    QString id=ui->dorm_outIDlineEdit->text();
    QString dormnum=ui->dormqingshi_numlineEdit->text();
    QString name=ui->dorm_namelineEdit->text();
    QString sex=ui->dorm_sexlineEdit->text();
    QString bednum=ui->dorm_bednumlineEdit->text();



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
         sql = QString("insert into student (id,dormnum,name,sex,bednum)"
                  " VALUES ('%1', '%2' , '%3', '%4', '%5' )")
            .arg(id).arg(dormnum).arg(name).arg(sex).arg(bednum);


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

void dormmanage::on_dorm_deleteButton_clicked()
{
    QString id=ui->dorm_inputlineEdit->text();

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

void dormmanage::on_updateButton_clicked()
{
    QString id=ui->dorm_inputlineEdit->text();
    QString dormnum=ui->dormqingshi_numlineEdit->text();
    QString name=ui->dorm_namelineEdit->text();
    QString sex=ui->dorm_sexlineEdit->text();
    QString bednum=ui->dorm_bednumlineEdit->text();
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
                                     "set  dormnum= '%0',name= '%1',sex='%2',bednum='%3'"
                                     " where id = '%4' ")
                               .arg(dormnum).arg(name).arg(sex).arg(bednum).arg(id);


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

void dormmanage::on_dorm_backButton_clicked()
{
    this->hide();
    manger *lk=new manger;
    lk->show();
}

void dormmanage::on_see_all_dorm_Button_clicked()
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
    query.exec("select dormnum,id,name,sex,bednum,beizhu from student");

    while(query.next())
               {
                   QStringList q1;
                   q1.clear();
                  QString dormnum = query.value(0).toString();
                   QString id = query.value(1).toString();
                   QString name = query.value(2).toString();
                   QString sex =query.value(3).toString();
                   QString bednum=query.value(4).toString();
                   QString beizhu=query.value(5).toString();

                      q1<<dormnum <<id<<name<<sex<<bednum<<beizhu;
                      list_all_dormstudent.append(q1);

                    }

    this->hide();
    seedorminfor *ol=new seedorminfor;
    ol->show();
}
