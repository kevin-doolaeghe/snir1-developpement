#include "cihmtableaucar.h"

//----------------------------------------------------------------------------------------------

//Constructeur

CIhmTableauCar::CIhmTableauCar()
{
    strcpy((char *)tabCar, "Il \x82tait parti \x85 Lille.");
    strcpy((char *)tabCarModif,"Il \x82tait parti \x85 Lille.");

}

//----------------------------------------------------------------------------------------------

//Menu

/*
    Algorithme de la méthode menu(short nbProp)
    Auteur : Doolaeghe Kevin
    Date : Novembre 2017

    Variables :
    selection, i = Entier 16 bits
    touche1, touche2 = Caractères

    Début
    Répéter
        selection <- 1
        Appel de la procédure clear()
        Appel de la procédure afficheCentre("Menu Principal", 80, 1)
        Appel de la procédure gotoxy(32, 4)
        Afficher "Doolaeghe  Kevin"
        Appel de la procédure gotoxy(10, 6)
        Afficher "Proposition 1"
        Appel de la procédure gotoxy(10, 8)
        Afficher "Proposition 2"
        ...
        Appel de la procédure gotoxy(10, nbProp * 2 + 6)
        Afficher "Quitter"
        Répéter
            Pour i allant de 6 à nbProp * 2 + 8
                Appel de la procédure gotoxy(7, i)
                Afficher "  "
            Appel de la procédure gotoxy(7, selection * 2 + 4)
            Afficher ">>"
            Appel de la procédure gotoxy(1, 1)
            touche2 <- 0
            touche1 <- Fonction saisie d'un touche
            Si (touche1 = -32)
                Alors   touche2 <- Fonction saisie d'une touche
            Si (touche2 = 72)
                Alors   Si (selection = 1)
                            Alors   selection <- nbProp + 1
                            Sinon   selection <- selection - 1
            Si (touche2 = 80)
                Alors   Si (selection = nbProp + 1)
                            Alors   selection <- 1
                            Sinon   selection <- selection + 1
        Jusqu'à (touche1 = 13)
        Si (selection = 1)
            Alors   Appel de la méthode fonction1()
        Si (selection = 2)
            Alors   Appel de la méthode fonction2()
        ...
    Jusqu'à (selection = nbProp + 1)
    Fin
*/

void CIhmTableauCar::menu(short nbProp)
{
    //Initialisation
    char touche1, touche2;
    static short selection = 1;
    short i;

    //PlaySound(L".\\mario.wav", NULL, SND_ASYNC);
    color(0, 15); //system("color 0f");
    //system("mode con cols=80 lines=25");
    do
    {
        //Affichage du titre
        clear();
        color(12, 15);
        afficheCentre("Menu Principal", 80, 1);
        color(0, 15);
        gotoxy(32, 4);
        cout << "Doolaeghe  Kevin";
        gotoxy(1, 1);

        //Affichage des propositions
        gotoxy(10, 6);
        cout << "Saisie d'une chaine de 20 caract" << (char)138 << "res";
        gotoxy(10, 8);
        cout << "Visualisation de la chaine de 20 caract" << (char)138 << "res";
        gotoxy(10, 10);
        cout << "Suppression des espaces de la chaine de caract" << (char)138 << "res saisie au 1";
        gotoxy(10, 12);
        cout << "Transformation en majuscule de la chaine de caract" << (char)138 << "res saisie au 1";
        gotoxy(10, 14);
        cout << "Cryptage en chiffre de quelques lettres pour un exercice du cerveau";
        gotoxy(10, 16);
        cout << "V" << (char)130 << "rification si le mot ou la phrase saisie correspond " << (char)133 << " un palindrome";
        gotoxy(10, 18);
        cout << "Remplacer, dans le texte de l'item 1, un mot par un autre";
        gotoxy(10, 20);
        cout << "D" << (char)130 << "composition du texte saisi " << (char)133 << " l'item 1";

        //Affichage de l'option pour quitter
        gotoxy(10, nbProp * 2 + 6);
        color(15, 12);
        cout << "Quitter";
        color(0, 15);

        do //Boucle de décalage du curseur selon le choix
        {
            //Effacage du curseur
            for(i = 6; i < nbProp * 2 + 7; i++)
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
            touche1 = getch();
            if(touche1 == -32) touche2 = getch(); //Touches directionnelles = 2 touches pressées
            if(touche2 == 72) //Flèche du haut
            {
                if(selection == 1) selection = nbProp + 1;
                else selection -= 1;
            }
            if(touche2 == 80) //Flèche du bas
            {
                if(selection == nbProp + 1) selection = 1;
                else selection += 1;
            }
        } while(touche1 != 13); //Touche entrée

        //Lancement de la fonction adéquate
        switch(selection)
        {
            case 1:
                saisirTexte();
            break;
            case 2:
                afficheCaracteresTexte();
            break;
            case 3:
                supprimeEspace();
            break;
            case 4:
                miseEnMajuscule();
            break;
            case 5:
                cryptageCerveau();
            break;
            case 6:
                testPalindrome();
            break;
            case 7:
                remplaceMot();
            break;
            case 8:
                decomposeTexte();
            break;
        }
    } while(selection != nbProp + 1); //Quitter
}

