#include "jeuserpent.h"

//Thread pour que le déplacement soit fluide
void* testClavier(void* arg)
{
    char car;
    Serpent* boa = (Serpent *) arg;

    while(true)
    {
        //Touche pressée
        if(_kbhit())
        {
            car = _getch();

            if(car == -32)
            {
                car = _getch();

                switch (car)
                {
                case 'K': //Gauche
                    if(!(boa->direction.posX == 1 && boa->direction.posY == 0) || !boa->longueur)
                    {
                        boa->direction.posX = -1;
                        boa->direction.posY = 0;
                    }
                    break;
                case 'M': //Droite
                    if(!(boa->direction.posX == -1 && boa->direction.posY == 0) || !boa->longueur)
                    {
                        boa->direction.posX = 1;
                        boa->direction.posY = 0;
                    }
                    break;
                case 'H': //Haut
                    if(!(boa->direction.posX == 0 && boa->direction.posY == 1) || !boa->longueur)
                    {
                        boa->direction.posX = 0;
                        boa->direction.posY = -1;
                    }
                    break;
                case 'P': //Bas
                    if(!(boa->direction.posX == 0 && boa->direction.posY == -1) || !boa->longueur)
                    {
                        boa->direction.posX = 0;
                        boa->direction.posY = 1;
                    }
                    break;
                }
            }
        }
        Sleep(FREQUENCE_HORLOGE);
    }

    return NULL;
}

//---------------------------------------------------------------

//Constructeur
JeuSerpent::JeuSerpent()
{
    menuJeuSerpent();
}

//---------------------------------------------------------------

/*

        Algorithme de la méthode JeuSerpent::jouerJeuSerpent( )

    Attribut de classe:
        boa : Serpent
        plateau : PlateauJeu
        appat : Vitamine
        vitesse : entier

    Variables :
        car : caractère

début

    faire
    {
        plateau.affichePlateau( ) // méthode de la classe PlateauJeu qui affiche la présentation
        // ainsi que le cadre représentant le plateau du jeu.
        boa.initSerpent( ) // méthode de la classe Serpent initialisant les attributs de cette classe
        appat.deplaceVitamine( ) // méthode de la classe Vitamine calculant les paramètres vit.x
        // et vit.y de façon aléatoire sur le plateau du jeu
        initialisation de la variable vitesse // vitesse à 150
        boa.afficheSerpent ( ) // méthode de la classe Serpent qui affiche le serpent sur le plateau
        attente de l’appuie d’une toucheclavier pour débuter la partie.
        faire
        {
            appat.afficheVitamine( );
            si (boa.tete.x = appat.vit.x et boa.tete.y = appat.vit.y)
            {
                boa.allongeSerpent( ) // méthode de la classe Serpent
                appat.deplaceVitamine( )
                . . . . // affichage boa.longueur et diminuer vitesse
            }
            boa.deplaceSerpent ( ) // méthode de la classe Serpent
            boa.afficheSerpent ( ) // méthode de la classe Serpent
            si ( touche tapée au clavier)
            {
                Car <- fonction qui retourne la touche tapée au clavier
                . . . mettre à jour les variables boa.direction.x et boa.direction.y
                en fonction de la variable Car
            }
            boucle d’attente avec la variable vitesse pour ralentir le jeu.
        } jusqu’à ( boa.mortSerpent( ) = 1 )
        afficher “Perdu - Voulez-vous recommencer (o/n) ?”
        car <- fonction qui retourne la touche tapée au clavier
    } jusqu’à ce que ( car = ‘n’ ou car = ‘N’ )

fin

*/

