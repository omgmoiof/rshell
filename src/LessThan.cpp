#include "LessThan.h"


    LessThan::LessThan(Runcmd* r, Runcmd* l) : Connector("<",r,l)
    {
        
        
    }
    
    bool LessThan::run()
    {
        char file[256];
			strcpy(file, rhs->getCmd().c_str());
            int redir;
			if((redir = open(file, O_RDONLY )) == -1) 
			{
				perror("Input Redirection Error: Could not open file");
				return false;
			}
			
			int sd = dup(0);
			if(-1 == dup2(redir, 0))
            {
	        	perror("There was an error with dup2");
		    
            }
			
			
			lhs->run();
			
			if(-1 == dup2(sd, 0))
            {
	        	perror("There was an error with dup2");
		    
            }
            return true;
        
    }
