#include "cihmboucle.h"


//------------------------------------------------------------------------------------------


//Constructeur :

CIhmBoucle::CIhmBoucle()
{

}


//------------------------------------------------------------------------------------------


//Menu :

/*
        Algorithme de la méthode menu() de la classe CIhmBoucle() :
    Auteur : Delvarre
    Date : Septembre 2017

    Variables :
        code = caractère

    Début
        Répéter
                {
                        //Afficher le menu
                        ...
                        Saisir code
                        Si (code = 'a' ou code = 'A' ou code = '1')
                                    Alors Appel de la méthode calculSPM()
                        Si (code = 'b' ou code = 'B' ou code = '2')
                                    Alors Appel de la méthode calculDivisionParSoustraction()
                        ...
                        Si (code = 'e' ou code = 'E' ou code = '5')
                                    Alors Appel de la méthode tableMultiplication()
                } Jusqu'à (code = 'q' ou code = 'Q')
    Fin
*/

void CIhmBoucle::menu()
{
    char code;
    do
    {
        system("cls");
        cout << "\t  TP 3 : 5 exercices pour mettre en oeuvres des boucles en C++\n";
        cout << "\t ==============================================================\n";
        cout << "\t                      Doolaeghe Kevin\n\n";
        cout << "a. Exercice 1 - Calcul de la somme, du produit et de la moyenne\n\n";
        cout << "b. Exercice 2 - Division par soustractions successives\n\n";
        cout << "c. Exercice 3 - Calcul de factorielle d'un entier\n\n";
        cout << "d. Exercice 4 - Afficher un triangle isocele forme d'etoiles\n\n";
        cout << "e. Exercice 5 - Afficher la table des produits pour N allant de 0 a 10\n\n";
        cout << "q. Quitter\n\n";
        cout << "Selectionnez a, b, c, d, e ou q : ";
        code = getch();
        if(code == 'a' || code == 'A' || code == '1') calculSTD();
        if(code == 'b' || code == 'B' || code == '2') calculDivisionParSoustraction();
        if(code == 'c' || code == 'C' || code == '3') calculFactorielle();
        if(code == 'd' || code == 'D' || code == '4') triangleIsocele();
        if(code == 'e' || code == 'E' || code == '5') tableMultiplication();
    } while(code != 'q' && code != 'Q');
}


//------------------------------------------------------------------------------------------


//Exercice 1 :

/*
        Algorithme de la méthode calculSTD() de la classe CIhmBoucle() :
    Auteur : Doolaeghe Kevin
    Date : Octobre 2017

    Variables :
        compteur, n, valeur = entiers
        somme = entier 64 bits
        produit = entier 128 bits

    Début
        Afficher "Exercice 1 - Calcul d'une somme, d'un produit et d'une moyenne"
        Afficher "Entrez le nombre de valeurs que vous souhaitez entrer : "
        Répéter
            Saisie n
        Jusqu'à (n > 0 et n < 255)
        Répéter
            Afficher "Nombre ", compteur, " : "
            Répéter
                Saisie valeur
            Jusqu'à (valeur < 16000 et valeur > -16000)
            somme <- somme + valeur
            produit <- produit * valeur
            compteur <- compteur + 1
        Jusqu'à (compteur > n)
        Afficher "Resultat de la somme des ", n, " valeurs : ", somme
        Afficher "Resultat du produit des ", n, de " valeurs : ", produit
        Afficher "Resultat de la moyenne des ", n, " valeurs : ", somme / n qui est un nombre à virgule
    Fin
*/

