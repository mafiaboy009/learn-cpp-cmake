/*
Category C: Implicit User Defined Type Conversion

Defined inside class (user defined type)

There are 2 methods to define implicit user defined type conversion:
Method 1: Use constructor that can accept a single parameter.
-- convert other types of object into your class
Method 2: Use the type conversion function
-- convert an object to your class into other types
*/

#include <iostream>
using namespace std;

class dog{
    public:
        //explicit dog(string name):m_name{name}{} 
        dog(string name):m_name{name}{} // NO Explicit
        // if you only want to define a constructor, and no implicit type
        // conversion, always put "explicit" before the constructor to avoid
        // inadvertent type conversion.
        string getName(){ return m_name;}
        operator string() const { return m_name; }
    private:
        string m_name;
};

int main(){
    string dogname{"Bob"};
    dog dog1 = dogname;
    string dog2 = dog1; // a possible bug
    cout << "My name is " << dog1.getName() << '\n';
    //cout << "My name is " << dog1 << '\n';
    cout << "My name is " << dog2 << '\n';
    return 0;
}

/*
PRINCIPLE: make interface easy to use correctly and hard to use incorrectly.
How hard is enough? Ideally, uncompilable.

General guideline:
1. Avoid defining seemingly unexpected conversion.
2. Avoid defining two-way implicit conversion. i.e., 
if a conversion from type A to type B is implemented, then
avoid writing a conversion from type B to type A
*/
