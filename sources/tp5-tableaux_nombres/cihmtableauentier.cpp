#include "cihmtableauentier.h"

//----------------------------------------------------------------------------------------------

//Constructeur

CIhmTableauEntier::CIhmTableauEntier()
{

}

//----------------------------------------------------------------------------------------------

//Menu

/*
        Algorithme de la méthode menu() de la classe CIhmTableauEntier :
    Auteur : Doolaeghe Kevin
    Date : Septembre 2017

    Variables :
        touche = caractère

    Début
        Répéter
            Afficher "  MENU  PRINCIPALE", "  DOOLAEGHE Kevin"
            Afficher "(a) ...", "(b) ...", [...], "(e) ...", "(q) Quitter", "Selectionnez a, b, c, d, e ou q : "
            touche <- Fonction touche pressée
            Si (touche = 'a' ou touche = 'A' ou touche = '1')	Alors	Lancer la méthode Exercice1()
            Si (touche = 'b' ou touche = 'B' ou touche = '2')	Alors	Lancer la méthode Exercice2()
            ...
            Si (touche = 'e' ou touche = 'E' ou touche = '5')	Alors	Lancer la méthode Exercice3()
        Jusqu'à (touche = 'q' ou touche = 'Q')
    Fin
*/

void CIhmTableauEntier::menu()
{
    char touche;
    short i;
    srand(time(0));
    color(0, 15); //system("color f0");
    do
    {
        clear(); //system("cls");
        gotoxy(27, 1); //Déplace le curseur aux coordonnées x = 27 et y = 1
        color(12, 15);
        cout << "Exercices sur les tableaux";
        gotoxy(25, 2);
        for(i = 0; i < 30; i++) cout << (char)205;
        gotoxy(32, 3);
        cout << "Doolaeghe Kevin";
        color(0, 15);
        gotoxy(5, 5);
        cout << "(a) Initialiser enti" << (char)138 << "rement le tableau a 0";
        gotoxy(5, 6);
        cout << "(b) Visualiser le tableau";
        gotoxy(5, 7);
        cout << "(c) Remplir le tableau avec des valeurs al" << (char)130 << "atoires comprises entre 0 et 20";
        gotoxy(5, 8);
        cout << "(d) Remplir le tableau avec des valeurs al" << (char)130 << "atoires comprises entre 5 et 18";
        gotoxy(5, 9);
        cout << "(e) Calculer la moyenne, la valeur max et la valeur min du tableau";
        gotoxy(5, 10);
        cout << "(f) Afficher le d" << (char)130 << "tail des notes du tableau avec histogramme";
        gotoxy(5, 11);
        cout << "(q) Quitter";
        gotoxy(10, 13);
        color(12, 15);
        cout << "S" << (char)130 << "lectionnez a, b, c, d, e ou q : ";
        color(0, 15);
        touche = getch();
        if(touche == 'a' || touche == 'A' || touche == '1') initTableau();
        if(touche == 'b' || touche == 'B' || touche == '2') affichageTableau();
        if(touche == 'c' || touche == 'C' || touche == '3') aleatoireValeurs_0_20();
        if(touche == 'd' || touche == 'D' || touche == '4') aleatoireValeurs(5, 18);
        if(touche == 'e' || touche == 'E' || touche == '5') moyenneTableau();
        if(touche == 'f' || touche == 'F' || touche == '6') histogrammeTableau();
    } while(touche != 'q' && touche != 'Q');
}

//----------------------------------------------------------------------------------------------

/*
        Algorithme de la méthode initTableau() de la classe CIhmTableauEntier :
    Auteur : Kevin Doolaeghe
    Date : Novembre 2017

    Variables d'entrée de la classe CIhmTableauEntier :
        tabNb = Tableau de 20 entiers
    Variable :
        i = entier

    Début
        Pour i allant de 0 à 19
            tabNb[i] <- 0
    Fin
*/

void CIhmTableauEntier::initTableau()
{
    for(int i = 0; i < 20; i++) //Boucle d'initialisation des valeurs du tableau à 0
    {
        tabNb[i] = 0;
    }
}

//----------------------------------------------------------------------------------------------

