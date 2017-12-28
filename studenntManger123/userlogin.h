#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>

namespace Ui {
class userlogin;
}

class userlogin : public QWidget
{
    Q_OBJECT

public:
    explicit userlogin(QWidget *parent = 0);
    ~userlogin();

private slots:
    void on_insert_loginButton_clicked();

    void on_user_login_back_clicked();

    void on_delete_loginButton_clicked();

    void on_update_userButton_clicked();

private:
    Ui::userlogin *ui;
};

#endif // USERLOGIN_H
