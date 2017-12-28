#ifndef CLASSMANAGE_H
#define CLASSMANAGE_H

#include <QWidget>

namespace Ui {
class classmanage;
}

class classmanage : public QWidget
{
    Q_OBJECT

public:
    explicit classmanage(QWidget *parent = 0);
    ~classmanage();

private slots:
    void on_class_querypushButton_clicked();

    void on_class_addpushButton_clicked();

    void on_class_deletepushButton_clicked();

    void on_class_upadatepushButton_clicked();

    void on_class_backpushButton_clicked();

private:
    Ui::classmanage *ui;
};

#endif // CLASSMANAGE_H
