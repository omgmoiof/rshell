#ifndef EXECVOCND_H
#define EXECVOCND_H

#include "Command.h"
#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

class Execvpcmd : public Command
{
    public:
        Execvpcmd(std::string&);
        bool run();
    
};

#endif
