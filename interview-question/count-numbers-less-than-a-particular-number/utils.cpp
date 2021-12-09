#include "utils.hpp"

// To handle base case of below recursive
// Variadic function Template
void display()
{
	std::cout << "--END--\n";
}

template <typename Head, typename... Tail>
void display(Head head, Tail... tail){
	std::cout << head << "\n";
	display(tail...);
}

template <typename T>
ostream& operator<<(ostream& os, const Array<T>& a){
	os << "[array ";
	for (int i = 0; i<a.Size();i++){
		os << a[i] <<' ';
	}
	os << "]";
	return os;
}

template <typename T>
void swapArray( T& source, T& destination) noexcept {
	using std::swap;
	swap( source.a_ptr, destination.a_ptr );
	swap( source.a_size, destination.a_size );
}

// assumption: vector/array v is sorted in ascending order
template <typename T>
auto binarySearch(T key, T* v, long size){ // O( log(N) ) logarithmic complexity
	auto left = 0;
	auto right = size - 1;

	while(left <= right){
		auto middle = (left + right) / 2;

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
auto linearSearch(T key, T* v, long size){ // O(N) linear complexity
	for( long i = 0; i < size; i++){
		if( key == v[i] )
		{
			return i;
		}
	}
	return INVALID_ARRAY_INDEX;
}

template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& a){
	os << "[stack ";
	for (int i = 0; i < a.Size();i++){
		os << a[i] <<' ';
	}
	os << "]";
	return os;
}
