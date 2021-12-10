/*
 * const_cast can be used to pass const data to a function that doesn’t receive const. 
 *
 * For example, in the following program fun() receives a normal pointer, 
 * but a pointer to a const can be passed with the help of const_cast.
 *
 */

#include <iostream>
using namespace std;

int fun(int* ptr)
{
    cout << "fun ptr " << ptr << '\n';
    *ptr=20; // this line has no effect on the val in main function;
	return (*ptr+10);
}

int main(void)
{
	const int val = 10;
	const int *ptr = &val;
	int *ptr1 = const_cast<int*>(ptr);
    cout << "ptr " << ptr << '\n';
    cout << "ptr1 " << ptr1 << '\n';
	cout << "val " << val << '\n';
	cout << fun(ptr1) << '\n';
	cout << "val " << val << '\n';
	return 0;
}
