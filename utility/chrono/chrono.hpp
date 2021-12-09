#pragma once
#include <iostream>
#include <chrono>

using namespace std;

const int INVALID_ARRAY_INDEX = -1;

// assumption: vector/array v is sorted in ascending order
template <typename T>
int binarySearch( T key, T* v, int size ){ // O( log(N) ) logarithmic complexity

    int left{0};
    int right{size-1};
	while(left <= right){
		int middle = (left + right) / 2;

		if( v[middle] == key ){
			return middle;
		}

		if( key < v[middle] ){
			right = middle-1;
		}

		if( key > v[middle] ){
			left = middle+1;
		}
	}
	return INVALID_ARRAY_INDEX;
}


template <typename T>
auto linearSearch(T key, T* v, int size){ // O(N) linear complexity
	for( int i = 0; i < size; i++){
		if( key == v[i] )
		{
			return i;
		}
	}
	return INVALID_ARRAY_INDEX;
}