//----------------------------------------------------------------------------------------------

//Exercice 1

/*
        Algorithme de la méthode saisirTexte() :
    Auteur : Kevin Doolaeghe
    Date : Décembre 2017

    Variables de la classe CIhmTableauCar :
        tabCar() = Tableau de 1024 caractères
        tabCarModif() = Tableau de 1024 caractères
    Variables :
        i = entier

    Début
        Afficher "Saisir du texte"
        Afficher "Saisissez du texte : "
        Saisir tabCar
        i <- 0
        Tant que tabCar(i) <> 0
            tabCarModif(i) <- tabCar(i)
            i <- i + 1
        tabCarModif(i) <- 0
    Fin
*/

void CIhmTableauCar::saisirTexte()
{
    short i;
    clear();
    color(12, 15);
    afficheCentre("Saisie du texte", 80, 1);
    color(0, 15);

    gotoxy(7, 5);
    cout << "Saisissez du texte : ";
    gets((char *)tabCar); //Saisie de tabCar
    for(i = 0; tabCar[i] != 0; i++) tabCarModif[i] = tabCar[i];
    tabCarModif[i] = 0;

    gotoxy(1, 1);
}

//----------------------------------------------------------------------------------------------

/*
        Algorithme de la méthode afficheCaracteresTexte() :
    Auteur : Kevin Doolaeghe
    Date : Décembre 2017

    Variables de la classe CIhmTableauCar :
        tabCar() = Tableau de 1024 caractères
        tabCarModif() = Tableau de 1024 caractères
    Variables :
        i = entier

    Début
        Afficher "Affichage des tableaux de caractères"
        Afficher "tabCar contient : ", tabCar
        Afficher "tabCarModif contient : ", tabCarModif
        Pour i allant de 0 à 19
            Si (i < 10)
                Alors   Appel de la procédure gotoxy(23, i + 11)
                Sinon   Appel de la procédure gotoxy(45, i + 1)
            Afficher i, " * "
            Afficher tabCarModif(i) en décimal, " * ", tabCarModif(i)
    Fin
*/

