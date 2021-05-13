#include "PlateauJeu.h"

PlateauJeu::PlateauJeu()
{

}

void PlateauJeu::affichePlateau()
{
    int i;
    int delai = 10;

    /*
        218 196 191
        179		179
        192 196 217
    */

    //Titre
    gotoxy(28, 1);
    color(COULEUR_TEXTE, COULEUR_FOND);
    cout << "Snake - Kevin Doolaeghe";
    color(COULEUR_DEFAUT, COULEUR_FOND);

    //Affichage de la grille avec effet
    color(COULEUR_PLATEAU, COULEUR_FOND);
    for (i = 0; i < 60; i++)
    {
        gotoxy(OFFSET_X + 1 + i, OFFSET_Y);
        cout << (char)196;
        Sleep(delai);
    }

    gotoxy(OFFSET_X + 61, OFFSET_Y);
    cout << (char)191;
    Sleep(delai);

    for (i = 0; i < 20; i++)
    {
        gotoxy(OFFSET_X + 61, OFFSET_Y + 1 + i);
        cout << (char)179;
        Sleep(delai);
    }

    gotoxy(OFFSET_X + 61, OFFSET_Y + 21);
    cout << (char)217;
    Sleep(delai);

    for (i = 59; i >= 0; i--)
    {
        gotoxy(OFFSET_X + 1 + i, OFFSET_Y + 21);
        cout << (char)196;
        Sleep(delai);
    }

    gotoxy(OFFSET_X, OFFSET_Y + 21);
    cout << (char)192;
    Sleep(delai);

    for (i = 19; i >= 0; i--)
    {
        gotoxy(OFFSET_X, OFFSET_Y + 1 + i);
        cout << (char)179;
        Sleep(delai);
    }

    gotoxy(OFFSET_X, OFFSET_Y);
    cout << (char)218;
    Sleep(delai);
}
