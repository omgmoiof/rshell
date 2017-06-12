#ifndef RUNCMD_H
#define RUNCMD_H

#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stack>
#include <algorithm>
#include <fcntl.h>
#include <math.h>

class Runcmd
{
    public:
        Runcmd();
        ~Runcmd();
        virtual bool run() = 0;
        virtual std::string getCmd() = 0;
    
};
#endif
