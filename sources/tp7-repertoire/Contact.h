#ifndef CONTACT_H
#define CONTACT_H

struct dataContact
{
    char nom[16];
    char prenom[16];
    char adresse[31];
    char ville[21];
    char codePostale[6];
    char email[31];
    char telDomicile[11];
    char telPortable[11];
};

#endif // CONTACT_H
