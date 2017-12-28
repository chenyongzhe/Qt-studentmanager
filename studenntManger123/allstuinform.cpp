#include "allstuinform.h"
#include "ui_allstuinform.h"
#include"globle.h"
#include "studentform.h"

AllstuInform::AllstuInform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllstuInform)
{
    ui->setupUi(this);
    setWindowTitle(QString("设计者8001716066，陈永喆"));

    for(int i1=0;i1<list_all_student.size();i1++){

    int row = ui->tableWidget->rowCount();

    ui->tableWidget->insertRow(row);
   QStringList rowdata=list_all_student[i1].toStringList();

    for(int i  = 0 ; i <rowdata .size() ; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(rowdata.at(i));
        ui->tableWidget->setItem(row , i , item);
    }

}

}

AllstuInform::~AllstuInform()
{
    delete ui;
}

void AllstuInform::on_back_stuButton_clicked()
{
    this->hide();
        list_all_student.clear();
        ui->tableWidget->clear();

       studentForm  *f1=new studentForm;

         f1->show();
}
