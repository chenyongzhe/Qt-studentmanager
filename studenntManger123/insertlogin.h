#ifndef INSERTLOGIN_H
#define INSERTLOGIN_H

#include <QWidget>

namespace Ui {
class insertlogin;
}

class insertlogin : public QWidget
{
    Q_OBJECT

public:
    explicit insertlogin(QWidget *parent = 0);
    ~insertlogin();

private slots:
    void on_insertloginqueryButton_clicked();

    void on_insertloginButton_clicked();

    void on_insert_back_Button_clicked();

private:
    Ui::insertlogin *ui;
};

#endif // INSERTLOGIN_H
