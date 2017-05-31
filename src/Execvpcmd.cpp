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

   
               string flag;
            string directory;
            if((cmd.at(0) == '[' || cmd.substr(0,4) == "test") && a.size() > 1){
                //do the test command stuff
                if(a.size() == 2){
                    flag = "-e";
                    directory = a.at(1);
                }
                else{
                    flag = a.at(1);
                    directory = a.at(2);
                }
                struct stat sb;
                //const char* dir = new char[directory.size() + 1];
                char temp[1024];
                strcpy(temp, directory.c_str());
                const char* dir = temp;
                if(stat(dir, &sb) == -1){
                    cout << "(False)" << endl;
                    return false;
                }
                if(flag == "-f"){
                    if(S_ISREG(sb.st_mode)){
                        cout << "(True)" << endl;
                        return true;
                    }
                    cout << "(False)" << endl;
                    return false;
                }
                else if(flag == "-d"){
                    if(S_ISDIR(sb.st_mode)){
                        cout << "(True)" << endl;
                        return true;
                    }
                    cout << "(False)" << endl;
                    return false;
                }
                cout << "(True)" << endl;
                return true;
            }
            //size of argv
            int size = a.size() + 2;
            //
            char **argv = new char*[a.size() + 2];
            char *tempcmd = new char[cmd.size()];
            strcpy(tempcmd, cmd.c_str());
            argv[0] = tempcmd;
            for(unsigned i = 0; i < a.size(); ++i){
                char *temparg = new char[a.at(i).size()];
                strcpy(temparg, a.at(i).c_str());
                argv[i + 1] = temparg;
            }
            argv[size - 1] = NULL;

   
   
  
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
