#include "cihmagenda.h"

//----------------------------------------------------------------------------------------------

//Constructeur

CIhmAgenda::CIhmAgenda()
{
    short i;
    for(i = 6; i < NB_CONTACT; i++)
    {
        agenda[i].nom[0] = 0;
        agenda[i].prenom[0] = 0;
    }
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

void CIhmAgenda::menu(short nbProp)
{
    //Initialisation
    char touche1, touche2;
    static short selection = 1;
    short i;
    color(0, 15); //system("color 0f");
    //system ("mode con cols=80 lines=25");
    do
    {
        //Affichage du titre
        clear();
        color(12, 15);
        afficheCentre("Menu Principal", 80, 1);
        color(0, 15);
        gotoxy(32, 4);
        cout << "Doolaeghe  Kevin";

        //Affichage des propositions
        gotoxy(10, 6);
        cout << "Visualiser l'ensemble des coordonn" << (char)130 << "es";
        gotoxy(10, 8);
        cout << "Ajouter un nom dans le r\x82pertoire";
        gotoxy(10, 10);
        cout << "Supprimer un nom dans le r\x82pertoire";
        gotoxy(10, 12);
        cout << "Rechercher une adresse par nom ou par pr\x82nom";
        gotoxy(10, 14);
        cout << "Rechercher un nom par ville";
        gotoxy(10, 16);
        cout << "Modifier un \x82l\x82ment dans le r\x82pertoire";

        //Affichage de l'option pour quitter
        gotoxy(10, nbProp * 2 + 6);
        color(15, 12);
        cout << "Quitter";
        color(0, 15);

        do //Boucle de décalage du curseur selon le choix
        {
            //Effacage du curseur
            for(i = 6; i < nbProp * 2 + 8; i++)
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
                afficheRepertoire();
                break;
            case 2:
                ajoutElement();
                break;
            case 3:
                retireElement();
                break;
            case 4:
                rechercheNomPrenom();
                break;
            case 5:
                rechercheVille();
                break;
            case 6:
                modifieElement();
                break;
        }
    } while(selection != nbProp + 1); //Quitter
}

//----------------------------------------------------------------------------------------------

//Affichage du répertoire

/*
        Algorithme de la méthode afficheRepertoire() de la classe CIhmAgenda :
    Auteur : Kevin Doolaeghe
    Date : Janvier 2018

    Variables :
        i, j, numLigne = entiers
        touche = caractère
        echap = booléen

    Variable de la classe CIhmAgenda :
        agenda = Tableau de 200 dataContact

    Début
        numLigne <- 8
        echap <- 0
        Effacer l'écran
        Afficher "Afficher le répertoire"
        Lancer la procédure gotoxy(3, 5)
        Afficher "Nom"
        Lancer la procédure gotoxy(21, 5)
        Afficher "Prénom"
        Lancer la procédure gotoxy(35, 5)
        Afficher "Adresse"
        Lancer la procédure gotoxy(66, 5)
        Afficher "n° Tel. dom."
        Lancer la procédure gotoxy(3, 6)
        Afficher "Email"
        Lancer la procédure gotoxy(35, 6)
        Afficher "CP - Ville"
        Lancer la procédure gotoxy(66, 6)
        Afficher "n° Tel. por."
        Lancer la procédure gotoxy(1, 7)
        Pour i allant de 0 à 79
            Afficher "="
        i <- 0
        Tant que (i < 200 et echap = 0)
            Si (agenda(i).nom(0) <> 0 ou agenda(i).prenom(0) <> 0)
                Alors   Lancer la procédure gotoxy(3, numLigne);
                        Afficher agenda(i).nom;
                        Lancer la procédure gotoxy(21, numLigne);
                        Afficher agenda(i).prenom;
                        Lancer la procédure gotoxy(35, numLigne);
                        Afficher agenda(i).adresse;
                        Lancer la procédure gotoxy(66, numLigne);
                        Afficher agenda(i).telDomicile;
                        Lancer la procédure gotoxy(3, numLigne + 1);
                        Afficher agenda(i).email;
                        Lancer la procédure gotoxy(35, numLigne + 1);
                        Afficher agenda(i).codePostale;
                        Lancer la procédure gotoxy(42, numLigne + 1);
                        Afficher agenda(i).ville;
                        Lancer la procédure gotoxy(66, numLigne + 1);
                        Afficher agenda(i).telPortable;
                        Lancer la procédure gotoxy(1, numLigne + 2);
                        Pour j allant de 0 à 79
                            Afficher "-"
                        Lancer la procédure gotoxy(1, 1);
                        numLigne <- numLigne + 3
                        Si (numLigne = 23)
                            Alors   touche <- Lancer la procédure getch()
                                    Si (touche = 27)
                                        Alors   echap <- 1
                                                Pour j allant de 8 à 22
                                                    Lancer la procédure gotoxy(1, j)
                                                    Afficher "                                                                                "
                                    numLigne <- 8
        Si (echap = 0 et numLigne <> 8)
            Alors   Lancer la procédure getch()
    Fin
*/

void CIhmAgenda::afficheRepertoire()
{
    short i, j, numLigne = 8;
    char touche;
    bool echap = false;

    //Affichage des contacts
    clear();
    color(12, 15);
    afficheCentre("Afficher le r\x82pertoire", 80, 1);
    color(0, 15);

    gotoxy(3, 5);
    cout << "Nom";
    gotoxy(21, 5);
    cout << "Pr\x82nom";
    gotoxy(35, 5);
    cout << "Adresse";
    gotoxy(66, 5);
    cout << "n" << (char)248 << " Tel. dom.";

    gotoxy(3, 6);
    cout << "Email";
    gotoxy(35, 6);
    cout << "CP - Ville";
    gotoxy(66, 6);
    cout << "n" << (char)248 << " Tel. por.";

    gotoxy(1, 7);
    for(i = 0; i < 80; i++) cout << "=";

    for(i = 0; i < NB_CONTACT && echap == false; i++)
    {
        if(agenda[i].nom[0] != 0 || agenda[i].prenom[0] != 0)
        {
            //Affichage
            color(9, 15);
            gotoxy(3, numLigne);
            cout << agenda[i].nom;
            gotoxy(21, numLigne);
            cout << agenda[i].prenom;
            gotoxy(35, numLigne);
            cout << agenda[i].adresse;
            gotoxy(66, numLigne);
            cout << agenda[i].telDomicile;

            gotoxy(3, numLigne + 1);
            cout << agenda[i].email;
            gotoxy(35, numLigne + 1);
            cout << agenda[i].codePostale;
            gotoxy(42, numLigne + 1);
            cout << agenda[i].ville;
            gotoxy(66, numLigne + 1);
            cout << agenda[i].telPortable;

            color(0, 15);
            gotoxy(1, numLigne + 2);
            for(j = 0; j < 80; j++) cout << "-";
            gotoxy(1, 1);

            //Calcul de la ligne où copier
            numLigne += 3;

            if(numLigne == 23)
            {
                touche = getch();
                if(touche == 27) echap = true;

                //Effacer le bas de l'écran
                for(j = 8; j < 23; j++)
                {
                    gotoxy(1, j);
                    cout << "                                                                                ";
                }

                numLigne = 8;
            }
        }
    }
    gotoxy(1, 1);
    if(echap == false && numLigne != 8) getch();
}

//----------------------------------------------------------------------------------------------

//Ajout

void CIhmAgenda::ajoutElement()
{
    short i = 0;

    clear();
    color(12, 15);
    afficheCentre("Ajout d'un \x82l\x82ment", 80, 1);
    color(0, 15);

    //Trouve un emplacement valide de l'agenda
    while(i < NB_CONTACT && (agenda[i].nom[0] != 0 || agenda[i].prenom[0] != 0)) i++;
    if(i != NB_CONTACT) //Saisie
    {
        //Nom
        gotoxy(15, 7);
        cout << "Nom : ";
        cin.getline(agenda[i].nom, 15);
        cout << endl << agenda[i].nom;

        //Prénom
        gotoxy(15, 9);
        cout << "Pr\x82nom : ";
        cin.getline(agenda[i].prenom, 16);

        //Adresse
        gotoxy(15, 11);
        cout << "Adresse : ";
        cin.getline(agenda[i].adresse, 31);

        //Ville
        gotoxy(15, 13);
        cout << "Ville : ";
        cin.getline(agenda[i].ville, 21);

        //Code postale
        gotoxy(15, 15);
        cout << "Code postale : ";
        cin.getline(agenda[i].codePostale, 6);

        //Email
        gotoxy(15, 17);
        cout << "Adresse Email : ";
        cin.getline(agenda[i].email, 31);

        //n° Tel. domicile
        gotoxy(15, 19);
        cout << "n" << (char)248 << " de t\x82l\x82phone du domicile : ";
        cin.getline(agenda[i].telDomicile, 11);

        //n° Tel. portable
        gotoxy(15, 21);
        cout << "n" << (char)248 << " de t\x82l\x82phone portable : ";
        cin.getline(agenda[i].telPortable, 11);

        gotoxy(29, 23);
        cout << "Le contact a \x82t\x82 ajout\x82";
    }
    else //Répertoire plein
    {
        gotoxy(29, 12);
        cout << "Le r\x82pertoire est plein";
    }

    gotoxy(1, 1);
    getch();
}

//----------------------------------------------------------------------------------------------

//Suppression

void CIhmAgenda::retireElement()
{
    short i, nbSuppr = 0;

    clear();
    color(12, 15);
    afficheCentre("Retirer un \x82l\x82ment", 80, 1);
    color(0, 15);

    //Saisie
    gotoxy(5, 5);
    cout << "Entrez le nom du contact \x85 supprimer : ";
    gets(data.nom);
    gotoxy(9, 7);
    cout << "Le pr\x82nom du contact \x85 supprimer : ";
    gets(data.prenom);

    //Recherche
    for(i = 0; i < NB_CONTACT; i++)
    {
        if(!strcmpi(agenda[i].nom, data.nom) && !strcmpi(agenda[i].prenom, data.prenom))
        {
            agenda[i].nom[0] = 0;
            agenda[i].prenom[0] = 0;
            nbSuppr++;
        }
    }

    switch(nbSuppr)
    {
        case 0:
            gotoxy(25, 10);
            cout << "Aucun contact n'a \x82t\x82 supprim\x82.";
            break;
        case 1:
            gotoxy(27, 10);
            cout << "Le contact a \x82t\x82 supprim\x82.";
            break;
        default:
            gotoxy(24, 10);
            cout << nbSuppr << " contacts ont \x82t\x82 supprim\x82.";
    }

    gotoxy(1, 1);
    getch();
}

//----------------------------------------------------------------------------------------------

//Recherche par nom ou prénom

void CIhmAgenda::rechercheNomPrenom()
{
    short i, j, numLigne = 8, nbAff = 0;
    bool echap = false;
    char touche;

    clear();
    color(12, 15);
    afficheCentre("Recherche par nom ou par pr\x82nom", 80, 1);
    color(0, 15);

    //Saisie
    gotoxy(15, 6);
    cout << "Entrez le nom du contact : ";
    gets(data.nom);
    gotoxy(12, 8);
    cout << "Entrez le pr" << (char)130 << "nom du contact : ";
    gets(data.prenom);

    //Affichage
    clear();
    color(12, 15);
    afficheCentre("Recherche par nom ou par pr\x82nom", 80, 1);
    color(0, 15);

    gotoxy(3, 5);
    cout << "Nom";
    gotoxy(21, 5);
    cout << "Pr\x82nom";
    gotoxy(35, 5);
    cout << "Adresse";
    gotoxy(66, 5);
    cout << "n" << (char)248 << " Tel. dom.";

    gotoxy(3, 6);
    cout << "Email";
    gotoxy(35, 6);
    cout << "CP - Ville";
    gotoxy(66, 6);
    cout << "n" << (char)248 << " Tel. por.";

    gotoxy(1, 7);
    for(i = 0; i < 80; i++) cout << "=";

    for(i = 0; i < NB_CONTACT && echap == false; i++) //Parcourt le répertoire
    {
        if((!strcmpi(agenda[i].nom, data.nom) || !strcmpi(agenda[i].prenom, data.prenom)) && (agenda[i].nom[0] != 0 || agenda[i].prenom[0] != 0)) //Si trouve un contact avec le nom ou le prénom
        {
            nbAff++; //Un contact trouvé
            //Affichage
            color(9, 15);
            gotoxy(3, numLigne);
            cout << agenda[i].nom;
            gotoxy(21, numLigne);
            cout << agenda[i].prenom;
            gotoxy(35, numLigne);
            cout << agenda[i].adresse;
            gotoxy(66, numLigne);
            cout << agenda[i].telDomicile;

            gotoxy(3, numLigne + 1);
            cout << agenda[i].email;
            gotoxy(35, numLigne + 1);
            cout << agenda[i].codePostale;
            gotoxy(42, numLigne + 1);
            cout << agenda[i].ville;
            gotoxy(66, numLigne + 1);
            cout << agenda[i].telPortable;

            color(0, 15);
            gotoxy(1, numLigne + 2);
            for(j = 0; j < 80; j++) cout << "-";
            gotoxy(1, 1);

            //Calcul de la ligne où copier
            numLigne += 3;

            if(numLigne == 23)
            {
                touche = getch(); //Choix
                if(touche == 27) echap = true; //Quitter

                //Effacer le bas de l'écran
                for(j = 8; j < 23; j++)
                {
                    gotoxy(1, j);
                    cout << "                                                                                ";
                }

                numLigne = 8;
            }
        }
    }
    gotoxy(1, 1);
    if(echap == false && numLigne != 8) getch(); //Fin affichage
    if(nbAff == 0) //Rien trouvé
    {
        clear();
        color(12, 15);
        afficheCentre("Recherche par nom ou par pr\x82nom", 80, 1);
        color(0, 15);
        gotoxy(30, 15);
        cout << "Aucun contact trouv\x82";
        getch();
    }
}

//----------------------------------------------------------------------------------------------

//Recherche par ville

void CIhmAgenda::rechercheVille()
{
    short i, j, numLigne = 8, nbAff = 0;
    bool echap = false;
    char touche;

    clear();
    color(12, 15);
    afficheCentre("Rechercher un nom par ville", 80, 1);
    color(0, 15);

    //Saisie
    gotoxy(15, 6);
    cout << "Entrez le nom de la ville : ";
    gets(data.ville);

    //Affichage
    clear();
    color(12, 15);
    afficheCentre("Rechercher un nom par ville", 80, 1);
    color(0, 15);

    gotoxy(3, 5);
    cout << "Nom";
    gotoxy(21, 5);
    cout << "Pr\x82nom";
    gotoxy(35, 5);
    cout << "Adresse";
    gotoxy(66, 5);
    cout << "n" << (char)248 << " Tel. dom.";

    gotoxy(3, 6);
    cout << "Email";
    gotoxy(35, 6);
    cout << "CP - Ville";
    gotoxy(66, 6);
    cout << "n" << (char)248 << " Tel. por.";

    gotoxy(1, 7);
    for(i = 0; i < 80; i++) cout << "=";

    for(i = 0; i < NB_CONTACT && echap == false; i++) //Parcourt le répertoire
    {
        if(!strcmpi(agenda[i].ville, data.ville) && (agenda[i].nom[0] != 0 || agenda[i].prenom[0] != 0)) //Si le contact avec le nom de ville existe
        {
            nbAff++; //un contact trouvé
            //Affichage
            color(9, 15);
            gotoxy(3, numLigne);
            cout << agenda[i].nom;
            gotoxy(21, numLigne);
            cout << agenda[i].prenom;
            gotoxy(35, numLigne);
            cout << agenda[i].adresse;
            gotoxy(66, numLigne);
            cout << agenda[i].telDomicile;

            gotoxy(3, numLigne + 1);
            cout << agenda[i].email;
            gotoxy(35, numLigne + 1);
            cout << agenda[i].codePostale;
            gotoxy(42, numLigne + 1);
            cout << agenda[i].ville;
            gotoxy(66, numLigne + 1);
            cout << agenda[i].telPortable;

            color(0, 15);
            gotoxy(1, numLigne + 2);
            for(j = 0; j < 80; j++) cout << "-";
            gotoxy(1, 1);

            //Calcul de la ligne où copier
            numLigne += 3;

            if(numLigne == 23)
            {
                touche = getch(); //Choix
                if(touche == 27) echap = true; //Quitter

                //Effacer le bas de l'écran
                for(j = 8; j < 23; j++)
                {
                    gotoxy(1, j);
                    cout << "                                                                                ";
                }

                numLigne = 8;
            }
        }
    }
    gotoxy(1, 1);
    if(echap == false && numLigne != 8) getch(); //Fin affichage
    if(nbAff == 0) //Rien trouvé
    {
        clear();
        color(12, 15);
        afficheCentre("Rechercher un nom par ville", 80, 1);
        color(0, 15);
        gotoxy(30, 15);
        cout << "Aucun contact trouv\x82";
        getch();
    }
}

//----------------------------------------------------------------------------------------------

//Modification

void CIhmAgenda::modifieElement()
{
    short i, j;
    bool sortie = false;
    char touche;

    //Affichage
    clear();
    color(12, 15);
    afficheCentre("Modifier un \x82l\x82ment", 80, 1);
    color(0, 15);

    gotoxy(3, 5);
    cout << "Nom";
    gotoxy(21, 5);
    cout << "Pr\x82nom";
    gotoxy(35, 5);
    cout << "Adresse";
    gotoxy(66, 5);
    cout << "n" << (char)248 << " Tel. dom.";

    gotoxy(3, 6);
    cout << "Email";
    gotoxy(35, 6);
    cout << "CP - Ville";
    gotoxy(66, 6);
    cout << "n" << (char)248 << " Tel. por.";

    gotoxy(1, 7);
    for(i = 0; i < 80; i++) cout << "=";

    for(i = 0; i < NB_CONTACT && sortie == false; i++) //Parcourt tous les contacts
    {
        if(agenda[i].nom[0] != 0 || agenda[i].prenom[0] != 0) //Si le contact existe
        {
            //Affichage
            color(9, 15);
            gotoxy(3, 8);
            cout << agenda[i].nom;
            gotoxy(21, 8);
            cout << agenda[i].prenom;
            gotoxy(35, 8);
            cout << agenda[i].adresse;
            gotoxy(66, 8);
            cout << agenda[i].telDomicile;

            gotoxy(3, 9);
            cout << agenda[i].email;
            gotoxy(35, 9);
            cout << agenda[i].codePostale;
            gotoxy(42, 9);
            cout << agenda[i].ville;
            gotoxy(66, 9);
            cout << agenda[i].telPortable;

            color(0, 15);
            gotoxy(1, 10);
            for(j = 0; j < 80; j++) cout << "-";
            gotoxy(1, 1);

            //Propositions
            gotoxy(10, 12);
            color(12, 15);
            cout << "Appuyez sur la touche :";
            gotoxy(35, 12);
            cout << "- espace pour modifier le contact";
            gotoxy(35, 13);
            cout << "- entr" << (char)130 << "e pour voir le contact suivant";

            gotoxy(1, 1);
            touche = getch();
            switch(touche) //Action selon la touche
            {
                case 32:
                    //Modifier
                    color(0, 15);

                    //Nom
                    gotoxy(15, 15);
                    cout << "Nom : ";
                    gets(agenda[i].nom);

                    //Prénom
                    gotoxy(15, 16);
                    cout << "Pr\x82nom : ";
                    gets(agenda[i].prenom);

                    //Adresse
                    gotoxy(15, 17);
                    cout << "Adresse : ";
                    gets(agenda[i].adresse);

                    //Ville
                    gotoxy(15, 18);
                    cout << "Ville : ";
                    gets(agenda[i].ville);

                    //Code postale
                    gotoxy(15, 19);
                    cout << "Code postale : ";
                    gets(agenda[i].codePostale);

                    //Email
                    gotoxy(15, 20);
                    cout << "Adresse Email : ";
                    gets(agenda[i].email);

                    //n° Tel. domicile
                    gotoxy(15, 21);
                    cout << "n" << (char)248 << " de t\x82l\x82phone du domicile : ";
                    gets(agenda[i].telDomicile);

                    //n° Tel. portable
                    gotoxy(15, 22);
                    cout << "n" << (char)248 << " de t\x82l\x82phone portable : ";
                    gets(agenda[i].telPortable);

                    gotoxy(29, 24);
                    cout << "Le contact a \x82t\x82 modifi\x82";

                    gotoxy(1, 1);
                    getch();
                    sortie = true;
                    break;
                case 13:
                    gotoxy(1, 8);
                    for(j = 0; j < 4; j++) cout << "                                                                                " << endl;
                    break;
                default:
                    sortie = true;
                    break;
            }
        }
    }
}