//Méthode jouerJeuSerpent()
void JeuSerpent::jouerJeuSerpent()
{
    bool quitter = false;
    int i;

    Serpent* ptBoa = (Serpent*) &boa;

    pthread_t threadDeplacement; //Création d'une variable de type pthread
    pthread_create(&threadDeplacement, NULL, testClavier, ptBoa); //Lancement du thread

    do
    {
        color(COULEUR_DEFAUT, COULEUR_FOND);
        clear();
        vitesse = 150;
        temps = 0;
        scoreMaxAtteint = false;

        plateau.affichePlateau();
        boa.initSerpent();

        boa.afficheSerpent();

        _getch();

        for (i = 0; i < 3; i++) //Initialisation des 3 vitamines
        {
            appat[i].changerTypeVit();
            appat[i].deplaceVitamine();
            appat[i].afficheVitamine();
        }

        //Début du jeu
        do
        {
            //Affichage du score
            color(COULEUR_TEXTE, COULEUR_FOND);
            gotoxy(1, 1);
            cout << "Score : " << boa.longueur;

            //Affichage du temps
            temps += (float)vitesse / 1000;
            gotoxy(1, 2);
            cout << "Temps : " << temps << " s   ";
            color(COULEUR_DEFAUT, COULEUR_FOND);

            //Affichage de la vitesse
            gotoxy(59, 1);
            cout << "Vitesse : ";
            if(vitesse > 125) cout << "Lent        ";
            else
            {
                if(vitesse > 100) cout << "Moyenne     ";
                else
                {
                    if(vitesse > 75) cout << "Rapide      ";
                    else cout << "Tr" << (char)138 << "s rapide ";
                }
            }

            gotoxy(0, 0);

            //Vitamine
            for(i = 0; i < 3; i++)
            {
                if(boa.tete.posX == appat[i].vit.posX && boa.tete.posY == appat[i].vit.posY) //Si mange une vitamine
                {
                    switch(appat[i].typeVit)
                    {
                    case 0: //Vitamine normale
                        boa.allongeSerpent();
                        vitesse -= 7;
                        break;
                    case 1: //Vitamine longueur
                        boa.allongeSerpent();
                        boa.allongeSerpent();
                        vitesse -= 10;
                        break;
                    case 2: //Vitamine vitesse
                        boa.allongeSerpent();
                        vitesse += 5;
                        break;
                    }

                    if(vitesse < 50) vitesse = 50;
                    if(vitesse > 175) vitesse = 175;

                    appat[i].changerTypeVit();
                    appat[i].deplaceVitamine();
                    appat[i].afficheVitamine();
                }
            }

            /*
            //Touche pressée
            if (_kbhit())
            {
                car = _getch();

                switch (car)
                {
                case 'K': //Gauche
                    boa.direction.posX = -1;
                    boa.direction.posY = 0;
                    break;
                case 'M': //Droite
                    boa.direction.posX = 1;
                    boa.direction.posY = 0;
                    break;
                case 'H': //Haut
                    boa.direction.posX = 0;
                    boa.direction.posY = -1;
                    break;
                case 'P': //Bas
                    boa.direction.posX = 0;
                    boa.direction.posY = 1;
                    break;
                }
            }
            */

            //Déplacement & affichage du serpent
            boa.deplaceSerpent();
            boa.afficheSerpent();

            //Horloge
            Sleep(vitesse);

            if(boa.longueur == LONGUEUR_MAX) scoreMaxAtteint = true; //Si score maximum atteint
        } while(!boa.mortSerpent() && !scoreMaxAtteint);

        quitter = finJeuSerpent();

    } while(!quitter);

    //_getch();
    pthread_cancel(threadDeplacement);
}

void JeuSerpent::menuJeuSerpent()
{
    //Menu

    //Initialisation
    char touche1, touche2;
    short selection = 1;
    short i;

    do
    {
        //Affichage du titre
        color(0, 15);
        clear();

        color(4, 15);
        gotoxy(25, 1);
        for(i = 0; i < 30; i++) cout << "=";
        gotoxy(29, 2);
        cout << "Snake - Menu Principal";
        gotoxy(25, 3);
        for(i = 0; i < 30; i++) cout << "=";

        color(0, 15);
        gotoxy(32, 4);
        cout << "Doolaeghe  Kevin";

        //Affichage des propositions
        gotoxy(10, 6);
        cout << "Jouer";
        gotoxy(10, 8);
        cout << "Commandes";

        //Affichage de l'option pour quitter
        gotoxy(10, 10);
        color(15, 12);
        cout << "Quitter";
        color(0, 15);

        do //Boucle de décalage du curseur selon le choix
        {
            //Effacage du curseur
            for(i = 6; i < 12; i++)
            {
                gotoxy(7, i);
                cout << "  ";
            }
            //Affichage du curseur
            gotoxy(7, selection * 2 + 4);
            color(12, 15);
            cout << ">>";
            color(0, 15);
            gotoxy(1, 1);

            //Détection de la touche pressée
            touche2 = 0; //Initialisation
            touche1 = _getch();
            if(touche1 == -32) touche2 = _getch(); //Touches directionnelles = 2 touches pressées
            if(touche2 == 72) //Flèche du haut
            {
                if(selection == 1) selection = 3;
                else selection -= 1;
            }
            if(touche2 == 80) //Flèche du bas
            {
                if(selection == 3) selection = 1;
                else selection += 1;
            }
        } while(touche1 != 13); //Touche entrée

        //Lancement de la fonction adéquate
        switch(selection)
        {
            case 1:
                jouerJeuSerpent();
                break;
            case 2:
                afficheCommandes();
                break;
        }

    } while(selection != 1 && selection != 3); //Quitter
}

