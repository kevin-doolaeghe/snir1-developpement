#include "form1.h"
#include "ui_form1.h"

Form1::Form1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);

    this->setFixedSize(230, 250); //Fixe la taille
    ui->labelFond->setGeometry(this->geometry()); //Place et dimensionne labelFond à la taille de l'objet centralWidget du Form1

    //labelHorloge
    ui->labelHorloge->setGeometry(35, 100, 160, 50);
    ui->labelHorloge->setFont(QFont("Times", 28, QFont::Bold));
    ui->labelHorloge->setFrameShape(QFrame::StyledPanel);
    ui->labelHorloge->setAlignment(Qt::AlignHCenter);
    ui->labelHorloge->setPalette(Qt::red);

    //labelAlarme
    ui->labelAlarme->setGeometry(75, 160, 80, 30);
    ui->labelAlarme->setFont(QFont("Times", 12, QFont::Bold));
    ui->labelAlarme->setFrameShape(QFrame::StyledPanel);
    ui->labelAlarme->setAlignment(Qt::AlignHCenter);
    ui->labelAlarme->setPalette(Qt::yellow);

    ui->labelAlarme->hide();

    //labelLogo
    ui->labelLogo->setGeometry(70, 30, 90, 65);

    timer1 = new QTimer;

    connect(timer1, SIGNAL(timeout()), this, SLOT(afficheHeure()));
    timer1->start(500);

    for(int i = 0; i < 60; i++)
    {
        cercle[i] = new MonCercle(this);

        int x = 100 * cos(2 * M_PI * i / 60) + this->width() / 2;
        int y = 100 * sin(2 * M_PI * i / 60) + this->height() / 2;
        cercle[i]->setGeometry(x, y, 12, 12);
    }
}

Form1::~Form1()
{
    delete ui;
}

void Form1::on_actionQuitter_triggered()
{
    this->close(); //Ferme la fenètre
}

void Form1::afficheHeure()
{
    QString hms ; //Objet hms sur la classe QString
    hms = QTime::currentTime().toString(); //Récupération heure courante dans hms
    ui->labelHorloge->setText(hms); //Mise à jour du label lableHorloge
}
