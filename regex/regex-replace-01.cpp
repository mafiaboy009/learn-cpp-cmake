#include <iostream> 
#include <string> 
#include <regex> 
#include <iterator> 

using namespace std; 
   
int main() 
{  
    string mystr = "This is software testing Help portal \n"; 
     
    cout<<"Input string: "<<mystr<<endl;
       
    // regex to match string beginning with 'p' 
    regex regexp("p[a-zA-z]+"); 
    cout<<"Replace the word 'portal' with word 'website' : "; 
    // regex_replace() for replacing the match with the word 'website'  
    cout << regex_replace(mystr, regexp, "website"); 
     
    string result; 
       
    cout<<"Replace the word 'website' back to 'portal': ";
    // regex_replace( ) for replacing the match back with 'portal' 
    regex_replace(back_inserter(result), mystr.begin(), mystr.end(), 
                  regexp,  "portal"); 
   
    cout << result; 
   
    return 0; 
}