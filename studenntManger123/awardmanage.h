#ifndef AWARDMANAGE_H
#define AWARDMANAGE_H

#include <QWidget>

namespace Ui {
class awardmanage;
}

class awardmanage : public QWidget
{
    Q_OBJECT

public:
    explicit awardmanage(QWidget *parent = 0);
    ~awardmanage();

private slots:
    void on_award_querypushButton_clicked();

    void on_award_addpushButton_clicked();

    void on_award_deletepushButton_clicked();

    void on_award_updatepushButton_clicked();

    void on_award_backpushButton_clicked();

private:
    Ui::awardmanage *ui;
};

#endif // AWARDMANAGE_H
