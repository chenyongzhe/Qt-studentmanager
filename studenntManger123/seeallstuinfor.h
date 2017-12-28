#ifndef SEEALLSTUINFOR_H
#define SEEALLSTUINFOR_H

#include <QWidget>

namespace Ui {
class seeallstuinfor;
}

class seeallstuinfor : public QWidget
{
    Q_OBJECT

public:
    explicit seeallstuinfor(QWidget *parent = 0);
    ~seeallstuinfor();

private slots:
    void on_backButton_clicked();

private:
    Ui::seeallstuinfor *ui;
};

#endif // SEEALLSTUINFOR_H
