#ifndef UTILS_CPP
#define UTILS_CPP

#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Array;

template <class T>
class Stack;

const long INVALID_ARRAY_INDEX = -1;
// To handle base case of below recursive
// Variadic function Template
void display();

template <typename Head, typename... Tail>
void display(Head head, Tail... tail);

template <typename T>
ostream& operator<<(ostream& os, const Array<T>& a);

template <typename T>
void swapArray( T& source, T& destination) noexcept;

// assumption: vector/array v is sorted in ascending order
template <typename T>
auto binarySearch(T key, T* v, long size);

template <typename T>
auto linearSearch(T key, T* v, long size);

template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& a);

#endif
