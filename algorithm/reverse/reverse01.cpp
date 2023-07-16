/*
 * Reverse every word in a sentence
 *
 */
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){

    string line{};
    cout << "Enter a sentence" << endl;
    getline( cin, line);
    cout << line << endl;

    istringstream iss(line);
    string word{};

    while( iss >> word ){
        // reverse() used to reverse a string
        reverse( word.begin(), word.end() ); 
        cout << word << endl;
    }

    return 0;
}