void CIhmTableauCar::afficheCaracteresTexte()
{
    //tabCarModif[3] = 'A';
    //Pour "bug", le caractère NULL est dans tabCarModif[3]. Il est donc remplacé par 'A'. Lors de l'affichage, il sera affiché chacun des caractères jusqu'à ce qu'il trouve le caractère 0.

    short i, j;
    clear();
    color(12, 15);
    afficheCentre("Affichage des tableaux de caract\x8ares", 80, 1);
    color(0, 15);
    //Affichage
    //tabCar
    gotoxy(17, 5);
    cout << "tabCar contient";
    gotoxy(40, 5);
    cout << ":";
    gotoxy(42, 5);
    puts((char *)tabCar); //Affiche tabCar
    //tabCarModif
    cout << endl;
    for(i = 0; i < 16; i++) cout << " ";
    cout << "tabCarModif contient";
    for(i = 0; i < 3; i++) cout << " ";
    cout << ": ";
    puts((char *)tabCarModif);
    //20 premiers caractères de tabCarModif
    cout << endl;
    for(i = 0; i < 16; i++) cout << " ";
    cout << "Les 20 premiers caract" << (char)138 << "res de tabCarModif sont :" << endl;
    //Tableau
    for(i = 0; i < 20; i++)
    {
        if(i < 10) cout << " ";
        for(j = 0; j < 35; j++) cout << " ";
        cout << i << " * " << tabCarModif[i] << " * " << (unsigned short)tabCarModif[i] << endl;
    }
    gotoxy(1, 1);
    getch();
}

//----------------------------------------------------------------------------------------------

//Exercice 2

/*
        Algorithme de la méthode supprimeEspace() :
    Auteur : Kevin Doolaeghe
    Date : Décembre 2017

    Variables de la classe CIhmTableauCar :
        tabCar() = Tableau de 1024 caractères
        tabCarModif() = Tableau de 1024 caractères
    Variables :
        i, nbEspaces = entier

    Début
        i <- 0
        nbEspaces <- 0
        Tant que tabCarModif(i) <> 0
            Si (tabCarModif(i) <> ' ')
                Alors   tabCarModif(i - nbEspaces) <- tabCarModif(i)
                Sinon   nbEspaces <- nbEspaces + 1
            i <- i + 1
        tabCarModif(i - nbEspaces) <- 0
    Fin
*/

void CIhmTableauCar::supprimeEspace()
{
    short i;
    short nbEspaces = 0;

    for(i = 0; tabCarModif[i] != 0; i++)
    {
        if(tabCarModif[i] != ' ') tabCarModif[i - nbEspaces] = tabCarModif[i];
        else nbEspaces++;
    }
    tabCarModif[i - nbEspaces] = 0;
}

//----------------------------------------------------------------------------------------------

//Exercice 3

/*
        Algorithme de la méthode miseEnMajuscule() :
    Auteur : Kevin Doolaeghe
    Date : Décembre 2017

    Variables de la classe CIhmTableauCar :
        tabCar() = Tableau de 1024 caractères
        tabCarModif() = Tableau de 1024 caractères
    Variables :
        i, nbCarSuppr = entiers

    Début
        nbCarSuppr <- 0
        i <- 0
        Tant que (tabCarModif(i) <> 0)
            Si (tabCarModif(i) >= 'a' et tabCarModif(i) <= 'z')
                Alors   tabCarModif(i) <-  tabCarModif(i) + 32
            Si (tabCarModif(i) = 'é' ou tabCarModif(i) = 'è' ou tabCarModif(i) = 'ë' ou tabCarModif(i) = 'ê')
                Alors   tabCarModif() <- 'E'
            Si (tabCarModif(i) = 'â' ou tabCarModif(i) = 'à' ou tabCarModif(i) = 'ä')
                Alors   tabCarModif() <- 'A'
            Si (tabCarModif(i) = 'î' ou tabCarModif(i) = 'ï')
                Alors   tabCarModif() <- 'I'
            ...
            i <- i + 1
    Fin
*/

