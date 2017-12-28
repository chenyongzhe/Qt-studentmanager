#ifndef AWARDFIND_H
#define AWARDFIND_H

#include <QWidget>

namespace Ui {
class awardfind;
}

class awardfind : public QWidget
{
    Q_OBJECT

public:
    explicit awardfind(QWidget *parent = 0);
    ~awardfind();

private slots:
    void on_stu_award_querypushButton_clicked();

    void on_stu_award_backpushButton_clicked();

private:
    Ui::awardfind *ui;
};

#endif // AWARDFIND_H
