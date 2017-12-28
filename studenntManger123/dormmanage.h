#ifndef DORMMANAGE_H
#define DORMMANAGE_H

#include <QWidget>

namespace Ui {
class dormmanage;
}

class dormmanage : public QWidget
{
    Q_OBJECT

public:
    explicit dormmanage(QWidget *parent = 0);
    ~dormmanage();

private slots:
    void on_dorm_queryButton_clicked();

    void on_dorm_addButton_clicked();

    void on_dorm_deleteButton_clicked();

    void on_updateButton_clicked();

    void on_dorm_backButton_clicked();

    void on_see_all_dorm_Button_clicked();

private:
    Ui::dormmanage *ui;
};

#endif // DORMMANAGE_H
