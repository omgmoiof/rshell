#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Connector.h"

class Semicolon : public Connector
{
    public:
        Semicolon(Runcmd*,Runcmd*);
        bool run();
    
};
#endif
