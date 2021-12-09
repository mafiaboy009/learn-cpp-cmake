#pragma once

#include <iostream>

using namespace std;


// To handle base case of below recursive
// Variadic function Template
void display()
{
    cout << "--END--\n";
}

template <typename Head, typename... Tail>
void display(Head head, Tail... tail){
    cout << head << "\n";
    display(tail...);
}

