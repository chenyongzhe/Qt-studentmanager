#ifndef COURSEMANAGE_H
#define COURSEMANAGE_H

#include <QWidget>

namespace Ui {
class coursemanage;
}

class coursemanage : public QWidget
{
    Q_OBJECT

public:
    explicit coursemanage(QWidget *parent = 0);
    ~coursemanage();

private slots:
    void on_course_querypushButton_clicked();

    void on_course_addpushButton_clicked();

    void on_course_deletepushButton_clicked();

    void on_course_updatepushButton_clicked();

    void on_course_backpushButton_clicked();

private:
    Ui::coursemanage *ui;
};

#endif // COURSEMANAGE_H
