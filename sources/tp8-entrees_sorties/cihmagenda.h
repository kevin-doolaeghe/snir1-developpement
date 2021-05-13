#ifndef CIHMAGENDA_H
#define CIHMAGENDA_H

#include <iostream>
#include <conio.h>
#include <fstream>
#include "consoleJR.h"
#include "afficheTitre.h"
#include "Contact.h"

#define NB_CONTACT 200

using namespace std;

class CIhmAgenda
{
    public:
        CIhmAgenda();
        void menu(short nbProp);
        dataContact data;
    private:
        void afficheRepertoire();
        void ajoutElement();
        void retireElement();
        void rechercheNomPrenom();
        void rechercheVille();
        void modifieElement();
        dataContact agenda[NB_CONTACT] =
        {
            {"Doe", "John", "", "", "", "doe.john@gmail.com", "", ""}
        };
        int Sauvegarder_Fichier();
        int Ouvrir_Fichier();
};

#endif
