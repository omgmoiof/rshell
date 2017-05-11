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
   vector<string> a;
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
   
  
   int error;
  
  int pid = fork();
    switch(pid)
    {
        
        case -1:
        perror("Error in forking");
       return 0;
        
        case 0:
        
         execvp(m.c_str(), b);
       perror(cmd.c_str());
       exit(0);
       
       default:
        
         if (waitpid(pid, &error, 0) == -1)
       {
           perror("Error in wait");
           return 0;
       }
       
       return error == 0;
        
    }

 
    
}
