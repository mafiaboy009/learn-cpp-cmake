#include <iostream>
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
    printInt(a); // Call void printInt(int& i)
    printInt(6); // Call void printInt(int&& i)
/*     int& b = a;
    int&& c; */
}