#ifndef STUDENTFORM_H
#define STUDENTFORM_H

#include <QWidget>
#include <QDebug>
namespace Ui {
class studentForm;
}

class studentForm : public QWidget
{
    Q_OBJECT

public:
    explicit studentForm(QWidget *parent = 0);
    ~studentForm();

private slots:
   /*
     void receiveData(QString data);

     */


    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_student_findscore_clicked();

    void on_stu_find_dormButton_clicked();

    void on_stu_find_coursebutton_clicked();

    void on_stu_award_button_clicked();

    void on_stu_findclass_inforButton_clicked();

    void on_stu_query_fee_Button_clicked();

private:
    Ui::studentForm *ui;
};

#endif // STUDENTFORM_H
