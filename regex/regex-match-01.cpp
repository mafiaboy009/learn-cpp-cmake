#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){

    if (regex_match ("softwareTesting", regex("(soft)(.*)") ))
    cout << "string:literal => matched\n";
 
   const char mystr[] = "SoftwareTestingHelp";
   string str ("software");
   regex str_expr ("(soft)(.*)");
 
   if (regex_match (str,str_expr))
      cout << "string:object => matched\n";
 
   if ( regex_match ( str.begin(), str.end(), str_expr ) )
      cout << "string:range(begin-end)=> matched\n";
 
   cmatch cm;
   regex_match (mystr,cm,str_expr);
    
   smatch sm;
   regex_match (str,sm,str_expr);
    
   regex_match ( str.cbegin(), str.cend(), sm, str_expr);
   cout << "String:range, size:" << sm.size() << " matches\n";
 
   
   regex_match ( mystr, cm, str_expr, regex_constants::match_default );
 
   cout << "the matches are: ";
   for (unsigned i=0; i<sm.size(); ++i) {
      cout << "[" << sm[i] << "] ";
   }
 
   cout << endl;

return 0;
}