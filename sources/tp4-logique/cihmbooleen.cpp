#include "cihmbooleen.h"

//----------------------------------------------------------------------------------------------

//Constructeur

CIhmBooleen::CIhmBooleen()
{
	
}

//----------------------------------------------------------------------------------------------

//Menu

/*
        Algorithme de la méthode menu() de la classe CIhmBooleen :
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

void CIhmBooleen::menu()
{
    system("color f0");
	char touche;
	do
	{
        system("cls");
		cout << "\t  MENU  PRINCIPALE\n" << "\t--------------------\n\t  DOOLAEGHE  Kevin\n\n";
        cout << "(a) Exercice 1 - Test de condition\n(b) Exercice 2 - Combinaison logique\n(c) Exercice 3 - Conversion binaire\n(d) Exercice 4 - Incrementation de variable\n(e) Exercice 5 - Forcer un bit a 1\n(q) Quitter\n\nSelectionnez a, b, c, d, e ou q : ";
		touche = getch();
        if(touche == 'a' || touche == 'A' || touche == '1') testCondition();
        if(touche == 'b' || touche == 'B' || touche == '2') combinaisonLogique();
        if(touche == 'c' || touche == 'C' || touche == '3') conversionBinaire();
        if(touche == 'd' || touche == 'D' || touche == '4') incrementeVariable();
        if(touche == 'e' || touche == 'E' || touche == '5') setBitVal();
	} while(touche != 'q' && touche != 'Q');
}

//----------------------------------------------------------------------------------------------

//Exercice 1

/*
        Algorithme de la méthode testCondition() de la classe CIhmBooleen :
    Auteur : Delvarre
    Date : Octobre 2017

	Variables :
        val = numérique

	Début
        Saisir val
        Si (val)
            Alors   Afficher “val est vrai”
            Sinon   Afficher “val est faux”
	Fin
*/

void CIhmBooleen::testCondition()
{
    //Initialisation
    float val;

    //Affichage
	system("cls");
	cout << "\t\tExercice 1 :\n\n";

    //Question
    cout << "\nEntrez un entier : ";
    do
    { //Saisie de val et vérification
        cin >> val;
        if(val != (int)val || val < -2000000000 || val > 2000000000)
        { //Gestion des erreurs
            cout << "\nErreur(s) :";
            if(val != (int)val) cout << "\n\t- Ce n'est pas un nombre entier";
            if(val < -2000000000 || val > 2000000000) cout << "\n\t- L'intervalle est plus ou moins deux milliards";
            cout << (char)7 << (char)7 << (char)7 << "\nRecommencez : ";
        }
    } while(val != (int)val || val < -2000000000 || val > 200000000000);

    //Traîtement
    if(val) cout << "\nval est vrai\n\n";
    else cout << "\nval est faux\n\n";
    system("pause");
}

//val est toujours vrai sauf pour 0. Il semblerait que par défaut, ce soit un ou logique avec 0 qui est effectué.

//----------------------------------------------------------------------------------------------

//Exercice 2

void CIhmBooleen::combinaisonLogique()
{
    //Initialisation
    int val1, val2;
    float v1, v2;

    //Affichage
    system("cls");
	cout << "\t\tExercice 2 :\n\n";

    //Question
    //val1 :
    cout << "\nEntrez la valeur de val1 : ";
    do
    {
        cin >> v1;
        if(v1 != (int)v1 || v1 < -2000000000 || v1 > 2000000000) //Gestion des erreurs
        { //Affichage des erreurs
            cout << "\nErreur(s) :";
            if(v1 != (int)v1) cout << "\n\t- Ce n'est pas un nombre entier";
            if(v1 < -2000000000 || v1 > 2000000000) cout << "\n\t- L'intervalle est plus ou moins deux milliards";
            cout << (char)7 << (char)7 << (char)7 << "\n\t\tRecommencez : ";
        } //Fin gestion des erreurs
    } while(v1 != (int)v1 || v1 < -2000000000 || v1 > 200000000000);
    val1 = v1;
    //val2 :
    cout << "\nEntrez la valeur de val2 : ";
    do
    {
        cin >> v2;
        if(v2 != (int)v2 || v2 < -2000000000 || v2 > 2000000000) //Gestion des erreurs
        { //Affichage des erreurs
            cout << "\nErreur(s) :";
            if(v2 != (int)v2) cout << "\n\t- Ce n'est pas un nombre entier";
            if(v2 < -2000000000 || v2 > 2000000000) cout << "\n\t- L'intervalle est plus ou moins deux milliards";
            cout << (char)7 << (char)7 << (char)7 << "\n\t\tRecommencez : ";
        } //Fin gestion des erreurs
    } while(v2 != (int)v2 || v2 < -2000000000 || v2 > 200000000000);
    val2 = v2;

    //Traîtement
    //Affichage
    cout << "\n~val1 = " << (~val1) << endl;
    cout << "val1 & val2 = " << (val1 & val2) << endl;
    cout << "val1 | val2 = " << (val1 | val2) << endl;
    cout << "!val1 = " << (!val1) << endl;
    cout << "val1 && val2 = " << (val1 && val2) << endl;
    cout << "val1 || val2 = " << (val1 || val2) << "\n\n";
    system("pause");
}