void CIhmBoucle::calculSTD()
{
    //Initialisation
    float n, valeur;
    int compteur = 1;
    double somme = 0;
    long double produit = 1;

    //Présentation
    system("cls");
    cout << "\tExercice 1 - Calcul d'une somme, d'un produit et d'une moyenne\n\n"; //Titre

    //Question
    cout << "Entrez le nombre de valeurs que vous souhaitez entrer : ";
    do //Boucle de vérification de la valeur
    {
        cin >> n;
        if(n < 0 || n != (int)n || n >= 255) //Affichage des erreurs
        {
            cout << "\nErreur(s) :";
            if(n >= 255) cout << "\n\t- Le nombre doit etre inferieur a 255";
            if(n < 0) cout << "\n\t- Le nombre doit etre positif";
            if(n != (int)n) cout << "\n\t- Le nombre doit etre un entier";
            cout << (char)7 << (char)7 << (char)7 << "\n\t\tRecommencez : ";
        } //Fin affichage des erreurs
    } while(n < 0 || n != (int)n || n >= 255);

    //Traîtement
    do //Boucle calculant au fur et à mesure la somme et le produit
    {
        cout << "\nNombre " << compteur << " : ";
        do //Boucle de vérification
        {
            cin >> valeur; //Demande la valeur
            if(valeur != (int)valeur || (int)valeur < -16000 || (int)valeur > 16000) //Affichage des erreurs
            {
                cout << "\nErreur(s) :";
                if(valeur < -16000 || valeur > 16000) cout << "\n\t- Le nombre doit etre compris entre -16000 et 16000";
                if(valeur != (int)valeur) cout << "\n\t- Le nombre doit etre un entier";
                cout << (char)7 << (char)7 << (char)7 << "\n\t\tRecommencez : ";
            } //Fin affichage des erreurs
        } while(valeur != (int)valeur || (int)valeur < -16000 || (int)valeur > 16000);
        somme += valeur; //Somme
        produit *= valeur; //Produit
        compteur++; //Incrémentation
    } while(compteur <= n);

    //Affichage
    cout << "\n\nResultat de la somme des " << n << " valeurs : " << somme << "\n"; //Affiche les résultats
    cout << "Resultat du produit des " << n << " valeurs : " << produit << "\n";
    cout << "Resultat de la moyenne des " << n << " valeurs : " << (float) somme / n << "\n\n";

    system("pause");
}


//------------------------------------------------------------------------------------------


//Exercice 2 :

/*
        Algorithme de la méthode calculDivisionParSoustraction() de la classe CIhmBoucle() :
    Auteur : Doolaeghe Kevin
    Date : Octobre 2017

    Variables :
        numerateur, denominateur, resultat, reste, compteur, diviseur = entiers
        signe = caractère

    Début
        Afficher "Exercice 2 - Calcul d'une division par soustractions"
        dividende <- 0
        compteur <- 1
        signe <- 0
        Afficher "Entrez la valeur du numerateur : "
        Répéter
            Saisie numerateur
        Jusqu'à (numerateur > -16000 et numerateur < 16000)
        Afficher "Entrez la valeur du denominateur : "
        Répéter
                    Saisie denominateur
        Jusqu'à (denominateur <> 0 et denominateur > -16000 et denominateur < 16000)
        Si ((denominateur > 0 et numerateur < 0) ou (denominateur < 0 et numerateur < 0))
                    Alors signe <- '-'
        Si (numerateur < 0)
                    Alors reste <- -numerateur
                    Sinon reste <- numerateur
        Si (denominateur < 0)
                    Alors diviseur <- -denominateur
                    Sinon diviseur <- denominateur
        Tant que (reste >= diviseur)
                    reste <- reste - diviseur
                    resultat <- resultat + 1
                    compteur <- compteur + 1
        Afficher "Le resultat de ", numerateur, " / ", denominateur, " est : ", resultat
        Afficher "Le reste de ", numerateur, " / ", denominateur, " est : ", reste
    Fin
*/

