#include <iostream>
#include <memory>

using  namespace std;

int main(){

    auto p = make_unique<int[]>(5);
    //note: make_unique cannot initialize the array elements

    // Initialize the array.
    for (int i = 0; i < 5; ++i)
    {
        p[i] = i;
        cout << p[i] << endl;
    }

    return 0;
}
