/*
 * An array has two types of elements only, viz., 0 and 1
 * Sort the array in O(n)
 *
 */

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

void displayArray(const array<int, 11>& boolArray){
    for( auto& a: boolArray ){
        cout << a << " ";
    }
    cout << endl;
}

int main(){

    const int size{11};
    array<int, size> boolArray = {1,0,1,0,1,1,0,1,1,0,1};
    //array<int, size> boolArray = {1,1,1,1,1,1,1,1,1,1,1};
    //array<int, size> boolArray = {0,0,0,0,0,0,0,0,0,0,0};

    displayArray( boolArray );

    int countZero{0};
    for(int i=0; i < size; ++i ){ // O(n)
        if( boolArray[i] == 0 ){
            ++countZero;
        }
    }

    for(int i=0; i<countZero; ++i){ // O(n)
        boolArray[i]=0;
    }

    for(int i=countZero; i<size; ++i){ // O(1)
        boolArray[i]=1;
    }

    displayArray( boolArray );

    return 0;
}
