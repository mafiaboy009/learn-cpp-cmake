#include <iostream>
#include <regex>
#include <string>
using namespace std;
  
int main()
{
    string input;
    regex integer_expr("(\\+|-)?[[:digit:]]+");
    //As long as the input is correct ask for another number
    while(true)
    {
        cout<<"Enter the input: ";
        cin>>input;
        if(!cin) break;
        //Exit when the user inputs q
        if(input=="q")
            break;
        if(regex_match(input,integer_expr))
            cout<<"Input is an integer"<<endl;
        else
        {cout<<"Invalid input : Not an integer"<<endl;}
    }
}