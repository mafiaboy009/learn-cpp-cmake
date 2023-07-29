#include <iostream>
#include <random>
using namespace std;

void printInt(int& i)
{
    cout << "lValue reference: " << i << "\n";
}

void printInt(int&& i)
{
    cout << "rValue reference: " << i << "\n";
}

/* uncomment to confuse compiler
void printInt(int i)
{
    cout << "Copy Value: " << i << "\n";
}
*/

int main()
{
    int a = 5;
    while (a > 0)
    {
        printInt(a);      // Call void printInt(int& i)
        printInt(6);      // Call void printInt(int&& i)
        printInt(rand()); // Call void printInt(int&& i)
        --a;
    }
    /*     int& b = a;
        int&& c; */
}