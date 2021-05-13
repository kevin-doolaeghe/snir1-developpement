#ifndef JEUSERPENT_H
#define JEUSERPENT_H

#include "plateaujeu.h"
#include "serpent.h"
#include "vitamine.h"

class JeuSerpent
{
public:
    JeuSerpent();
    void jouerJeuSerpent();
private:
    void menuJeuSerpent();
    bool finJeuSerpent();
    void afficheCommandes();
    void enregisterScore();
    PlateauJeu plateau;
    Serpent boa;
    Vitamine appat[3];
    int vitesse;
    float temps;
    bool scoreMaxAtteint;
};

#endif // JEUSERPENT_H
