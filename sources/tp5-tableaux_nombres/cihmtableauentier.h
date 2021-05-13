#ifndef CIHMTABLEAUENTIER_H
#define CIHMTABLEAUENTIER_H

#include "consoleJR.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class CIhmTableauEntier
{
    public:
        CIhmTableauEntier();
        void menu();
    private:
        int tabNb[20];
        void affichageTableau();
        void aleatoireValeurs(int valInf, int valSup);
        void aleatoireValeurs_0_20();
        void histogrammeTableau();
        void initTableau();
        void moyenneTableau();
};

#endif
