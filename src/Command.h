#ifndef COMMAND_H
#define COMMAND_H


#include "Runcmd.h"

class Command : public Runcmd
{
    public:
        Command();
        Command(std::string& );
        virtual bool run() = 0;
    
    protected:
        std::string cmd;
    
    
    
};

#endif
