#include "GreaterThan.h"


    GreaterThan::GreaterThan(Runcmd* r, Runcmd* l) : Connector(">",r,l)
    {
        
        
    }
    
    bool GreaterThan::run()
    {

            char file[256];
            strcpy(file, rhs->getCmd().c_str());
            int redir;
            if((redir = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP)) == -1)
            {
    			perror("Redir Error: Could not open file");
    			return false;

    		}
            int sd = dup(1);

            
            if(-1 == dup2(redir, 1))
            {
	        	perror("There was an error with dup2");
		    
            }
            
            lhs->run();

            
            if(-1 == dup2(sd, 1))
            {
	        	perror("There was an error with dup2");
		    
            }
            return true;
        
    }
