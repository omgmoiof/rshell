#ifndef Stick_H
#define Stick_H

#include "Connector.h"

class Stick : public Connector
{
    public:
        Stick(Runcmd*,Runcmd*);
        bool run();
    
};

#endif
