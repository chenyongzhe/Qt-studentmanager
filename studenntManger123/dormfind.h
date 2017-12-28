#ifndef DORMFIND_H
#define DORMFIND_H

#include <QWidget>

namespace Ui {
class dormfind;
}

class dormfind : public QWidget
{
    Q_OBJECT

public:
    explicit dormfind(QWidget *parent = 0);
    ~dormfind();

private slots:
    void on_stu_finddormButton_clicked();

private:
    Ui::dormfind *ui;
};

#endif // DORMFIND_H
