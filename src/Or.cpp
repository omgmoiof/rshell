
#include "Or.h"


    Or::Or(Runcmd* r, Runcmd* l) : Connector("||",r,l)
    {
        
        
    }
    
    bool Or::run()
    {
        if (lhs == NULL)
        {
            if (rhs != NULL) return rhs->run();
        }
        else if (rhs == NULL) return lhs->run();
        return lhs->run() || rhs->run();
        
    }
