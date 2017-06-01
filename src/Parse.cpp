#include "Parse.h"
#include <iostream>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stack>



#include <sys/types.h>

#include <unistd.h>
//#define delimitor ";#"                    // token separators

using namespace std;

Parse::Parse() { }


void Parse::run()
{
    string input;
    Runcmd* inputCommand = NULL;
    while(true)
    {
        cout << "$ ";
        getline(cin, input);
        inputCommand = parse(input);
        if (inputCommand != NULL)
        {
            inputCommand->run();
            inputCommand = NULL;
            
        }
        
        
    }
    
    
}

Runcmd* Parse::parse(string& s)
{
    if (s.size() == 0) return NULL;
    if (s.find_first_not_of(" ") == string::npos) return NULL;
    
    if (s.find('#') != string::npos)
    {
        int loc = s.find('#');
        s = s.substr(0,loc);
        return parse(s);
        
    }
    

    bool par = false;
    string parenth_part = "";
    for (unsigned i = 0; i < s.length(); i++)
    {
        
        if (s.at(i) == '(' )
        {
            if (s.find(')') == string::npos)
            {
                cout << "Error, could not find matching ')'" << endl;
                return NULL;
            }
            
            stack<int> p;
            int end;
            p.push(i);
            for (unsigned int j = i + 1; p.size() > 0; j++ )
            {
                if (s.at(j) == '(') p.push(j);
                if (s.at(j) == ')') p.pop();
                
                end = j;
            }
            
            parenth_part = s.substr(i+1, end - i - 1);
            par = true;
            i = end;
            
            
            
            
        }
        
        if(s.at(i) == ';' )
        {
            
            int size = s.length();

            string lhs = s.substr(0,i);
            string rhs = s.substr(i+1,size);
            
            Semicolon* b;
            if (par) b = new Semicolon(parse(rhs),parse(parenth_part));
            else b = new Semicolon(parse(rhs),parse(lhs));
            return b;
        }
        
        if (s.at(i) == '|' && s.at(i+1) == '|')
        {
            
            int size = s.length();
            string lhs = s.substr(0,i);
            string rhs = s.substr(i+2,size);
            
            Or* c;
            if (par) c = new Or(parse(rhs),parse(parenth_part));
            else c = new Or(parse(rhs),parse(lhs));
            return c;
            
        }
        
        if (s.at(i) == '&' && s.at(i+1) == '&')
        {
            
            int size = s.length();
            string lhs = s.substr(0,i);
            string rhs = s.substr(i+2,size);
            
            And* d;
            if (par) d = new And(parse(rhs),parse(parenth_part));
            else d = new And(parse(rhs),parse(lhs));
            return d;
            
        }
        
        if (s.substr(i,4) == "exit" && (s.length() == i+4 || s.at(i+4) == ' '))
        {
        
            Exit* ex = new Exit();
            return ex;
        
        }
        
         
        
        
        
        
        
    }
    
    
    Runcmd* g;
    if (par) g = parse(parenth_part);
    else g = new Execvpcmd(s);
    return g;
    
    
    
}
