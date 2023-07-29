#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void print(list<int>& mylist)
{
    for(auto li : mylist)
    {
        cout << li << " ";
    }
    cout << "\n";
}

int main()
{
    list<int> mylist{5,2,9};
    mylist.push_back(6);
    mylist.push_front(4);
    print(mylist);
    list<int>::iterator itr = find(mylist.begin(), mylist.end(), 2);
    mylist.insert(itr,8);
    print(mylist);
    itr++;
    mylist.erase(itr);
    print(mylist);

    list<int> mylist2;
    print(mylist2);
    mylist2.splice(mylist2.begin(), mylist, ++mylist.begin(), --mylist.end());
    print(mylist2);
    return EXIT_SUCCESS;
}