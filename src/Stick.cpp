#include "Stick.h"


    Stick::Stick(Runcmd* r, Runcmd* l) : Connector("|",r,l)
    {
        
        
    }
    
    bool Stick::run()
    {

            int fd[2];
            pipe(fd);

            int saveStdout = dup(1);

            
            if(-1 == dup2(fd[1], 1))
            {
	        	perror("There was an error with dup2");
		    
            }

            lhs->run();
            
            
            if(-1 == close(fd[1]))
            {
	        	perror("There was a problem with close. ");
            
            }
            
            
            int saveStdin = dup(0);

            
            if(-1 == dup2(fd[0], 0))
            {
	        	perror("There was an error with dup2");
		    
            }
      
            if(-1 == dup2(saveStdout, 1))
            {
	        	perror("There was an error with dup2");
		    
            }

            rhs->run();

            
            if(-1 == close(fd[0]))
            {
	        	perror("There was a problem with close. ");
            
            }

            
            if(-1 == dup2(saveStdin, 0))
            {
	        	perror("There was an error with dup2");
		    
            }
            
            return true;
        
    }
