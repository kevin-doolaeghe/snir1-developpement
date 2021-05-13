#ifndef LIAISONRS232_H
#define LIAISONRS232_H

#include "serialib/serialib.h"
#include <iostream>
using namespace std;

#define SERIAL_DEVICE "/dev/ttyUSB0" // linux
//#define SERIAL_DEV "COM4" // windows
#define VITESSE 9600

class LiaisonRs232
{
public:

    char device[30];
    int vitesseBaud;
    int rs232Connect;
    serialib liaisonCom;
    char chaineReception[4096];
    LiaisonRs232(char *com = SERIAL_DEVICE, int baud=VITESSE);
    int envoieChaineRs232(char *chaine);
    int lirechaineRs232();
    ~LiaisonRs232();
};

#endif // LIAISONRS232_H
