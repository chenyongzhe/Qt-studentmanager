#ifndef SEEDORMINFOR_H
#define SEEDORMINFOR_H

#include <QWidget>

namespace Ui {
class seedorminfor;
}

class seedorminfor : public QWidget
{
    Q_OBJECT

public:
    explicit seedorminfor(QWidget *parent = 0);
    ~seedorminfor();

private slots:
    void on_backButton_clicked();

private:
    Ui::seedorminfor *ui;
};

#endif // SEEDORMINFOR_H
