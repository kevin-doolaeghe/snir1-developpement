/*      Titre : Calcul d'un numéro INSEE
 *
 *  Auteur : Kévin DOOLAEGHE
 *  Date : 21/09/2017
 *
 *  Variables :
 *      cle = entier
 *      sexe = caractère
 *      an = entier
 *      mois = entier
 *      departement = entier
 *      codeVille = entier
 *      codeNaissance = entier
 *      numInsee = entier 64 bits
 *
 *  début
 *
 *      affichage "Calcul d'un numero INSEE"
 *      affichage "Sexe"
 *      affichage "Etes-vous un homme ou une femme ? (tapez h ou f)"
 *      saisir sexe
 *      tant que(sexe <> 'h' et sexe <> 'f')
 *              effacer l'écran
 *              affichage "Calcul d'un numero INSEE"
 *              affichage "Sexe"
 *              affichage "Etes-vous un homme ou une femme ? (tapez h ou f)"
 *              affichage "Vous avez entre une mauvaise valeur, recommencez..."
 *              saisir sexe
 *      fin tant que
 *      si(sexe = 'h')
 *              alors numInsee <- 1000000000000
 *              sinon numInsee <- 2000000000000
 *
 *      effacer l'écran
 *      affichage "Calcul d'un numero INSEE"
 *      affichage "Annee de naissance"
 *      affichage "En quelle annee etes-vous ne ? (deux derniers chiffres)"
 *      saisir an
 *      tant que(an < 0 et an > 99)
 *              effacer l'écran
 *              affichage "Calcul d'un numero INSEE"
 *              affichage "Annee de naissance"
 *              affichage "En quelle annee etes-vous ne ? (deux derniers chiffres)"
 *              affichage "Vous avez entre une mauvaise valeur, recommencez..."
 *              saisir an
 *      fin tant que
 *      numInsee <- numInsee + an * 10000000000
 *
 *      effacer l'écran
 *      affichage "Calcul d'un numero INSEE"
 *      affichage "Mois de naissance"
 *      affichage "Quel est votre mois de naissance ? (deux chiffres)"
 *      saisir mois
 *      tant que(an < 0 et mois > 12)
 *              effacer l'écran
 *              affichage "Calcul d'un numero INSEE"
 *              affichage "Mois de naissance"
 *              affichage "Quel est votre mois de naissance ? (deux chiffres)"
 *              affichage "Vous avez entre une mauvaise valeur, recommencez..."
 *              saisir mois
 *      fin tant que
 *      numInsee <- numInsee + mois * 100000000
 *
 *      effacer l'écran
 *      affichage "Calcul d'un numero INSEE"
 *      affichage "Departement de la ville de naissance"
 *      affichage "Dans quel departement etes-vous ne ? (deux chiffres)"
 *      saisir departement
 *      tant que(departement < 1 et departement > 94)
 *              effacer l'écran
 *              affichage "Calcul d'un numero INSEE"
 *              affichage "Departement de la ville de naissance"
 *              affichage "Dans quel departement etes-vous ne ? (deux chiffres)"
 *              affichage "Vous avez entre une mauvaise valeur, recommencez..."
 *              saisir departement
 *      fin tant que
 *      numInsee <- numInsee + departement * 1000000
 *
 *      effacer l'écran
 *      affichage "Calcul d'un numero INSEE"
 *      affichage "Code de la ville de naissance"
 *      affichage "Quel est le code de la ville dans laquelle vout etes ne ? (trois chiffres)"
 *      saisir codeVille
 *      tant que(codeVille < 1 et codeVille > 999)
 *              effacer l'écran
 *              affichage "Calcul d'un numero INSEE"
 *              affichage "Code de la ville de naissance"
 *              affichage "Quel est le code de la ville dans laquelle vout etes ne ? (trois chiffres)"
 *              affichage "Vous avez entre une mauvaise valeur, recommencez..."
 *              saisir codeVille
 *      fin tant que
 *      numInsee <- numInsee + codeVille * 1000
 *
 *      effacer l'écran
 *      affichage "Calcul d'un numero INSEE"
 *      affichage "Code naissance"
 *      affichage "Combien y a-t-il eu de naissances le mois de votre naissance ? (trois chiffres)"
 *      saisir CodeNaissance
 *      tant que(codeNaissance < 1 et codeNaissance > 999)
 *              effacer l'écran
 *              affichage "Calcul d'un numero INSEE"
 *              affichage "Code naissance"
 *              affichage "Combien y a-t-il eu de naissances le mois de votre naissance ? (trois chiffres)"
 *              affichage "Vous avez entre une mauvaise valeur, recommencez..."
 *              saisir codeNaissance
 *      fin tant que
 *      numInsee <- numInsee + codeNaissance
 *
 *      cle <- 97 - numInsee modulo 97
 *      numInsee <- numInsee * 100 + cle
 *
 *      effacer l'écran
 *      affichage "Calcul d'un numero INSEE"
 *      affichage "Votre numero INSEE est le suivant :"
 *      affichage numInsee
 *
 *  fin
 *
 */

