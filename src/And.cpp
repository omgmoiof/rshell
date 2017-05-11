#include "And.h"


    And::And(Runcmd* r, Runcmd* l) : Connector("&&",r,l)
    {
        
        
    }
    
    bool And::run()
    {
        if (lhs == NULL) return false;
        else if (rhs == NULL)
        {
            if (lhs != NULL) return rhs->run();
            return false;
        }
        else return lhs->run() && rhs->run();
        
    }
