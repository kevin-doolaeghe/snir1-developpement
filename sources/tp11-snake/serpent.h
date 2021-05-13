#ifndef SERPENT_H
#define SERPENT_H

#include "positionXY.h"

class Serpent
{
public:
    Serpent();
    void afficheSerpent();
    void allongeSerpent();
    void deplaceSerpent();
    void initSerpent();
    bool mortSerpent();
    struct PositionXY tete;
    struct PositionXY corps[LONGUEUR_MAX];
    struct PositionXY carEffacement;
    struct PositionXY direction;
    int longueur;
};

#endif // SERPENT_H
