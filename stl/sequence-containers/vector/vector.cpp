#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1{1,2,3};
    vector<int> v2(move(v1));
    vector<int> v3(v2);
    cout << "v1 size: " << v1.size() << endl;
    cout << "v2 size: " << v2.size() << endl;
    cout << "v3 size: " << v3.size() << endl;

    v1.swap(v3);
    cout << "v1 size: " << v1.size() << endl;
    cout << "v2 size: " << v2.size() << endl;
    cout << "v3 size: " << v3.size() << endl;

    return EXIT_SUCCESS;
}