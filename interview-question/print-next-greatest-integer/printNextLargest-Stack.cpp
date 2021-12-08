#include<iostream>

#include<array>
#include<stack>
#include<queue>

using namespace std;

void showQ( queue<int> g )
{
    cout << "* Queue *\n";
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

void showStack( stack<int> g )
{
    cout << "* Stack *\n";
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

int main(){

    const int arraySize = 4;
    //array< int, arraySize > intArray = {1, 1, 1, 2};
    array< int, arraySize > intArray = {1, 1, 1, 1};
    //array< int, arraySize > intArray = {2, 1, 1, 1};
    //array< int, arraySize > intArray = {1, 3, 2, 4};
    stack< int > intStack;

    for(int i = arraySize-1; i >= 0; i-- ){
            intStack.push( intArray[i] );
    }

    for(int i = 0; i < arraySize; i++ ){
        if( intArray[i] > intStack.top() ){
            while( intArray[i] > intStack.top() && !intStack.empty() ){
                cout << intArray[i] << ' ';
                intStack.pop();
            }
        }
    }

    while( !intStack.empty() ){
        cout << -1 << ' ';
        intStack.pop();
    }

    cout << '\n';

    return EXIT_SUCCESS;
}
