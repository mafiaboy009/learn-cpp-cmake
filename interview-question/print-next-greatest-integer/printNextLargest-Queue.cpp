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
    //array< int, arraySize > intArray = {1, 1, 1, 1};
    //array< int, arraySize > intArray = {2, 1, 1, 1};
    array< int, arraySize > intArray = {1, 2, 3, 4};
    //array< int, arraySize > intArray = {1, 3, 2, 4};
    queue< int > intQueue;

    for(int i = 0; i < arraySize; i++ ){

        if( i == 0 ){
            intQueue.push( intArray[i] );
            continue;
        }

        if( intArray[i] > intQueue.front() ){
            while( intArray[i] > intQueue.front() && !intQueue.empty() ){
                cout << intArray[i] << ' ';
                intQueue.pop();
            }
            intQueue.push( intArray[i] );
        }
        else{
            intQueue.push( intArray[i] );
        }

    }

    while( !intQueue.empty() ){
        cout << -1 << ' ';
        intQueue.pop();
    }

    cout << '\n';

    return EXIT_SUCCESS;
}
