#include "Command.h"


    Command::Command() {}
    
    Command::Command(std::string& s)
    {
        cmd = s;
    }
    
    std::string Command::getCmd() {return cmd;}
