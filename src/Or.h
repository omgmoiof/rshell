
#ifndef OR_H
#define OR_H

#include "Connector.h"

class Or : public Connector
{
    public:
        Or(Runcmd*,Runcmd*);
        bool run();
    
};

#endif