/*
        Algorithme de la méthode AffichageTableau() de la classe CIhmTableauEntier :
    Auteur : Kevin Doolaeghe
    Date : Novembre 2017

    Variables d'entrée de la classe CIhmTableauEntier :
        tabNb = Tableau de 20 entiers
    Variable :
        i = entier

    Début
        Afficher "Affichage du tableau"
        Pour i allant de 0 à 19
            Appel procédure gotoxy(36, i + 3)
            Si (i < 10)
                Alors   Afficher " "
            Afficher i, " - ", tabNb[i]
    Fin
*/

void CIhmTableauEntier::affichageTableau()
{
    short i;

    system("cls");
    gotoxy(29, 1);
    color(12, 15);
    cout << "Affichage du tableau :";
    gotoxy(25, 2);
    for(i = 0; i < 30; i++) cout << (char)205;
    color(0, 15);

    for(int i = 0; i < 20; i++) //Boucle pour parcourir toutes les cases du tableau afin de les afficher
    {
        gotoxy(36, i + 3);
        if(i < 10) cout << " ";
        cout << i << " - " << tabNb[i];
    }
    gotoxy(1, 1);
    getch();
}

//----------------------------------------------------------------------------------------------

/*
        Algorithme de la méthode aleatoireValeurs_0_20() de la classe CIhmTableauEntier :
    Auteur : Kevin Doolaeghe
    Date : Novembre 2017

    Variables d'entrée de la classe CIhmTableauEntier :
        tabNb = Tableau de 20 entiers
    Variable :
        i = entier

    Début
        Pour i allant de 0 à 19
            tabNb[i] <- Appel de la fonction rand() modulo 21
    Fin
*/

void CIhmTableauEntier::aleatoireValeurs_0_20()
{
    for(int i = 0; i < 20; i++)
    {
        tabNb[i] = rand() % 21; //Nombre aléatoire entre 0 et 20
    }
}

//----------------------------------------------------------------------------------------------

/*
        Algorithme de la méthode aleatoireValeurs(valInf = entier, valSup = entier) de la classe CIhmTableauEntier :
    Auteur : Kevin Doolaeghe
    Date : Novembre 2017

    Variables d'entrée de la classe CIhmTableauEntier :
        tabNb = Tableau de 20 entiers
    Variable :
        i = entier

    Début
        Pour i allant de 0 à 19
            tabNb[i] <- valInf + Appel de la fonction rand() modulo (valSup - valInf + 1)
    Fin
*/

void CIhmTableauEntier::aleatoireValeurs(int valInf, int valSup)
{
    for(int i = 0; i < 20; i++) //Boucle qui affecte une valeur aléatoire entre valInf et valSup à toutes les valeurs du tableau
    {
        tabNb[i] = rand() % (valSup - valInf + 1) + valInf; //Nombre aléatoire entre valInf et valSup
    }
}

//----------------------------------------------------------------------------------------------

/*
        Algorithme de la méthode moyenneTableau() de la classe CIhmTableauEntier :
    Auteur : Kevin Doolaeghe
    Date : Novembre 2017

    Variables d'entrée de la classe CIhmTableauEntier :
        tabNb = Tableau de 20 entiers
    Variables :
        i, somme, max, min = entiers

    Début
        somme <- 0
        max <- tabNb[0]
        min <- tabNb[0]
        Afficher "Affichage du tableau"
        Pour i allant de 0 à 19
            Appel de la procédure gotoxy(36, i + 3)
            Afficher i, " - ", tabNb[i]
            somme <- somme + tabNb[i]
            Si (tabNb[i] > max)
                Alors
                    max <- tabNb[i]
            Si (tabNb[i] < min)
                Alors
                    min <- tabNb[i]
        Appel de la procédure gotoxy(50; 8)
        Afficher "Valeur max : ", max
        Appel de la procédure gotoxy(50; 9)
        Afficher "Valeur min : ", min
        Appel de la procédure gotoxy(50; 10)
        Afficher "Moyenne : ", somme / 20
    Fin
*/

