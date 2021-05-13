#include "tramemanip.h"

TrameManip::TrameManip(string dataTrame)
{
    trame = dataTrame;
    headBalise = "";
    endBalise = "";
}

void TrameManip::setTrame(string dataTrame)
{
    trame = dataTrame;
}

void TrameManip::setHeadBalise(string balise)
{
    headBalise = balise;
}

void TrameManip::setEndBalise(string balise)
{
    endBalise = balise;
}

string TrameManip::setData(string data, string idHead, string idEnd, string dataTrame)
{
    if(!dataTrame.empty()) trame = dataTrame;
    if(!idHead.empty()) headBalise = idHead;
    if(!idEnd.empty()) endBalise = idEnd;

    if(trame.find(headBalise) == -1 && trame.find(endBalise) == -1) trame += headBalise + data + endBalise;

    return trame;
}

string TrameManip::getTrame()
{
    return trame;
}

string TrameManip::getData(string idHead, string idEnd, string dataTrame)
{
    string donnees = "";

    if(!dataTrame.empty()) trame = dataTrame;
    if(!idHead.empty()) headBalise = idHead;
    if(!idEnd.empty()) endBalise = idEnd;

    int posDebut = trame.find(headBalise);

    if(posDebut != -1)
    {
        int posFin = trame.find(endBalise, posDebut);

        if(posFin != -1)
        {
            int nbCar = posFin - posDebut - headBalise.length();
            donnees = trame.substr(posDebut + headBalise.length(), nbCar);
        }
    }

    return donnees;
}

bool TrameManip::modifData(string data, string idHead, string idEnd, string dataTrame)
{
    bool retour = false;

    if(!dataTrame.empty()) trame = dataTrame;
    if(!idHead.empty()) headBalise = idHead;
    if(!idEnd.empty()) endBalise = idEnd;

    int posDebut = trame.find(headBalise);

    if(posDebut != -1)
    {
        int posFin = trame.find(endBalise, posDebut);

        if(posFin != -1)
        {
            int nbCar = posFin - posDebut - headBalise.length();
            trame.replace(posDebut + headBalise.length(), nbCar, data);

            retour = true;
        }
    }

    return retour;
}

bool TrameManip::supprimeData(string idHead, string idEnd, string dataTrame)
{
    bool retour = false;

    if(!dataTrame.empty()) trame = dataTrame;
    if(!idHead.empty()) headBalise = idHead;
    if(!idEnd.empty()) endBalise = idEnd;

    int posDebut = trame.find(headBalise);

    if(posDebut != -1)
    {
        int posFin = trame.find(endBalise, posDebut);

        if(posFin != -1)
        {
            int nbCar = posFin + endBalise.length() - posDebut;
            trame.erase(posDebut, nbCar);

            retour = true;
        }
    }

    return retour;
}
