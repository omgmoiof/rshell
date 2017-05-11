
#include "Parse.h"
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
    
    
    for (unsigned i = 0; i < s.length(); i++)
    {
        if(s.at(i) == ';' )
        {
            
            int size = s.length();
            string lhs = s.substr(0,i);
            string rhs = s.substr(i+1,size);
            
            Semicolon* b = new Semicolon(parse(rhs),parse(lhs));
            return b;
        }
        
        if (s.at(i) == '|' && s.at(i+1) == '|')
        {
            
            int size = s.length();
            string lhs = s.substr(0,i);
            string rhs = s.substr(i+2,size);
            
            Or* c = new Or(parse(rhs),parse(lhs));
            return c;
            
        }
        
        if (s.at(i) == '&' && s.at(i+1) == '&')
        {
            
            int size = s.length();
            string lhs = s.substr(0,i);
            string rhs = s.substr(i+2,size);
            
            And* d = new And(parse(rhs),parse(lhs));
            return d;
            
        }
        
        if (s.at(i) == 'e' && s.at(i+1) == 'x' && s.at(i+2) == 'i' && s.at(i+3) == 't')
        {
        
            Exit* ex = new Exit();
            return ex;
        
        }
        
    }
    
    Execvpcmd* f = new Execvpcmd(s);
    return f;
    
    
    
    
}