void CIhmTableauEntier::moyenneTableau()
{
    int somme = 0;
    int max = tabNb[0];
    int min = tabNb[0];
    short i;

    //Titre
    system("cls");
    gotoxy(15, 1);
    color(12, 15);
    cout << "Affichage de la moyenne, du maximum et du minimum :";
    gotoxy(25, 2);
    for(i = 0; i < 30; i++) cout << (char)205;
    color(0, 15);

    for(int i = 0; i < 20; i++) //Boucle qui permet de parcourir toutes les valeurs du tableau
    {
        //Affichage du tableau
        gotoxy(36, i + 3);
        if(i < 10) cout << " ";
        cout << i << " - " << tabNb[i];

        if(tabNb[i] > max) max = tabNb[i]; //Recherche de la valeur maximale
        if(tabNb[i] < min) min = tabNb[i]; //Recherche de la valeur minimale
        somme += tabNb[i]; //Calcul de la somme de toutes les valeurs du tableau
    }
    //Affichage
    gotoxy(55, 8);
    cout << "Valeur min : " << min;
    gotoxy(55, 9);
    cout << "Valeur max : " << max;
    gotoxy(58, 10);
    cout << "Moyenne : " << (float)(somme / 20);
    gotoxy(1, 1);
    getch();
}

//----------------------------------------------------------------------------------------------

/*
        Algorithme de la méthode histogrammeTableau() de la classe CIhmTableauEntier :
    Auteur : Kevin Doolaeghe
    Date : Novembre 2017

    Variables de la classe CIhmTableauEntier :
        tabNb = Tableau de 20 entiers
    Variables :
        i, j, compteur = entiers

    Début
        Appel de la procédure gotoxy(28, 1)
        Afficher "Affichage du tableau"
        Pour i allant de 0 à 19
            Appel de la procédure gotoxy(22, i + 4)
            Si (i < 10)
                Alors   Afficher " "
            Afficher i, " - ", tabNb[i]
        Pour i allant de 3 à 25
            Appel de la procédure gotoxy(45; i)
            Afficher "|"
        Pour i allant de 0 à 20
            Appel de la procédure gotoxy(5; i + 3)
            Si (i < 10)
                Alors   Afficher " "
            Afficher "i :"
            compteur <- 0
            Pour j allant de 0 à 19
                Si (tabNb[j] = i)
                    Alors   compteur <- compteur + 1
            Appel de la procédure gotoxy(34; i + 3)
            Afficher compteur
            Si (compteur = 0 ou compteur = 1)
                Alors   Afficher " note"
                Sinon   Afficher " notes"
            Appel de la procédure gotoxy(45; i + 3)
            Pour j allant de 0 à compteur - 1
                Afficher "*"
    Fin
*/

void CIhmTableauEntier::histogrammeTableau()
{
    short i, j, compteur;

    system("cls");
    gotoxy(28, 1);
    color(12, 15);
    cout << "Histogramme du tableau :";
    gotoxy(25, 2);
    for(i = 0; i < 30; i++) cout << (char)205;
    color(0, 15);
    //Affichage à gauche du tableau
    for(i = 0; i < 20; i++)
    {
        gotoxy(22, i + 4);
        if(i < 10) cout << " ";
        cout << i << " - " << tabNb[i];
    }
    //Affichage au milieu d'une délimitation
    for(i = 3; i < 25; i++)
    {
        gotoxy(39, i);
        cout << "|";
    }
    //Affichage à droite de l'histogramme
    for(i = 0; i <= 20; i++)
    {
        gotoxy(45, i + 4);
        if(i < 10) cout << " ";
        cout << i << " : ";
        //Calcul du nombre de notes entre 0 et 20
        compteur = 0;
        for(j = 0; j < 20; j++) //Boucle parcourant chacune des cases du tableau
        {
            if(tabNb[j] == i) compteur++;
        }
        //Affichage du nombre de notes
        gotoxy(50, i + 4);
        if(compteur < 10) cout << " ";
        cout << compteur;
        if(compteur == 0 || compteur == 1) cout << " note"; //Singulier
        else cout << " notes"; //Pluriel
        //Affichage des étoiles
        gotoxy(60, i + 4);
        for(j = 0; j < compteur; j++) cout << "*";
    }
    gotoxy(1, 1);
    getch();
}