#include "cihm.h"

CIhm::CIhm()
{
}

void CIhm::calculInsee()
{
    int cle;
    char sexe;
    int an;
    int mois;
    int departement;
    int codeVille;
    int codeNaissance;
    long long numInsee;

    cout << "\t\tCalcul d'un numero INSEE\n\n";
    cout << "\tSexe\n\n";
    cout << "Etes-vous un homme ou une femme ? (tapez h ou f)\n";
    cin >> sexe;

    while (sexe != 'h' && sexe != 'f')
    {
        system("clear");
        cout << "\t\tCalcul d'un numero INSEE\n\n";
        cout << "\tSexe\n\n";
        cout << "Etes-vous un homme ou une femme ? (tapez h ou f)\n\n";
        cout << "Vous avez entre une mauvaise valeur, recommencez...\n";
        cin >> sexe;
    }
    if (sexe == 'h')
        numInsee = 1000000000000;
    else
        numInsee = 2000000000000;

    system("clear");
    cout << "\t\tCalcul d'un numero INSEE\n\n";
    cout << "\tAnnee de naissance\n\n";
    cout << "En quelle annee etes-vous ne ? (deux derniers chiffres)\n";
    cin >> an;
    while (an < 0 || an > 99)
    {
        system("clear");
        cout << "\t\tCalcul d'un numero INSEE\n\n";
        cout << "\tAnnee de naissance\n\n";
        cout << "En quelle annee etes-vous ne ? (deux derniers chiffres)\n\n";
        cout << "Vous avez entre une mauvaise valeur, recommencez...\n";
        cin >> an;
    }
    numInsee = numInsee + an * 10000000000;

    system("clear");
    cout << "\t\tCalcul d'un numero INSEE\n\n";
    cout << "\tMois de naissance\n\n";
    cout << "Quel est votre mois de naissance ? (deux chiffres)\n";
    cin >> mois;
    while (mois < 1 || mois > 12)
    {
        system("clear");
        cout << "\t\tCalcul d'un numero INSEE\n\n";
        cout << "\tMois de naissance\n\n";
        cout << "Quel est votre mois de naissance ? (deux chiffres)\n\n";
        cout << "Vous avez entre une mauvaise valeur, recommencez...\n";
        cin >> mois;
    }
    numInsee = numInsee + mois * 100000000;

    system("clear");
    cout << "\t\tCalcul d'un numero INSEE\n\n";
    cout << "\tDepartement de la ville de naissance\n\n";
    cout << "Dans quel departement etes-vous ne ? (deux chiffres)\n";
    cin >> departement;
    while (departement < 1 || departement > 94)
    {
        system("clear");
        cout << "\t\tCalcul d'un numero INSEE\n\n";
        cout << "\tMois de naissance\n\n";
        cout << "Quel est votre mois de naissance ? (deux chiffres)\n\n";
        cout << "Vous avez entre une mauvaise valeur, recommencez...\n";
        cin >> departement;
    }
    numInsee = numInsee + departement * 1000000;

    system("clear");
    cout << "\t\tCalcul d'un numero INSEE\n\n";
    cout << "\tCode de la ville de naissance\n\n";
    cout << "Quel est le code de la ville de votre naissance ? (trois chiffres)\n";
    cin >> codeVille;
    while (codeVille < 1 || codeVille > 999)
    {
        system("clear");
        cout << "\t\tCalcul d'un numero INSEE\n\n";
        cout << "\tCode de la ville de naissance\n\n";
        cout << "Quel est le code de la ville de votre naissance ? (trois chiffres)\n\n";
        cout << "Vous avez entre une mauvaise valeur, recommencez...\n";
        cin >> codeVille;
    }
    numInsee = numInsee + codeVille * 1000;

    system("clear");
    cout << "\t\tCalcul d'un numero INSEE\n\n";
    cout << "\tCode naissance\n\n";
    cout << "Combien y a-t-il eu de naissances le mois de votre naissance ? (trois chiffres)\n";
    cin >> codeNaissance;
    while (codeNaissance < 1 || codeNaissance > 999)
    {
        system("clear");
        cout << "\t\tCalcul d'un numero INSEE\n\n";
        cout << "\tCode naissance\n\n";
        cout << "Combien y a-t-il eu de naissance le mois de votre naissance ? (deux chiffres)\n\n";
        cout << "Vous avez entre une mauvaise valeur, recommencez...\n";
        cin >> codeNaissance;
    }
    numInsee = numInsee + codeNaissance;

    cle = 97 - numInsee % 97;
    numInsee = numInsee * 100 + cle;

    system("clear");
    cout << "\t\tCalcul d'un numero INSEE\n\n";
    cout << "\tVotre numero INSEE est le suivant\n\n";
    cout << numInsee << "\n\n";

    system("pause");
}
