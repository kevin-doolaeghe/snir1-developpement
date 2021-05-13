#ifndef MONCERCLE_H
#define MONCERCLE_H

#include <QWidget>
#include <QPainter>

class MonCercle : public QWidget
{
    Q_OBJECT
public:
    explicit MonCercle(QWidget *parent = 0);
    int couleur;

signals:

public slots:
    void paintEvent(QPaintEvent *e);

};

#endif // MONCERCLE_H
