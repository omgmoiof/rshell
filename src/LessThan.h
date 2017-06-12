#ifndef LessThan_H
#define LessThan_H

#include "Connector.h"

class LessThan : public Connector
{
    public:
        LessThan(Runcmd*,Runcmd*);
        bool run();
    
};

#endif
