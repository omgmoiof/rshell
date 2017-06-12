#ifndef DoubleGreaterThan_H
#define DoubleGreaterThan_H

#include "Connector.h"

class DoubleGreaterThan : public Connector
{
    public:
        DoubleGreaterThan(Runcmd*,Runcmd*);
        bool run();
    
};

#endif
