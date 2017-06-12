#ifndef PARSE_H
#define PARSE_H


#include "Runcmd.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"
#include "Command.h"
#include "Connector.h"
#include "Execvpcmd.h"
#include "Exit.h"
#include "DoubleGreaterThan.h"
#include "GreaterThan.h"
#include "LessThan.h"
#include "Stick.h"

#include <string>
#include <iostream>
#include <fstream>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>


class Parse
{
    public:
        Parse();
        void run();
        Runcmd* parse(std::string&);
    
};

#endif
