#include "DoubleGreaterThan.h"


    DoubleGreaterThan::DoubleGreaterThan(Runcmd* r, Runcmd* l) : Connector(">>",r,l)
    {
        
        
    }
    
    bool DoubleGreaterThan::run()
    {

            char file[256];
            strcpy(file, rhs->getCmd().c_str());
            int redir;
            if((redir = open(file, O_RDWR | O_APPEND | O_CREAT , S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP )) == -1)
            {
    				perror("Error with output redirection"); //error message with output redirection
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
