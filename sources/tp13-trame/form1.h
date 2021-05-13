#ifndef FORM1_H
#define FORM1_H

#include <QMainWindow>
#include <QMessageBox>

#include "tramemanip.h"

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

    void on_pushButtonRechercher_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonAjouter_clicked();

    void on_pushButtonRemplacer_clicked();

    void on_actionEffacer_triggered();

    void on_lineEditHeadBalise_textChanged(const QString &arg1);

    void on_lineEditEndBalise_textChanged(const QString &arg1);

private:
    Ui::Form1 *ui;
    TrameManip *trame;
};

#endif // FORM1_H
