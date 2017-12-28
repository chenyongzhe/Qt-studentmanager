#ifndef FEEMANAGE_H
#define FEEMANAGE_H

#include <QWidget>

namespace Ui {
class feemanage;
}

class feemanage : public QWidget
{
    Q_OBJECT

public:
    explicit feemanage(QWidget *parent = 0);
    ~feemanage();

private slots:
    void on_fee_querypushButton_clicked();

    void on_fee_addpushButton_clicked();

    void on_fee_deletepushButton_clicked();

    void on_fee_updatepushButton_clicked();

    void on_fee_backpushButton_clicked();

private:
    Ui::feemanage *ui;
};

#endif // FEEMANAGE_H
