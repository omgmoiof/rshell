#include "Semicolon.h"

    Semicolon::Semicolon(Runcmd* r, Runcmd* l) : Connector(";",r,l)
    {
        
        
    }
    
    bool Semicolon::run()
    {
        if (lhs != NULL) lhs->run();
        if (rhs != NULL) rhs->run();
        return true;
        
    }
