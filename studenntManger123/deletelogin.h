#ifndef DELETELOGIN_H
#define DELETELOGIN_H

#include <QWidget>

namespace Ui {
class deletelogin;
}

class deletelogin : public QWidget
{
    Q_OBJECT

public:
    explicit deletelogin(QWidget *parent = 0);
    ~deletelogin();

private slots:
    void on_deletequeryButton_clicked();

    void on_login_deleteButton_clicked();

    void on_deletebackButton_clicked();

private:
    Ui::deletelogin *ui;
};

#endif // DELETELOGIN_H
