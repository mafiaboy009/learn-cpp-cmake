#pragma once
#include <iostream>
#include <array>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const array<T,3>& a){
	os << "[array ";
	for ( int i = 0; i < static_cast<int>( a.size()); i++ ){
		os << a[i] <<' ';
	}
	os << "]";
	return os;
}
