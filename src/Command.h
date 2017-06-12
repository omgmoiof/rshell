#ifndef COMMAND_H
#define COMMAND_H


#include "Runcmd.h"
#include <vector>

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stack>
#include <algorithm>

class Command : public Runcmd
{
    public:
        Command();
        Command(std::string& );
        virtual bool run() = 0;
        std::string getCmd();
    
    protected:
        std::string cmd;
    
    
};
#endif
