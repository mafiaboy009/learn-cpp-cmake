#include <iostream>
#include <sstream>

using namespace std;

string reverseString( string word ){
    string revWord(word.length(), ' ');
    for( int i=word.length()-1, j=0; i >= 0; --i, ++j){
        revWord[j] = word[i];
    }
    return revWord;
}

int main(){

    string line{};
    getline( cin, line);
    cout << line << endl;

    istringstream iss(line);
    string word{};

    while( iss >> word ){
        cout << reverseString( move(word) ) << endl;
    }

    return 0;
}
