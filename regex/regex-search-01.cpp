#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
     //string to be searched
    string mystr = "She sells_sea shells in the sea shore"; 
   
    // regex expression for pattern to be searched 
    regex regexp("s[a-z_]+"); 
   
    // flag type for determining the matching behavior (in this case on string objects)
    smatch m; 
   
    // regex_search that searches pattern regexp in the string mystr  and returns the first occurence
    regex_search(mystr, m, regexp); 
  
    cout<<"String that matches the pattern:"<<endl;
    for (auto x : m) 
        cout << x << " "; 
    
    return EXIT_SUCCESS;
}