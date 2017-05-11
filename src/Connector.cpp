#include "Connector.h"


    Connector::Connector(std::string s, Runcmd* r, Runcmd *l)
    {
        literal = s;
        rhs = r;
        lhs = l;
        
    }
    
    Connector::~Connector()
    {
       
        
    }
