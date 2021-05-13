#include "Vitamine.h"

Vitamine::Vitamine()
{
    srand(time(NULL)); //Initialise la seed de rand()
}

void Vitamine::afficheVitamine()
{
    gotoxy(OFFSET_X + vit.posX, OFFSET_Y + vit.posY);
    switch (typeVit) //Affichage selon la couleur
    {
    case 0:
        color(COULEUR_VIT_NORMALE, COULEUR_FOND);
        break;
    case 1:
        color(COULEUR_VIT_LONGUEUR, COULEUR_FOND);
        break;
    case 2:
        color(COULEUR_VIT_VITESSE, COULEUR_FOND);
        break;
    }

    cout << "*"; //Affichage
    color(COULEUR_DEFAUT, COULEUR_FOND);
}

void Vitamine::deplaceVitamine()
{
    vit.posX = rand() % 60 + 1; //Nombre aléatoire entre 0 et 60
    vit.posY = rand() % 20 + 1;
}

void Vitamine::changerTypeVit()
{
    typeVit = rand() % 3; //Choix du type de la vitamine
}