/*
    Opérateur ~ : Prend le nombre binaire de la valeur et remplace les 0 par des 1 et inversement.
    Opérateur & : Réalise un ET entre les différents bits des deux valeurs en binaire
    Opérateur | : Réalise un OU entre les différents bits des deux valeurs en binaire
    Opérateur ! : Si la valeur vaut 0 alors  1 sinon cela 0
    Opérateur && : Renvoie 0 si le test est effectué avec un 0 sinon il renvoie 1
    Opérateur || : Renvoie 0 si le test est effectué avec deux 0 sinon il renvoie 1
*/

//----------------------------------------------------------------------------------------------

//Exercice 3

/*
        Algorithme de la méthode conversionBinaire() de la classe CIhmBooleen :
	Auteur : Kevin Doolaeghe
    Date : Octobre 2017

	Variables :
        i, nombre, masque = entiers

	Début
        Afficher "Conversion en binaire"
        Répeter
            Afficher "Entrez un nombre entre -128 et 127 : "
            Saisir nombre
        Jusqu'à (nombre < 128 et nombre > -129)
        Afficher "La valeur binaire du nombre ", nombre, " est : "
        Pour i allant de 0 à 7
            masque <- 128 >> i
            Si ((nombre & masque) = 0)
                Alors   Afficher "0"
                Sinon   Afficher "1"
	Fin
*/

void CIhmBooleen::conversionBinaire()
{
    //Initialisation
    short i, masque;
    float nombre;

    //Affichage
	system("cls");
    cout << "\t\tExercice 3 : Conversion binaire\n\n";

    //Question
    cout << "Entrez un entier entre -128 et 127: ";
    do
    {
        cin >> nombre;
        if(nombre != (int)nombre || nombre < -128 || nombre > 127)
        { //Gestion des erreurs
            cout << "Erreur(s) :";
            if(nombre != (int)nombre) cout << "\n\t- Le nombre doit etre un entier";
            if(nombre < -128 || nombre > 127) cout << "\n\t- Le nombre doit etre entre -128 et 127";
            cout << (char)7 << (char)7 << (char)7 << "\nRecommencez : ";
        }
    } while(nombre != (int)nombre || nombre > 127 || nombre < -128);

    //Traîtement
    cout << "La valeur binaire du nombre " << nombre << " est : ";
    for(i = 0; i < 8; i++) //Boucle
    {
        masque = 128 >> i; //Mise à jour du masque
        if(((short)nombre & masque) == 0) cout << "0";
        else cout << "1";
    }
    cout << "\n";
    system("pause");
}

/*
    - La capacité de comptage est 256 valeurs (-128 à 127).
    - Le huitième bit est le bit de signe, il permet de savoir si le nombre est négatif (1) ou non (0).
*/

//----------------------------------------------------------------------------------------------

//Exercice 4

