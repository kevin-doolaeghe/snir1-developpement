#ifndef CIHMAGENDA_H
#define CIHMAGENDA_H

#include <iostream>
#include <conio.h>
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
            {"Doolaeghe", "Kevin", "16 rue du Colombier", "Lys Lez Lannoy", "59390", "doolaeghe.kevin@gmail.com", "", "0781943995"},
            {"", "Pierre", "18 rue de Cohem", "Lys Lez Lannoy", "59390", "pierre@hotmail.com", "0320896145", "0645632197"},
            {"Dupont", "", "", "Dunkerque", "", "dupont.pro@gmail.com", "", "0652341957"},
            {"Braeckeveldt", "Damien", "", "", "", "damien.braeckeveldt@gmail.com", "", "0640516895"},
            {"Helmes", "Jos\x82", "5 rue de Cohem", "Lys Lez Lannoy", "59390", "", "", "0797543165"},
            {"Delvarre", "Christian", "Rue des Peupliers", "Roubaix", "59100", "rostand.delvarre@gmail.com", "0344556677", "0600112233"}
        };
};

#endif
