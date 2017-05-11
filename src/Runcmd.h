#ifndef RUNCMD_H
#define RUNCMD_H

#include <string>
#include <stdlib.h>

class Runcmd
{
    public:
        Runcmd();
        ~Runcmd();
        virtual bool run() = 0;
    
};
#endif
