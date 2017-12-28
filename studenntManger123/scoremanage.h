#ifndef SCOREMANAGE_H
#define SCOREMANAGE_H

#include <QWidget>

namespace Ui {
class scoremanage;
}

class scoremanage : public QWidget
{
    Q_OBJECT

public:
    explicit scoremanage(QWidget *parent = 0);
    ~scoremanage();

private slots:
    void on_score_querypushButton_clicked();

    void on_score_addpushButton_clicked();

    void on_score_deletepushButton_clicked();

    void on_score_upadtepushButton_clicked();

    void on_score_backpushButton_clicked();

private:
    Ui::scoremanage *ui;
};

#endif // SCOREMANAGE_H
