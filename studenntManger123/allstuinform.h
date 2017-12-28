#ifndef ALLSTUINFORM_H
#define ALLSTUINFORM_H

#include <QWidget>

namespace Ui {
class AllstuInform;
}

class AllstuInform : public QWidget
{
    Q_OBJECT

public:
    explicit AllstuInform(QWidget *parent = 0);
    ~AllstuInform();

private slots:
    void on_back_stuButton_clicked();

private:
    Ui::AllstuInform *ui;
};

#endif // ALLSTUINFORM_H