void CIhmBoucle::calculDivisionParSoustraction()
{
    //Initialisation
    float numerateur, denominateur;
    int reste, diviseur;
    int resultat = 0;
    int compteur = 1;
    char signe = 0;

    //Titre
    system("cls");
    cout << "\tExercice 2 - Calcul d'une division par soustractions\n\n";

    //Questions
    cout << "Entrez la valeur du numerateur : "; //Saisie du numérateur
    do //Boucle de vérification
    {
        cin >> numerateur;
        if(numerateur != (int)numerateur || numerateur < -16000 || numerateur > 16000) //Affichage des erreurs
        {
            cout << "\nErreur(s) :";
            if(numerateur != (int)numerateur) cout << "\n\t- Le nombre entre n'est pas un entier";
            if(numerateur < -16000 || numerateur > 16000) cout << "\n\t- Le nombre doit etre compris entre -16000 et 16000";
            cout << (char)7 << (char)7 << (char)7 << "\n\t\tRecommencez : ";
        } //Fin affichage des erreurs
    } while(numerateur != (int)numerateur || numerateur < -16000 || numerateur > 16000);

    //Deuxième question
    cout << "\nEntrez la valeur du denominateur : ";
    do //Boucle de vérification
    {
        cin >> denominateur;
        if(denominateur == 0 || denominateur != (int)denominateur || denominateur < -16000 || denominateur > 16000) //Affichage des erreurs
        {
            cout << "\nErreur(s) :";
            if(denominateur == 0) cout << "\n\t- Division par 0 impossible,";
            if(denominateur =! (int)denominateur) cout << "\n\t- Le nombre entre n'est pas un entier,";
            if(denominateur < -16000 || denominateur > 16000) cout << "\n\t- Le nombre doit etre compris entre -16000 et 16000,";
            cout << (char)7 << (char)7 << (char)7 << "\n\t\tRecommencez : ";
        } //Fin affichage des erreurs
    } while(denominateur == 0 || denominateur != (int)denominateur || denominateur < -16000 || denominateur > 16000);

    //Traîtement
    if((denominateur < 0 && numerateur > 0) || (denominateur > 0 && numerateur < 0)) signe = '-'; //Gestion des signes

    if(numerateur < 0) reste = -numerateur; //Initialisation du reste
    else reste = numerateur;
    if(denominateur < 0) diviseur = -denominateur; //Initialisation du diviseur
    else diviseur = denominateur;

    while(reste >= diviseur) //Boucle calculant le reste et le résultat
    {
        reste -= diviseur;
        resultat++;
        compteur++;
    }

    //Affichage des résultats
    cout << "\n\nLe resultat de " << numerateur << " / " << denominateur << " est : " << signe << resultat;
    cout << "\nLe reste de " << numerateur << " / " << denominateur << " est : " << reste << "\n\n";

    system("pause");
}


//------------------------------------------------------------------------------------------


//Exercice 3 :

/*
        Algorithme de la méthode calculFactoriellle() de la classe CIhmBoucle() :
    Auteur : Doolaeghe Kevin
    Date : Octobre 2017

    Variables :
        nombre, compteur = entiers
        factorielle = entier 64 bits

    Début
        Afficher "Exercice 3 - Calcul d'une factorielle"
        factorielle <- 1
        Afficher "Entrez le nombre dont vous souhaitez avoir la factorielle : "
        Répéter
            Saisie nombre
        Jusqu'à (nombre > 0 et nombre < 16000)
        Si (nombre = 0)
                    Alors Afficher "!0 = 1"
                    Sinon   Tant que (compteur <= nombre)
                                    factorielle <-  * compteur
                                    compteur <- compteur + 1
                            Afficher "!", nombre, " = ",factorielle
    Fin
*/

void CIhmBoucle::calculFactorielle()
{
    //Initialisation
    float nombre;
    int compteur = 1;
    long long factorielle = 1;

    //Titre
    system("cls");
    cout << "\tExercice 3 - Calcul d'une factorielle\n\n";

    //Question
    cout << "Entrez le nombre dont vous souhaitez avoir la factorielle : ";
    do //Boucle de vérification
    {
        cin >> nombre;
        if(nombre < 0 || nombre != (int)nombre || nombre > 16000) //Gestion erreurs
        {
            cout << "\nErreur(s) :";
            if(nombre < 0) cout << "\n\t- Le nombre doit etre positif";
            if(nombre != (int)nombre) cout << "\n\t- Le nombre doit etre un entier";
            if(nombre > 16000) cout << "\n\t- Le nombre doit etre au maximum 16000";
            cout << (char)7 << (char)7 << (char)7 << "\n\t\tRecommencez : ";
        } //Fin affichage des erreurs
    } while(nombre < 0 || nombre != (int)nombre || nombre > 16000);
    cout << "\n";

    //Traîtement
    if(nombre == 0) //Cas !0
        cout << "!0 = 1\n\n";
    else
    {
        while(compteur <= nombre) //Boucle calcul de la factorielle demandée
        {
            factorielle *= compteur;
            compteur++;
        }

        //Affichage
        cout << "!" << nombre << " = " << factorielle << "\n\n";
    }

    system("pause");
}


//------------------------------------------------------------------------------------------


//Exercice 4 :

/*
        Algorithme de la méthode triangleIsocele() de la classe CIhmBoucle() :
    Auteur : Doolaeghe Kevin
    Date : Octobre 2017

    Variables :
        nbligne, numligne, nbespace, nbetoile = entiers

    Début
        Afficher "Exercice 4 - Triangle isocele"
        Afficher "Entrez le nombre de lignes que le triangle va comporter : "
        Répéter
            Saisir nbligne
        Jusqu'à (nbligne >= 0 et nbligne <= 40)
        Pour numligne allant de 0 à nbligne - 1
            Aller à la ligne
            Faire pour nbespace = 2 à nbligne - numligne
                Afficher " "
            Faire pour nbetoile = 1 à 2 * numligne + 1
                Afficher "*"
    Fin
*/

