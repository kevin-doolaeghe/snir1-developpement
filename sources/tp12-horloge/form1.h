#ifndef FORM1_H
#define FORM1_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <math.h>

#include "moncercle.h"

namespace Ui {
class Form1;
}

class Form1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = 0);
    ~Form1();

private slots:
    void on_actionQuitter_triggered();
    void afficheHeure();

private:
    Ui::Form1 *ui;
    QTimer *timer1;
    MonCercle *cercle[60];
};

#endif // FORM1_H
