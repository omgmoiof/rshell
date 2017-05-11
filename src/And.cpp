#include "And.h"

class And : public Connector
{
    And(Runcmd* r, Runcmd* l) : Connector("&&",r,l)
    {
        
        
    }
    
    bool run()
    {
        if (lhs == NULL) return false;
        else if (rhs == NULL)
        {
            if (lhs != NULL) return rhs->run();
            return false;
        }
        else return lhs->run() && rhs->run();
        
    }
}