void CIhmBoucle::triangleIsocele()
{
    //Initialisation
    int numligne, nbespace, nbetoile;
    float nbligne;

    //Titre
    system("cls");
    cout << "\tExercice 4 - Triangle isocele\n\n"; //Affichage

    //Question
    cout << "Entrez le nombre de lignes que le triangle va comporter : ";
    do //Boucle de vérification
    {
        cin >> nbligne;
        if(nbligne < 0 || nbligne > 40 || nbligne != (int)nbligne) //Affichage des erreurs
        {
            cout << "\nErreur(s) :";
            if(nbligne < 0) cout << "\n\t- Le nombre doit etre positif";
            if(nbligne > 40) cout << "\n\t- 40 lignes au maximum";
            if(nbligne != (int)nbligne) cout << "\n\t- Le nombre doit etre un entier";
            cout << (char)7 << (char)7 << (char)7 << "\n\t\tRecommencez : ";
        } //Fin affichage des erreurs
    } while(nbligne < 0 || nbligne > 40 || nbligne != (int)nbligne);

    //Traîtement
    for(numligne = 0; numligne < nbligne; numligne++) //Numéro de ligne
    { //Boucles affichant les espaces et les étoiles de chaque ligne
        cout << "\n";
        //Nombre d'espaces = Nombre de lignes - Numéro de ligne : Calcul du nombre d'espaces
        for(nbespace = 2; nbespace <= nbligne - numligne; nbespace++) cout << " "; //Calcul du nombre d'espaces et affichage
        //Suite des nombres impairs : Calcul du nombre d'étoiles
        for(nbetoile = 1; nbetoile <= 2 * numligne + 1; nbetoile++) cout << "*"; //Calcul du nombre d'étoiles et affichage
    }
    cout << "\n\n";

    system("pause");
}


//------------------------------------------------------------------------------------------


//Exercice 5 :


/*
        Algorithme de la méthode tableMultiplication() de la classe CIhmBoucle :
    Auteur : Doolaeghe Kevin
    Date : Octobre 2017

    Variables :
        i, j, k, l, m

    Début
        Afficher "Exercice 5 - Table de multiplications"
        Afficher "  X*Y | "
        Pour i allant de 0 à 10
            Si (j <> 10)
                Alors   Afficher "   ", i, " "
                Sinon   Afficher "  ", i, " "
        Aller à la ligne
        Afficher "----------------------------------------------------------------"
        Pour j allant de 0 à 10
            Si (j < 10)
                Alors   Aller à la ligne
                        Afficher j, "   | "
                Sinon   Aller à la ligne
                        Afficher j, "  | "
            Pour k allant de 0 à 10
                Si (j * k < 10)
                    Alors   Afficher "   ", j * k, " "
                    Sinon   Si (j * k < 100)
                                Alors   Afficher "  ", j * k, " "
                    Sinon   Afficher " ", j * k, " "
    Fin
*/

void CIhmBoucle::tableMultiplication()
{
    //Initialisation
    int i, j, k;

    //Titre
    system("cls");
    cout << "\tExercice 5 - Table de multiplications\n\n";

    //Traîtement
    //Ligne 1
    cout << "\n  X*Y  | ";
    for(i = 0; i <= 10; i++) //Boucle écrivant 1 jusqu'à 10
    {
        if(i < 10) cout << "   " << i << " ";
        else cout << "  " << i << " ";
    }
    cout << "\n";
    //Ligne 2
    cout << "----------------------------------------------------------------";

    //Lignes suivantes
    for(j = 0; j <= 10; j++) //Boucle correspondant aux tables de 1 à 10
    {
        //Tables de 1 à 9
        if(j < 10) cout << "\n   " << j << "   | ";
        else cout << "\n  " << j << "   | ";
        //Tables de 1 à 10
        for(k = 0; k <= 10; k++)
        {
            if(j * k < 10) cout << "   " << j * k << " ";
            else if(j * k < 100) cout << "  " << j * k << " ";
            else cout << " " << j * k << " ";
        }
    }
    cout << "\n\n";

    system("pause");
}