void CIhmTableauCar::miseEnMajuscule()
{
    short i;
    short nbCarSuppr = 0;

    //Traîtement
    for(i = 0; tabCarModif[i] != 0; i++)
    {
        if(tabCarModif[i] >= 'a' && tabCarModif[i] <= 'z') tabCarModif[i - nbCarSuppr] = tabCarModif[i] & 0xdf;
        switch(tabCarModif[i])
        {
            case 130:
            case 136:
            case 137:
            case 138:
            case 144:
                tabCarModif[i] = 'E';
                break;
            case 131:
            case 132:
            case 133:
            case 134:
            case 142:
            case 143:
                tabCarModif[i] = 'A';
                break;
            case 139:
            case 140:
            case 141:
            case 161:
                tabCarModif[i] = 'I';
                break;
            case 147:
            case 148:
            case 149:
            case 153:
            case 155:
            case 146:
                tabCarModif[i] = 'O';
                break;
            case 129:
            case 150:
            case 151:
            case 154:
            case 163:
                tabCarModif[i] = 'U';
                break;
            case 128:
            case 135:
                tabCarModif[i] = 'C';
                break;
            case 145:
                tabCarModif[i] = (char)146;
                break;
            case 164:
            case 165:
                tabCarModif[i] = 'N';
                break;
            case 152:
                tabCarModif[i] = 'Y';
                break;
        }
    }
}

//----------------------------------------------------------------------------------------------

//Exercice 4

/*
        Algorithme de la méthode cryptageCerveau() :
    Auteur : Kevin Doolaeghe
    Date : Décembre 2017

    Variables de la classe CIhmTableauCar :
        tabCar() = Tableau de 1024 caractères
        tabCarModif() = Tableau de 1024 caractères
    Variables :
        i = entier

    Début
        Afficher "Cryptage de tabCarModif"
        Afficher "Phrase testée :", tabCar
        i <- 0
        Tant que (tabCar(i) <> 0)
            tabCarModif(i) <- tabCar(i)
            i <- i + 1
        tabCarModif(i) <- 0
        Appel de la procédure miseEnMajuscule()
        i <- 0
        Tant que (tabCarModif(i) <> 0)
            Si (tabCarModif(i) = 'O')
                Alors   tabCarModif(i) <- '0';
            Si (tabCarModif(i) = 'I')
                Alors   tabCarModif(i) <- '1';
            Si (tabCarModif(i) = 'Z')
                Alors   tabCarModif(i) <- '2';
            Si (tabCarModif(i) = 'E')
                Alors   tabCarModif(i) <- '3';
            Si (tabCarModif(i) = 'A')
                Alors   tabCarModif(i) <- '4';
            Si (tabCarModif(i) = 'S')
                Alors   tabCarModif(i) <- '5';
            Si (tabCarModif(i) = 'T')
                Alors   tabCarModif(i) <- '7';
            Si (tabCarModif(i) = 'B')
                Alors   tabCarModif(i) <- '8';
            Si (tabCarModif(i) = 'G')
                Alors   tabCarModif(i) <- '9';
            i <- i + 1
        Afficher "Voici la forme cryptée de tabCarModif : ", tabCarModif
    Fin
*/

void CIhmTableauCar::cryptageCerveau()
{
    short i = 0;

    clear();
    color(12, 15);
    afficheCentre("Cryptage de tabCarModif", 80, 1);
    color(0, 15);

    gotoxy(7, 5);
    cout << "Phrase test" << (char)130 << "e :   " << tabCar;
    //Copie tabCar dans tabCarModif
    while(tabCar[i] != 0)
    {
        tabCarModif[i] = tabCar[i];
        i++;
    }
    tabCarModif[i] = 0;

    //Traîtement
    miseEnMajuscule();
    for(i = 0; tabCarModif[i] != 0; i++) //Parcourt la chaine
    {
        switch(tabCarModif[i]) //Teste si tabCarModif(i) correspond à différentes valeurs
        {
        case 'O':
            tabCarModif[i] = '0';
            break; //Sort du switch
        case 'Z':
            tabCarModif[i] = '2';
            break;
        case 'I':
            tabCarModif[i] = '1';
            break;
        case 'E':
            tabCarModif[i] = '3';
            break;
        case 'A':
            tabCarModif[i] = '4';
            break;
        case 'S':
            tabCarModif[i] = '5';
            break;
        case 'T':
            tabCarModif[i] = '7';
            break;
        case 'B':
            tabCarModif[i] = '8';
            break;
        case 'G':
            tabCarModif[i] = '9';
            break;
        }
    }
    gotoxy(7, 7);
    cout << "Voici la forme crypt" << (char)130 << " de tabCarModif :"; //Affichage
    gotoxy(10, 10);
    cout << tabCarModif;

    gotoxy(1, 1);
    getch();
}

