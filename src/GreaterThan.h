#ifndef GreaterThan_H
#define GreaterThan_H

#include "Connector.h"

class GreaterThan : public Connector
{
    public:
        GreaterThan(Runcmd*,Runcmd*);
        bool run();
    
};

#endif
