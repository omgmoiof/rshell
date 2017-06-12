#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "Runcmd.h"


class Connector : public Runcmd
{
    protected:
        Runcmd* rhs;
        Runcmd* lhs;
    
    public:
        Connector(std::string, Runcmd*, Runcmd*);
        ~Connector();
        virtual bool run() = 0;
        std::string getCmd();
    
    private:
        std::string literal;
    
};

#endif