//----------------------------------------------------------------------------------------------

//Exercice 5

/*
        Algorithme de la méthode testPalindrome() :
    Auteur : Kevin Doolaeghe
    Date : Décembre 2017

    Variables de la classe CIhmTableauCar :
        tabCar() = Tableau de 1024 caractères
        tabCarModif() = Tableau de 1024 caractères
    Variables :
        i, longueur = entier
        testPal = booléen

    Début
        testPal <- 1
        i <- 0
        longueur <- 0
        Afficher "Test palindrome"
        miseEnMajuscule()
        supprimeEspace()
        Afficher "Phrase testée : ", tabCar
        Tant que (tabCarModif(longueur) <> 0)
            longueur <- longueur + 1
        longueur <- longueur - 1
        Tant que (i < longueur et testPal = 1)
            Si (tabCarModif(i) <> tabCarModif(longueur))
                Alors   testPal <- 0
            i <- i + 1
            longueur <- longueur - 1
        Si (testPal = 1)
            Alors   Afficher " est un palindrome"
            Sinon   Afficher " n'est pas un palindrome"
        Retourner testPal

    Fin
*/

bool CIhmTableauCar::testPalindrome()
{
    short i, longueur;
    bool testPal = 1;

    clear();
    color(12, 15);
    afficheCentre("Test palindrome", 80, 1);
    color(0, 15);

    //Initialisation de tabCarModif
    for(i = 0; tabCar[i] != 0; i++)
    {
        tabCarModif[i] = tabCar[i];
    }
    tabCarModif[i] = 0;
    miseEnMajuscule();

    //Supprime les caractères qui ne sont pas des lettres pour le test
    for(i = 0; tabCarModif[i] != 0; i++)
    {
        if(tabCarModif[i] < 'A' || tabCarModif[i] > 'Z') tabCarModif[i] = ' ';
    }
    supprimeEspace();

    //Calcul de la longueur
    for(longueur = 0; tabCarModif[longueur] != 0; longueur++);
    longueur--;
    //Boucle de vérification
    i = 0;
    while(i < longueur && testPal == 1)
    {
        if(tabCarModif[i] != tabCarModif[longueur]) testPal = 0;
        i++;
        longueur--;
    }
    //Test de vérification
    gotoxy(7, 5);
    cout << "\"" << tabCar << "\"";
    if(testPal == 1) cout << " est un palindrome :";
    else cout << " n'est pas un palindrome :";

    //Affichage des tests
    gotoxy(7, 7);
    cout << tabCarModif << " :";
    for(longueur = 0; tabCarModif[longueur] != 0; longueur++);
    longueur--;
    i = 0;
    while(i < longueur)
    {
        gotoxy(7, i + 9);
        cout << tabCarModif[i] << " - " << tabCarModif[longueur];
        i++;
        longueur--;
    }
    gotoxy(1, 1);
    getch();
    return testPal;
}

//----------------------------------------------------------------------------------------------

//Exercice 6

