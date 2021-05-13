#include "liaisonrs232.h"

LiaisonRs232::LiaisonRs232(char *com, int baud)
{
    rs232Connect = 0;
    strcpy(device,com);
    vitesseBaud=baud;
    rs232Connect = liaisonCom.Open(device,vitesseBaud);
    if (rs232Connect!=1)
    {
        cout << "Erreur de connexion - le port UART ne s'ouvre pas. \n";
        cout << "Assurez-vous qu'il n'est pas ouvert par l'utilisation d'une autre application.\n";
        cout << "rs232Connect = "<<(int)rs232Connect<< "\n\n";
    }
      else   cout << "Le port série "<< device << " est ouvert avec succès. rs232Connect = "<<rs232Connect<< "\n\n";

}

int LiaisonRs232::envoieChaineRs232(char *chaine)
{
  int nbCar=0;
  if (rs232Connect == 1)
  {
      int nbCar = liaisonCom.WriteString(chaine);
     // cout << "nbCar = "<<nbCar<<endl;
      if (nbCar<0)
                    cout << "Erreur, les données n'ont pas été transmises !. \n";
      else
            cout << "La chaine : \""<<chaine<<"\" a été envoyée .\n\n";
  } else
      cout << "Pas de connexion du port Série, les données ne sont pas envoyées.\n\n";
  return nbCar;
}

int LiaisonRs232::lirechaineRs232()
{
    int nbCar;
    if (rs232Connect == 1)
    {
        nbCar = liaisonCom.ReadString(chaineReception,'\n',256,10000);

    }

    return nbCar;
}

LiaisonRs232::~LiaisonRs232()
{
    liaisonCom.Close();
}

