#include "feemanage.h"
#include "ui_feemanage.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "manger.h"
feemanage::feemanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::feemanage)
{
    ui->setupUi(this);
}

feemanage::~feemanage()
{
    delete ui;
}

void feemanage::on_fee_querypushButton_clicked()
{
    QString id=ui->fee_IDlineEdit->text();
    QString name=ui->fee_namelineEdit->text();
    QString banji=ui->fee_banjilineEdit->text();
    QString term=ui->fee_termlineEdit->text();
    QString major=ui->fee_majorlineEdit->text();
      ui->fee_feelineEdit->clear();
      ui->fee_arrearage_lineEdit->clear();
    if(id.compare("")==0||name.compare("")==0||banji.compare("")==0||term.compare("")==0||major.compare("")==0)
    QMessageBox::information(this, "警告", "查询条件输入不足");

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
    qDebug() << "Failed to connect to root mysql ";
     else qDebug() << "open";


    QSqlQuery query(db);
    db.exec("SET NAMES 'GBK'");


   query.exec("select fee,arrearage from fee where id='"+id+"' and name='"+name+"' and banji='"+banji+"' and major='"+major+"' and term='"+term+"'");



    if(query.next()){
       qDebug()<<"第一条数据为"<<query.value(0).toString();
        ui->fee_feelineEdit->setText(query.value(0).toString());
        ui->fee_arrearage_lineEdit->setText(query.value(1).toString());



    }
        else
         {
           if(id.compare("")==0||name.compare("")==0||banji.compare("")==0||term.compare("")==0||major.compare("")==0)

                     return;

           else   QMessageBox::information(this, "警告", "不存在你所要查找的数据");

         }
}

void feemanage::on_fee_addpushButton_clicked()
{
    QString id=ui->fee_IDlineEdit->text();
    QString name=ui->fee_namelineEdit->text();
    QString banji=ui->fee_banjilineEdit->text();
    QString major=ui->fee_majorlineEdit->text();
    QString term=ui->fee_termlineEdit->text();
    QString fee=ui->fee_feelineEdit->text();
    QString arrearage=ui->fee_arrearage_lineEdit->text();



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
    query.exec("select id,name,banji,major,term from fee");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();
                   QString name1= query.value(1).toString();
                   QString banji1= query.value(2).toString();
                   QString major1= query.value(3).toString();
                   QString term1= query.value(4).toString();

                   if(id.compare(id1)==0&&term.compare(term1)==0&&major.compare(major1)==0&&name.compare(name1)==0&&banji.compare(banji1)==0)
                   {

                    QMessageBox::information(this ,tr("提示") , tr("该编号已存在不允许再次添加!"));
                      T2=false;
                   }
                 }
    if(T2==true)
    {
         QString sql;
         sql = QString("insert into fee ( id,name,major,banji,term,fee,arrearage)"
                  " VALUES ('%1', '%2' , '%3', '%4', '%5','%6','%7' )")
            .arg(id).arg(name).arg(major).arg(banji).arg(term).arg(fee).arg(arrearage);


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

void feemanage::on_fee_deletepushButton_clicked()
{
    QString id=ui->fee_IDlineEdit->text();
    QString name=ui->fee_namelineEdit->text();
    QString major=ui->fee_majorlineEdit->text();
    QString banji=ui->fee_banjilineEdit->text();
    QString term=ui->fee_termlineEdit->text();
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
        query.exec("select id,name,major,banji,term from fee");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();
                   QString name1= query.value(1).toString();
                   QString major1= query.value(2).toString();
                   QString banji1= query.value(3).toString();
                   QString term1= query.value(4).toString();

                   if(id.compare(id1)==0&&term.compare(term1)==0&&major.compare(major1)==0&&banji.compare(banji1)==0&&name.compare(name1)==0)
                  {
                       QString sql;
                       sql = QString("DELETE FROM fee "
                                     " where id='"+id+"' and name='"+name+"' and major='"+major+"' and term='"+term+"' and banji='"+banji+"'");
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

void feemanage::on_fee_updatepushButton_clicked()
{
    QString id=ui->fee_IDlineEdit->text();
    QString name=ui->fee_namelineEdit->text();
    QString major=ui->fee_majorlineEdit->text();
    QString banji=ui->fee_banjilineEdit->text();
    QString term=ui->fee_termlineEdit->text();
    QString fee=ui->fee_feelineEdit->text();
    QString arrearage=ui->fee_arrearage_lineEdit->text();

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
        query.exec("select id,name,term,major,banji from fee");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();
                   QString name1= query.value(1).toString();
                   QString term1= query.value(2).toString();
                   QString major1= query.value(3).toString();
                   QString banji1= query.value(4).toString();

                   if(id.compare(id1)==0&&term.compare(term1)==0&&name.compare(name1)==0&&banji.compare(banji1)==0&&major.compare(major1)==0)
                  {
                       QString sql;
                       sql = QString("UPDATE fee "
                                     "set  fee= '%0',arrearage= '%1' "
                                     " where id='"+id+"' and name='"+name+"' and major='"+major+"' and banji='"+banji+"' and major='"+major+"'")
                                            .arg(fee).arg(arrearage);



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

void feemanage::on_fee_backpushButton_clicked()
{
    this->hide();
    manger *sx=new manger;
    sx->show();
}
