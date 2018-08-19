#include "Execvpcmd.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

Execvpcmd::Execvpcmd(std::string& s) : Command(s)
{
    int start = s.find_first_not_of(" ");
    int end = s.find_last_not_of(" ");
    cmd = s.substr(start, end - start + 1);
}

bool Execvpcmd::run()
{
   stringstream strstm;
   strstm.str(cmd);
   vector<string> alpha;
   string m, n;
   strstm >> m;
   alpha.push_back(m);
   while(strstm >> n)
   {
       alpha.push_back(n);
   }
   
   char ** beta = new char * [alpha.size() + 1];
   
   for (unsigned i = 0; i < alpha.size(); i++)
   {
       beta[i] = (char *)(alpha[i].c_str());
   }
   
   beta[alpha.size()] = NULL;

   
    string flag;
    string info;
    
    if((cmd.at(0) == '[' || cmd.substr(0,4) == "test") && alpha.size() > 1)
    {
                
        if(alpha.size() != 2)
        {
            flag = alpha.at(1);
            info = alpha.at(2);
        }
        
        else
        {
                    
            flag = "-e"; //if e flag is detected
            info = alpha.at(1);
        }
                
        struct stat testf;
        char temp[1024];
        strcpy(temp, info.c_str());
        const char* path = temp;
                
        if(stat(path, &testf) == -1) //Checks if the file or info exists
        {
            cout << "(False)" << endl;  //Prints out (False) if it does not exists
            return false;
        }
        
        if(flag == "-f") //if f flag is detected
        {
            if(S_ISREG(testf.st_mode) == false)   //Checks if it exists and is a file
            {
                cout << "(False)" << endl; //Prints out (False) if it does not exists or is not a file
                return false;

            }
                cout << "(True)" << endl;  //Prints out (True) if it exists and is a file
                return true;
                
        }
        else if(flag == "-d") //if d flag is detected
        {
            if(S_ISDIR(testf.st_mode))  //Checks if it exists and is a info
            {
                cout << "(True)" << endl; //Prints out (True) if it exists and is a info
                return true;
            }
            cout << "(False)" << endl;  //Prints out (False) if it does not exists or is not a info
            return false;
        }
        
        cout << "(True)" << endl;  //Prints out (True) if it does exist
        return true;
    }


  
  int error;
  
  int pid = fork();  //Creates parent and child
    switch(pid)
    {
        
        case -1:
            perror("Error in forking"); //Forking fails
            return 0;
        
        case 0:
        
            execvp(m.c_str(), beta); //Executes parent/child process
            perror(cmd.c_str());
            exit(0);
       
       default:
        
            if (waitpid(pid, &error, 0) == -1) // Waits for parent/child process to finish
            {
                   perror("Error in wait"); //waits fails
                   return 0;
            }
       
       return error == 0;
        
    }

 
    
}