/*
        Algorithme de la méthode remplaceMot() :
    Auteur : Kevin Doolaeghe
    Date : Décembre 2017

    Variables de la classe CIhmTableauCar :
        tabCarModif() = Tableau de 1024 caractères
    Variables :
        motARemplacer(), motDeRemplacement() = Tableau de 25 caractères
        suiteTxt() = Tableau de 1000 caractères
        ptMot = pointeur de caractère

    Début
        Afficher "Remplacer une chaine"
        Afficher "Entrez la chaine à remplacer : "
        Saisir motARemplacer
        ptMot <- strstr(tabCarModif, motARemplacer)
        Si (ptMot <> 0)
            Alors   Afficher "Veuillez saisir la nouvelle chaine : "
                    Saisir motDeRemplacement
                    strcpy(suiteTxt, ptMot + strlen(motARemplacer))
                    *ptMot <- 0
                    strcat(tabCarModif, motDeRemplacement)
                    strcat(tabCarModif, suiteTxt)
            Sinon   Afficher "La chaine n'existe pas"
    Fin
*/

void CIhmTableauCar::remplaceMot()
{
    char motARemplacer[100], motDeRemplacement[100];
    char suiteTxt[1000];
    char *ptMot;

    clear();
    color(12, 15);
    afficheCentre("Remplace mot", 80, 1);
    color(0, 15);

    gotoxy(7, 5);
    cout << "Entrez la chaine " << (char)133 << " remplacer : ";
    cin >> motARemplacer;
    gotoxy(7, 7);
    ptMot = strstr((char *)tabCarModif, motARemplacer);
    if(ptMot != 0)
    {
        cout << "Veuillez saisir le nouveau mot : ";
        cin >> motDeRemplacement;

        while((ptMot = strstr((char *)tabCarModif, motARemplacer)))
        {
            strcpy(suiteTxt, ptMot + strlen(motARemplacer));
            *ptMot = 0;
            strcat((char *)tabCarModif, motDeRemplacement);
            strcat((char *)tabCarModif, suiteTxt);
        }

        gotoxy(7, 9);
        cout << ">> " << tabCarModif;
    }
    else cout << "Le mot n'existe pas";

    gotoxy(1, 1);
    getch();
}

//----------------------------------------------------------------------------------------------

//Exercice 7

/*
        Algorithme de la méthode decomposeTexte() :
    Auteur : Kevin Doolaeghe
    Date : Décembre 2017

    Variables de la classe CIhmTableauCar :
        tabCar() = Tableau de 1024 caractères
        tabCarModif() = Tableau de 1024 caractères
        tabMot() = Tableau de 100 * 25 caractères
    Variables :
        i, j, posChaine bufferActif, longueur, nbLettre, nbChiffre, nbMot = entier

    Début
        longueur <- 0
        nbLettre <- 0
        nbChiffre <- 0
        nbMot <- 0
        bufferActf <- 0
        Afficher "Décomposition du texte"
        Afficher "Phrase testée :", tabCar
        i <- 0
        Tant que tabCar(i) <> 0)
            tabCarModif(i) <- tabCar(i)
            longueur <- longueur + 1
            Si ((tabCar(i) >= 'a' et tabCar(i) <= 'z') ou (tabCar(i) >= 'A' et tabCar(i) <= 'Z'))
                Alors   nbLettre <- nbLettre + 1
            Si (tabCar(i) >= '0' et tabCar(i) <= '9')
                Alors   nbChiffre <- nbChiffre + 1
            i <- i + 1
        tabCarModif(i) <- 0
        Pour i allant de 0 à 99
            Pour j allant de 0 à 24
                tabMot(i)(j) <- 0
        i<- 0
        Tant que (tabCar(i) <> 0)
            Si (tabCar(i) <> 32)
                Alors   Si (bufferActif = 0)
                            Alors   posChaine = 0
                        tabMot(nbMot)(posChaine) <- tabCar(i)
                        bMot <- nbMot + 1
                        bufferActif <- 1
            Si (tabCar(i) = 32 et bufferActif = 1)
                Alors   tabMot(nbMot)(posChaine) <- 0
                        nbMot <- nbMot + 1
                        bufferActif <- 0
            i <- i + 1
        tabMot(nbMot)(posChaine) <- 0
        miseEnMajuscule()
        Afficher "Nombre de caractères : ", longueur
        Afficher "Phrase en majuscules : ", tabCarModif
        Afficher "Nombre de lettres : ", nbLettre
        Afficher "Nombre de chiffres : ", nbChiffre
        Afficher "Nombre de mots : ", nbMot
        Afficher "Liste des mots :"
        i <- 0
        j <- 0
        Tant que (tabMot(i)(0) <> 0 et i < 100)
            Afficher "[", i, "] "
            Tant que (tabMot(i)(j) <> 0 et j < 25)
                Afficher tabMot(i)(j)
                j <- j + 1
            Aller à la ligne
            i <- i + 1
    Fin
*/

