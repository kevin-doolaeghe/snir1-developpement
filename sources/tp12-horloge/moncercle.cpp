#include "moncercle.h"

MonCercle::MonCercle(QWidget *parent) :
    QWidget(parent)
{
    couleur = 1;
}

void MonCercle::paintEvent(QPaintEvent *e)
{
    QPainter cercle(this);

    QPen crayon(Qt::black, 1);
    cercle.setPen(crayon);

    switch(couleur)
    {
    case 1:
        cercle.setBrush(Qt::red);
        break;
    case 2:
        cercle.setBrush(Qt::yellow);
        break;
    case 3:
        cercle.setBrush(Qt::black);
        break;
    case 4:
        cercle.setBrush(Qt::white);
        break;
    }

    cercle.drawEllipse(0, 0, 10, 10);
}
