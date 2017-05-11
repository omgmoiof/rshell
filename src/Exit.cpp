#include "Exit.h"

    Exit::Exit() : Command()
    {
        cmd = "";
    
    }
    
    bool Exit::run()
    {
        exit(0);
        
    }

