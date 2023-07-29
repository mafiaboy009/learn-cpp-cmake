#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> deq{4,6,7};
    deq.push_front(2);
    deq.push_back(3);

    for(auto d:deq)
    {
        cout << d;
    }
    cout << "\n";

    return EXIT_SUCCESS;
}