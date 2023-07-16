#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main(){

    const int size{11};
    array<int, size> boolArray = {1,0,1,0,1,1,0,1,1,0,1};
    //array<int, size> boolArray = {1,1,1,1,1,1,1,1,1,1,1};
    //array<int, size> boolArray = {0,0,0,0,0,0,0,0,0,0,0};

    for( auto& a: boolArray ){
        cout << a << " ";
    }
    cout << endl;

    /*
    // bubble sort; O(n^2)
    for( int i=0; i<size; ++i ){
        for( int j=0; j < size-1; ++j ){
            if( boolArray[j] > boolArray[j+1]){
                swap( boolArray[j], boolArray[j+1]);
            }
        }
    }
    */
    
    // O(n); 
    int i{0}, j{size-1};
    int foundI{-1}, foundJ{-1};
    while( i < j ){

        bool foundZero = false;
        bool foundOne = false;

        while( j > 0 ){
            if( boolArray[j] == 0 ){
                foundJ = j;
                foundZero = true;
                --j;
                break;
            }
            --j;
        }

        while( i < size ){
            if( boolArray[i] == 1 ){
                foundI = i;
                foundOne = true;
                ++i;
                break;
            }
            ++i;
        }

        if( foundZero && foundOne && i < j ){
            swap( boolArray[foundI], boolArray[foundJ] );
        }

    }

    cout << "foundI " << foundI << endl;
    cout << "foundJ " << foundJ << endl;

    for( auto& a: boolArray ){
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
