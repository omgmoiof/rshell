#include "Execvpcmd.h"

using namespace std;

Execvpcmd::Execvpcmd(std::string& s) : Command(s)
{
    int start = s.find_first_not_of(" ");
    int end = s.find_last_not_of(" ");
    cmd = s.substr(start, end - start + 1);
}

bool Execvpcmd::run()
{
   stringstream s;
   s.str(cmd);
   vector<string> a; //puts the commands in a vector of strings
   string m, n;
   s >> m;
   a.push_back(m);
   while(s >> n)
   {
       a.push_back(n);
   }
   
   char ** b = new char * [a.size() + 1];
   
   for (unsigned i = 0; i < a.size(); i++)
   {
       b[i] = (char *)(a[i].c_str());
   }
   
   b[a.size()] = NULL;

   
    string flag; //for detection of the -e, -f, and -d flags
    string info;
    
    if((cmd.at(0) == '[' || cmd.substr(0,4) == "test") && a.size() > 1)
    {
                
        if(a.size() != 2)
        {
            flag = a.at(1);
            info = a.at(2);
        }
        
        else
        {
                    
            flag = "-e";
            info = a.at(1);
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
        
        if(flag == "-f")
        {
            if(S_ISREG(testf.st_mode) == false)   //Checks if it exists and is a file
            {
                cout << "(False)" << endl; //Prints out (False) if it does not exists or is not a file
                return false;

            }
                cout << "(True)" << endl;  //Prints out (True) if it exists and is a file
                return true;
                
        }
        else if(flag == "-d")
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
  
  int pid = fork();
    switch(pid) //makes parent and child
    {
        
        case -1: //Forking fail
            perror("Error in forking");
            return 0;
        
        case 0: //creates parent and child
        
            execvp(m.c_str(), b);
            perror(cmd.c_str());
            exit(0);
       
       default:
        
            if (waitpid(pid, &error, 0) == -1) //wait until parent/child dies
            {
                   perror("Error in wait"); //wait fails
                   return 0;
            }
       
       return error == 0;
        
    }
}