void CIhmTableauCar::decomposeTexte()
{
    short i, j, posChaine;
    short longueur = 0;
    short nbLettre = 0;
    short nbChiffre = 0;
    short nbMot = 0;
    bool bufferActif = false;

    clear();
    color(12, 15);
    afficheCentre("D\x82composition du texte", 80, 1);
    color(0, 15);

    gotoxy(7, 7);
    cout << "Phrase test" << (char)130 << "e : " << tabCar << "\n\n";
    //Traîtement
    //Compte le nombre de caractères, de lettres et de chiffre et copie tabCar dans tabCarModif
    for(i = 0; tabCar[i] != 0; i++)
    {
        tabCarModif[i] = tabCar[i];
        longueur++;
        if((tabCar[i] >= 'a' && tabCar[i] <= 'z') || (tabCar[i] >= 'A' && tabCar[i] <= 'Z')) nbLettre++;
        if(tabCar[i] >= '0' && tabCar[i] <= '9') nbChiffre++;
    }
    tabCarModif[i] = 0;

    //Initialisation de tabMot
    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 25; j++) tabMot[i][j] = 0;
    }

    //Compte et stocke les mots de la chaine
    for(i = 0; tabCar[i] != 0; i++)
    {
        if(tabCar[i] != 32) //Si c'est un mot
        {
            if(bufferActif == false) posChaine = 0;

            tabMot[nbMot][posChaine] = tabCar[i];
            posChaine++;
            bufferActif = true;
        }
        if(tabCar[i] == 32 && bufferActif == true) //Si c'est la fin d'un mot
        {
            tabMot[nbMot][posChaine] = 0;
            nbMot++;
            bufferActif = false;
        }
    }
    tabMot[nbMot][posChaine] = 0;

    //Mise en majuscules
    miseEnMajuscule();

    //AFFICHAGE
    //Nombre de caractères
    for(i = 0; i < 6; i++) cout << " ";
    cout << "Nombre de caract" << (char)138 << "res : " << longueur << "\n\n";

    //Majuscules
    for(i = 0; i < 6; i++) cout << " ";
    cout << "Phrase en majuscules : " << tabCarModif << "\n\n";

    //Nombre de lettres
    for(i = 0; i < 6; i++) cout << " ";
    cout << "Nombre de lettres : " << nbLettre << "\n\n";

    //Nombre de chiffres
    for(i = 0; i < 6; i++) cout << " ";
    cout << "Nombre de chiffres : " << nbChiffre << "\n\n";

    //Nombre de mots
    for(i = 0; i < 6; i++) cout << " ";
    cout << "Nombre de mots : " << nbMot + 1 << "\n\n";

    //Liste des mots
    for(i = 0; i < 6; i++) cout << " ";
    cout << "Liste des mots :\n\n";
    for(i = 0; tabMot[i][0] != 0 && i < 100; i++)
    {
        for(j = 0; j < 35; j++) cout << " ";
        cout << "[" << i << "] ";
        for(j = 0; tabMot[i][j] != 0 && j < 25; j++) cout << tabMot[i][j];
        cout << endl;
    }

    //Fin
    gotoxy(1, 1);
    getch();
}