bool JeuSerpent::finJeuSerpent()
{
    //Initialisation
    char touche1, touche2;
    short selection = 1;
    short i;
    bool retour;

    do
    {
        //Affichage du titre
        color(0, 15);
        clear();

        color(4, 15);
        gotoxy(25, 1);
        for(i = 0; i < 30; i++) cout << "=";
        gotoxy(34, 2);
        cout << "Fin de jeu !";
        gotoxy(25, 3);
        for(i = 0; i < 30; i++) cout << "=";

        color(0, 15);
        gotoxy(32, 4);
        cout << "Doolaeghe  Kevin";

        //Affichage des propositions
        gotoxy(10, 6);
        cout << "Recommencer";
        gotoxy(10, 8);
        cout << "Enregister mon score !";
        gotoxy(10, 10);
        cout << "Commandes";

        //Affichage de l'option pour quitter
        gotoxy(10, 12);
        color(15, 12);
        cout << "Quitter";
        color(0, 15);

        //Affichage du score
        color(4, 15);
        gotoxy(10, 17);
        cout << "R" << (char)130 << "sultats :";
        color(0, 15);
        gotoxy(15, 19);
        cout << "Score => " << boa.longueur;
        gotoxy(15, 20);
        cout << "Temps => " << temps;

        color(1, 15);
        if(boa.mortSerpent())
        {
            gotoxy(32, 15);
            cout << "Vous " << (char)136 << "tes mort !";
        }

        if(scoreMaxAtteint)
        {
            gotoxy(12, 15);
            cout << "Vous avez atteint le score maximum de " << LONGUEUR_MAX << " points !";
        }

        do //Boucle de décalage du curseur selon le choix
        {
            //Effacage du curseur
            for(i = 6; i < 14; i++)
            {
                gotoxy(7, i);
                cout << "  ";
            }
            //Affichage du curseur
            gotoxy(7, selection * 2 + 4);
            color(12, 15);
            cout << ">>";
            color(0, 15);
            gotoxy(1, 1);

            //Détection de la touche pressée
            touche2 = 0; //Initialisation
            touche1 = _getch();
            if(touche1 == -32) touche2 = _getch(); //Touches directionnelles = 2 touches pressées
            if(touche2 == 72) //Flèche du haut
            {
                if(selection == 1) selection = 4;
                else selection -= 1;
            }
            if(touche2 == 80) //Flèche du bas
            {
                if(selection == 4) selection = 1;
                else selection += 1;
            }
        } while(touche1 != 13); //Touche entrée

        //Lancement de la fonction adéquate
        switch(selection)
        {
        case 1:
            retour = false;
            break;
        case 2:
            enregisterScore();
            break;
        case 3:
            afficheCommandes();
            break;
        case 4:
            retour = true;
            break;
        }
    } while(selection != 1 && selection != 4);

    return retour;
}

void JeuSerpent::afficheCommandes()
{
    int i;

    clear();

    color(4, 15);
    gotoxy(25, 1);
    for(i = 0; i < 30; i++) cout << "=";
    gotoxy(35, 2);
    cout << "Commandes";
    gotoxy(25, 3);
    for(i = 0; i < 30; i++) cout << "=";

    color(0, 15);
    gotoxy(15, 5);
    cout << "Monter";
    gotoxy(45, 5);
    cout << "Fl" << (char)138 << "che du haut";
    gotoxy(15, 7);
    cout << "Descendre";
    gotoxy(45, 7);
    cout << "Fl" << (char)138 << "che du bas";
    gotoxy(15, 9);
    cout << "Aller " << (char)133 << " gauche";
    gotoxy(45, 9);
    cout << "Fl" << (char)138 << "che de gauche";
    gotoxy(15, 11);
    cout << "Aller " << (char)133 << " droite";
    gotoxy(45, 11);
    cout << "Fl" << (char)138 << "che de droite";

    for(i = 0; i < 9; i++)
    {
        gotoxy(40, i + 4);
        cout << "|";
    }

    gotoxy(1, 1);

    _getch();
}

void JeuSerpent::enregisterScore()
{
    ofstream fichierSauv;
    int i;
    char nom[31];

    do //Saisie du nom
    {
        clear();
        color(4, 15);
        gotoxy(25, 1);
        for(i = 0; i < 29; i++) cout << "=";
        gotoxy(27, 2);
        cout << "Enregistrement du score !";
        gotoxy(25, 3);
        for(i = 0; i < 29; i++) cout << "=";

        color(0, 15);
        gotoxy(10, 10);
        cout << "Entrez votre nom : ";
        color(4, 15);
        cinPtrLim(nom, 30);
    } while(nom[0] == 0);

    gotoxy(23, 15);
    fichierSauv.open("score.snake", ios::out | ios::app | ios::binary); //Ouverture du fichier

    if(fichierSauv.is_open()) //Si ouvert
    { //Ecrit les résultats
        fichierSauv << "\tScore de " << nom << " :" << endl;
        fichierSauv << "Longueur : " << boa.longueur << endl;
        fichierSauv << "Temps : " << temps << endl << endl;

        fichierSauv.close();

        cout << "Vos r" << (char)130 << "sultats sont enregistr" << (char)130 << "s ! :)";
    }
    else
    { //Si erreur
        cout << "Impossible d'ouvrir le fichier...";
    }

    _getch();
}
