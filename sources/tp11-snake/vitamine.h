#ifndef VITAMINE_H
#define VITAMINE_H

#include "positionXY.h"

class Vitamine
{
public:
    Vitamine();
    void afficheVitamine();
    void deplaceVitamine();
    void changerTypeVit();
    struct PositionXY vit;
    int typeVit;
};

#endif // VITAMINE_H
