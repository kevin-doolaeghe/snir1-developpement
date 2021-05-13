#include "form1.h"
#include "ui_form1.h"

Form1::Form1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);

    trame = new TrameManip;
}

Form1::~Form1()
{
    delete ui;
}

void Form1::on_actionQuitter_triggered()
{
    this->close();
}

void Form1::on_pushButtonRechercher_clicked()
{
    string data;
    data = trame->getData();

    if(!data.empty()) QMessageBox::information(NULL, "Rechercher", QString::fromStdString(data));
}

void Form1::on_pushButtonSupprimer_clicked()
{
    bool suppr = trame->supprimeData();

    if(suppr) QMessageBox::information(NULL, "Supprimer", "Suppression effectuée");
    else QMessageBox::warning(NULL, "Supprimer", "Donnée introuvable");

    ui->textEditTrame->setText(QString::fromStdString(trame->getTrame()));
}

void Form1::on_pushButtonAjouter_clicked()
{
    trame->setData(ui->lineEditDonnees->text().toStdString());

    ui->textEditTrame->setText(QString::fromStdString(trame->getTrame()));
}

void Form1::on_pushButtonRemplacer_clicked()
{
    bool modif = trame->modifData(ui->lineEditDonnees->text().toStdString());

    if(modif) QMessageBox::information(NULL, "Remplacer", "Remplacement effectuée");
    else QMessageBox::warning(NULL, "Remplacer", "Donnée introuvable");

    ui->textEditTrame->setText(QString::fromStdString(trame->getTrame()));
}

void Form1::on_actionEffacer_triggered()
{
    trame->setTrame("");

    ui->textEditTrame->setText(QString::fromStdString(trame->getTrame()));
}

void Form1::on_lineEditHeadBalise_textChanged(const QString &arg1)
{
    trame->setHeadBalise(ui->lineEditHeadBalise->text().toStdString());
}

void Form1::on_lineEditEndBalise_textChanged(const QString &arg1)
{
    trame->setEndBalise(ui->lineEditEndBalise->text().toStdString());
}
