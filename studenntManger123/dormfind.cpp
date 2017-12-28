#include "dormfind.h"
#include "ui_dormfind.h"
#include "globle.h"
#include  "studentform.h"

dormfind::dormfind(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dormfind)
{
    ui->setupUi(this);
    setWindowTitle(QString("设计者8001716066，陈永喆"));
    for(int i1=0;i1<list_all_dormstudent.size();i1++){

    int row = ui->find_dorm_tableWidget->rowCount();

    ui->find_dorm_tableWidget->insertRow(row);
   QStringList rowdata=list_all_dormstudent[i1].toStringList();

    for(int i  = 0 ; i <rowdata .size() ; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(rowdata.at(i));
        ui->find_dorm_tableWidget->setItem(row , i , item);
    }

}



}

dormfind::~dormfind()
{
    delete ui;
}

void dormfind::on_stu_finddormButton_clicked()
{
    this->hide();
       list_all_dormstudent.clear();
        ui->find_dorm_tableWidget->clear();

       studentForm  *f2=new studentForm;

         f2->show();
}
