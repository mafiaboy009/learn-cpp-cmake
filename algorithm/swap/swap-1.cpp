#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArray(T* array, int size ){
    if( array == nullptr || size == 0 ){
        return;
    }
    for( int i=0; i < size; ++i ){
        cout << array[i] << " ";
    } 
    cout << '\n';
}

int main(){
    const int size{10};
    int *arrayToBeSorted = new int[size];
    for( int i=0; i < size; ++i ){
        arrayToBeSorted[size-i-1] = i;
    } 
    printArray( arrayToBeSorted, size );

    for( int* ptr1 = arrayToBeSorted; ptr1 < arrayToBeSorted+size; ++ptr1 ){
        for( int* ptr2 = arrayToBeSorted; ptr2 < arrayToBeSorted+size-1; ++ptr2 ){
            if( *ptr2 > *(ptr2+1) ){
                swap( *ptr2, *(ptr2+1) );
            }
        }
    }
    printArray( arrayToBeSorted, size );

    return 0;
}
