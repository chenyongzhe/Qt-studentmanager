#ifndef FINDCLASS_H
#define FINDCLASS_H

#include <QWidget>

namespace Ui {
class findclass;
}

class findclass : public QWidget
{
    Q_OBJECT

public:
    explicit findclass(QWidget *parent = 0);
    ~findclass();

private slots:
    void on_stu_find_classqueryButton_clicked();

    void on_stu_findclassbackButton_clicked();

private:
    Ui::findclass *ui;
};

#endif // FINDCLASS_H
