/*
IBM Interview Question
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
/*  
    int const size = 4;
    int arr[size] = {-5,-4,4,-9}; 
*/
    int const size = 19;
    int arr[] = {-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9};
    int inNum{};
    while(true)
    {
        cout << "Enter number: ";
        cin >> inNum;
        set<int> diffSet{};
        vector<int> record{};
        int combos{};
        for( unsigned i=0; i < size; ++i )
        {
            if( inNum == arr[i] )
            {
                ++combos;
                record.push_back(arr[i]);
            }
            if( diffSet.find( arr[i] ) != diffSet.end() )
            {
                ++combos;
                record.push_back(arr[i]);
            }
            int diff = inNum - arr[i];
            diffSet.insert( diff );
        }
        cout << "No. of combinations : " << combos << "\n";
        for(auto v: record){
            cout << v << " ";
        }
        cout << "\n\n";
    }
    return EXIT_SUCCESS;
}