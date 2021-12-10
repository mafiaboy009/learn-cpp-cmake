/*
User Defined Implicit Type Conversion

Categories of Type Conversion:
                              Implicit      Explicit
Standard Type Conversion        A             B
User Defined Type Conversion    C             D ( casting )


*************************************************
Category A: Implicit Standard Type Conversion

char c = 'A';
int i = c; // Integral promotion
char *pc = 0; // int -> nullptr
void f(int i);
f(c);// char c is implicitly converted to int
dog *pd = new yellowdog(); // pointer type conversion; note this is not user defined type conversion

******************************************************
Category C: Implicit User Defined Type Conversion

Defined inside class (user defined type)

There are 2 methods to define implicit user defined type conversion:
Method 1: Use constructor that can accept a single parameter.
-- convert other types of object into your class
Method 2: Use the type conversion function
-- convert an object to your class into other types
*/
class dog{
public:
dog(string name):m_name{name}{} // NO Explicit
// if you only want to define a constructor, and no implicit type
// conversion, always put "explicit" before the constructor to avoid
// inadvertent type conversion.
string getName(){ return m_name;}
operator string () const { return m_name; }
private:
string m_name;
};

int main(){

string dogname = "Bob";
dog dog1 = dogname;
string dog2 = dog1; // a possible bug
cout << "My name is << dog1.getName() << '\n';
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

/*
******************************************************
Category D: Explicit Type Conversion are called Casting

Four types
- static_cast - related type
- dynamic_cast - related type
- const_cast - same type
- reinterpret_cast -any type

NOTE: avoid using C-stype casting; USE C++-style casting only
