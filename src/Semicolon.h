#include "Connector.h"

class Semicolon : public Connector
{
    public:
        Semicolon(Runcmd*,Runcmd*);
        bool run();
    
};
