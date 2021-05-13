#ifndef CIHMTABLEAUCAR_H
#define CIHMTABLEAUCAR_H

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

#include "consoleJR.h"
#include "afficheTitre.h"

using namespace std;

class CIhmTableauCar
{
    public:
        CIhmTableauCar();
        void menu(short nbProp);
    private:
        void saisirTexte();
        bool testPalindrome();
        void supprimeEspace();
        void afficheCaracteresTexte();
        void cryptageCerveau();
        void decomposeTexte();
        void miseEnMajuscule();
        void remplaceMot();
        unsigned char tabCar[1024];
        unsigned char tabCarModif[1024];
        char tabMot[100][25];
};

#endif
