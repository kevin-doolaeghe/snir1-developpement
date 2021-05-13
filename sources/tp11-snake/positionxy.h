#ifndef POSITIONXY_H
#define POSITIONXY_H

//Offset X et Y
#define OFFSET_X 9
#define OFFSET_Y 3

#define LONGUEUR_MAX 300
#define FREQUENCE_HORLOGE 30

#define COULEUR_FOND 1
#define COULEUR_DEFAUT 15
#define COULEUR_TEXTE 15
#define COULEUR_PLATEAU 14
#define COULEUR_SERPENT 2
#define COULEUR_VIT_NORMALE 12
#define COULEUR_VIT_LONGUEUR 11
#define COULEUR_VIT_VITESSE 13

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <fstream>
#include "consoleJR.h"
#include "methods.h"

using namespace std;

//Structure PositionXY

struct PositionXY
{
    int posX;
    int posY;
};

#endif // POSITIONXY_H