/*
        Algorithme de la méthode incrementeVariable() de la classe CIhmBooleen :
	Auteur : Kevin Doolaeghe
    Date : Octobre 2017

	Variables :
        code1, question = caractères
        code2 = entier 16 bits

	Début
        Afficher "Exercice 4"
        Afficher "Tapez 0 ou 1 pour utiliser une variable de type char ou short : "
        question <- fonction saisie d'une touche
        Si (question = '0')
            Alors   Tant que (code1 < 128)
                        Afficher code1 en entier 16 bits
                        Si (code1 = 1)
                            Alors   Faire une pause
                        code1 <- code1 + 1
            Sinon   Tant que (code2 < 32768)
                        Afficher code2
                        Si (code2 = 1)
                            Alors   Faire une pause
                        code2 <- code2 + 1
	Fin
*/

void CIhmBooleen::incrementeVariable()
{
    //Initialisation
    char code1 = 0;
    short code2 = 0;
    char question;

    //Affichage
	system("cls");
	cout << "\t\tExercice 4 :\n\n";

    //Question
    cout << "Tapez 0 ou 1 pour utiliser une variable de type char ou short : ";
    do //Boucle de saisie de la variable question et vérification de la réponse (0 ou 1)
    {
        question = getch();
        if(question != '0' && question != '1') cout << (char)7 << (char)7 << (char)7 << "\nVous devez entrer 0 ou 1, recommencez : ";
    } while(question != '0' && question != '1');

    //Traîtement
    cout << "\n\n";
    if(question == '0') //Type char
    { //Choix du type char
        while(code1 < 128) //Boucle infinie
        {
            cout << (short)code1 << endl;
            if(code1 == 1) system("pause");
            code1++;
        }
    }
    else
    { //Choix du type short
        while(code2 < 32768) //Boucle infinie
        {
            cout << code2 << endl;
            if(code2 == 1) system("pause");
            code2++;
        }
    }
}

//Lorsque l'on atteint la valeur maximale permise par le type de la variable, on repare à la valeur minimale ce qui rend la boucle infinie.

//----------------------------------------------------------------------------------------------

//Exercice 5

/*
        Algorithme de la méthode setBitVal() de la classe CIhmBooleen :
	Auteur : Kevin Doolaeghe
    Date : Octobre 2017

	Variables :
        val, numero, i, puis2 = entiers

	Début
        puis2 <- 1
        Afficher "Exercice 5"
        Afficher "Saisissez un nombre : "
        Saisir val
        Afficher "Entrez le rang du bit a mettre a 1 : "
        Saisir numero
        Pour i allant de 0 à numero - 1
            puis2 <- puis2 * 2
        val <- val | puis2
        Afficher "La nouvelle valeur est : ", val
	Fin
*/

void CIhmBooleen::setBitVal()
{
    //Initialisation
    float val, numero;
    short i;
    short puis2 = 1;

    //Affichage
	system("cls");
	cout << "\t\tExercice 5 :\n\n";

    //Question
    cout << "Saisissez un nombre : ";
    do //Boucle de saisie du nombre et vérification
    {
        cin >> val;
        if(val != (int)val || val < -32768 || val > 32767)
        { //Gestion des erreurs
            cout << "Erreur(s) :";
            if(val != (int)val) cout << "\n\tLe nombre doit etre un entier";
            if(val < -32768 || val > 32767) cout << "\n\tLe nombre doit etre entre -32768 et 32767";
            cout << (char)7 << (char)7 << (char)7 << "\nRecommencez : ";
        }
    } while(val != (int)val || val > 32767 || val < -32768);
    cout << "Entrez le rang du bit a mettre a 1 : ";
    //numero est entre 1 et 16
    do //Boucle de saisie du rang et vérification
    {
        cin >> numero;
        if(numero != (int)numero || numero < 1 || numero > 16)
        { //Gestion des erreurs
            cout << "Erreur(s) :";
            if(numero != (int)numero) cout << "\n\t- Le rang doit etre un entier";
            if(numero < 1 || numero > 16) cout << "\n\t- Le rang doit etre entre 1 et 16";
            cout << (char)7 << (char)7 << (char)7 << "\nRecommencez : ";
        }
    } while(numero != (int)numero || numero > 16 || numero < 1);

    //Traîtement
    for(i = 0; i < numero - 1; i++) //Boucle qui calcule la puissance de 2 correspondant au rang
    {
        puis2 *= 2;
    }
    val = (short)val | puis2; //Calcul du resultat

    //Affichage
    cout << "La nouvelle valeur est : " << (short)val<< endl;
	system("pause");
}
