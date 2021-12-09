/*
 * sort( begin, end, [criteria] )
 *
 * begin: start location
 * end : end location
 * []: optional
 * criteria: greater, lesser, or our own(expressed through lambda function)
 *
 */
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

    // sort in ascending order
    sort( arrayToBeSorted, arrayToBeSorted+size );
    printArray( arrayToBeSorted, size );

    // sort in descending order
    sort( arrayToBeSorted, arrayToBeSorted+size, greater<int>() );
    printArray( arrayToBeSorted, size );

    return 0;
}
