#ifndef STUINFORMANAGE_H
#define STUINFORMANAGE_H

#include <QWidget>

namespace Ui {
class stuinformanage;
}

class stuinformanage : public QWidget
{
    Q_OBJECT

public:
    explicit stuinformanage(QWidget *parent = 0);
    ~stuinformanage();

private slots:
    void on_infor_querypushButton_clicked();

    void on_infor_addButton_clicked();

    void on_infor_deletepushButton_clicked();

    void on_infor_updatepushButton_clicked();

    void on_infor_backpushButton_clicked();

    void on_infor_see_inforpushButton_clicked();

private:
    Ui::stuinformanage *ui;
};

#endif // STUINFORMANAGE_H
