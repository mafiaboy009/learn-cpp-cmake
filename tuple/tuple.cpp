#include <iostream>
#include <tuple>
using namespace std;

int main()
{
    tuple<char, int, string> aTup{'a',1,"abc"};
    cout << get<0>( aTup ) << "\n";
    cout << get<1>( aTup ) << "\n";
    cout << get<2>( aTup ) << "\n";
    return EXIT_SUCCESS;
}