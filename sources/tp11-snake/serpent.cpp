#include "Serpent.h"

Serpent::Serpent()
{
    /*
        direction.x = 1 , direction.y = 0 : déplacement vers la droite.
        direction.x = -1 , direction.y = 0 : déplacement vers la gauche.
        direction.x = 0 ,direction.y = 1 : déplacement vers le bas.
        direction.x = 0 , direction.y = -1 : déplacement vers le haut.
    */
}

void Serpent::afficheSerpent()
{
    int i = longueur;

    //Affichage du caractère d'effacement
    gotoxy(OFFSET_X + carEffacement.posX, OFFSET_Y + carEffacement.posY);
    color(COULEUR_SERPENT, COULEUR_FOND);
    cout << " ";

    //Affichage du corps
    for (i = 0; i < longueur; i++)
    {
        gotoxy(OFFSET_X + corps[i].posX, OFFSET_Y + corps[i].posY);
        cout << "o";
    }

    //Affichage de la tête
    gotoxy(OFFSET_X + tete.posX, OFFSET_Y + tete.posY);
    cout << "@";
    color(COULEUR_DEFAUT, COULEUR_FOND);
}

void Serpent::allongeSerpent()
{
    longueur++;
}

void Serpent::deplaceSerpent()
{
    int i = longueur - 1;

    if (longueur) //Si le serpent a un corps
    {
        //carEfffacement prend les coordonnées du dernier corps
        carEffacement.posX = corps[i].posX;
        carEffacement.posY = corps[i].posY;

        //Boucle mettant au corps, les coordonnées du corps précédent
        while (i)
        {
            corps[i].posX = corps[i - 1].posX;
            corps[i].posY = corps[i - 1].posY;
            i--;
        }

        //Le premier corps prend les coordonnées de la tête
        corps[0].posX = tete.posX;
        corps[0].posY = tete.posY;
    }
    else //Si pas de corps
    {
        carEffacement.posX = tete.posX;
        carEffacement.posY = tete.posY;
    }

    //Mise à jour des coordonnées de la tête
    tete.posX += direction.posX;
    tete.posY += direction.posY;
}

void Serpent::initSerpent()
{
    //Aucune direction initiale
    direction.posX = 0;
    direction.posY = -1;

    int i;

    //Pas de corps
    longueur = 0;

    //Placement de la tête au milieu
    tete.posX = 30;
    tete.posY = 10;

    //Initialisation des coordonnées des parties du corps à (0, 0)
    for (i = 0; i < 100; i++)
    {
        corps[i].posX = 1;
        corps[i].posY = 1;
    }

    //Positionnement du caractère d'effacement à côté de la tête
    carEffacement.posX = 31;
    carEffacement.posY = 10;
}

bool Serpent::mortSerpent()
{
    bool retour = false;
    int i;

    //Si touche la grille
    if (tete.posX <= 0 || tete.posX >= 61 || tete.posY <= 0 || tete.posY >= 21)
    {
        retour = true;
    }

    //Si touche le corps
    for(i = 0; i < 100; i++)
    {
        if(tete.posX == corps[i].posX && tete.posY == corps[i].posY)
        {
            retour = true;
        }
    }

    return retour;
}
