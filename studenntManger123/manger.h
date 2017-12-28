#ifndef MANGER_H
#define MANGER_H

#include <QWidget>

namespace Ui {
class manger;
}

class manger : public QWidget
{
    Q_OBJECT

public:
    explicit manger(QWidget *parent = 0);
    ~manger();

private slots:
    void on_pushButton_9_clicked();

    void on_userloginButton_clicked();

    void on_stu_inform_guanlipushButton_clicked();

    void on_dorm_guanliButton_clicked();

    void on_award_managepushButton_clicked();

    void on_scoremanagepushButton_clicked();

    void on_course_manageButton_clicked();

    void on_class_managepushButton_clicked();

    void on_feemanagepushButton_clicked();

private:
    Ui::manger *ui;
};

#endif // MANGER_H
