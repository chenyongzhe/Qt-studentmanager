#ifndef FINDSCORE_H
#define FINDSCORE_H

#include <QWidget>

namespace Ui {
class findscore;
}

class findscore : public QWidget
{
    Q_OBJECT

public:
    explicit findscore(QWidget *parent = 0);
    ~findscore();

private slots:
    void on_findscoreButton_clicked();

    void on_pushButton_findcore_back_clicked();

private:
    Ui::findscore *ui;
};

#endif // FINDSCORE_H
