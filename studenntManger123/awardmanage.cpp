#include "awardmanage.h"
#include "ui_awardmanage.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "manger.h"
awardmanage::awardmanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::awardmanage)
{
    ui->setupUi(this);
}

awardmanage::~awardmanage()
{
    delete ui;
}

void awardmanage::on_award_querypushButton_clicked()
{
    QString id=ui->award_inputIDlineEdit->text();
    ui->awardlineEdit->clear();
    ui->classlineEdit->clear();
    ui->majorlineEdit->clear();
    ui->namelineEdit->clear();
    ui->outputIDlineEdit->clear();
    ui->punishlineEdit->clear();
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


   query.exec("select name,banji,major,award,punish from student where id='"+id+"'");



    if(query.next())
    {
       qDebug()<<"第一条数据为"<<query.value(0).toString();
        ui->namelineEdit->setText(query.value(0).toString());
        ui->classlineEdit->setText(query.value(1).toString());
        ui->majorlineEdit->setText(query.value(2).toString());
        ui->awardlineEdit->setText(query.value(3).toString());
        ui->punishlineEdit->setText(query.value(4).toString());
        ui->outputIDlineEdit->setText(id);




    }

    else
    {
           if(id.compare("")==0)
               return;

           else  QMessageBox::information(this, "警告", "不存在你所要查找的编号");
     }
}

void awardmanage::on_award_addpushButton_clicked()
{
    QString id=ui->outputIDlineEdit->text();
    QString name=ui->namelineEdit->text();
    QString banji=ui->classlineEdit->text();
    QString major=ui->majorlineEdit->text();
    QString award=ui->awardlineEdit->text();
    QString punish=ui->punishlineEdit->text();



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

                    QMessageBox::information(this ,tr("提示") , tr("该编号已存在不允许再次添加!"));
                      T2=false;
                   }
                 }
    if(T2==true)
    {
         QString sql;
         sql = QString("insert into student (id,name,banji,major,award,punish)"
                  " VALUES ('%1', '%2' , '%3', '%4', '%5', '%6' )")
            .arg(id).arg(name).arg(banji).arg(major).arg(award).arg(punish);


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

void awardmanage::on_award_deletepushButton_clicked()
{
    QString id=ui->award_inputIDlineEdit->text();

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

void awardmanage::on_award_updatepushButton_clicked()
{
    QString id=ui->award_inputIDlineEdit->text();
    QString name=ui->namelineEdit->text();
    QString banji=ui->classlineEdit->text();
    QString major=ui->majorlineEdit->text();
    QString award=ui->awardlineEdit->text();
    QString punish=ui->punishlineEdit->text();
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
                                     "set  name= '%0',banji= '%1',major='%2',award='%3',punish='%4'"
                                     " where id = '%5' ")
                               .arg(name).arg(banji).arg(major).arg(award).arg(punish).arg(id);


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

void awardmanage::on_award_backpushButton_clicked()
{
    this->hide();
    manger *sy=new manger;
    sy->show();
}
