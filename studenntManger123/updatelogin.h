#ifndef UPDATELOGIN_H
#define UPDATELOGIN_H

#include <QWidget>

namespace Ui {
class updatelogin;
}

class updatelogin : public QWidget
{
    Q_OBJECT

public:
    explicit updatelogin(QWidget *parent = 0);
    ~updatelogin();

private slots:
    void on_login_update_queryButton_clicked();

    void on_login_updatepushButton_clicked();

    void on_loginupdatebackButton_clicked();

private:
    Ui::updatelogin *ui;
};

#endif // UPDATELOGIN_H
