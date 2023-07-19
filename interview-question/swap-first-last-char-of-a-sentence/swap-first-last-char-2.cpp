/*
Oracle Interview
URL: https://app.coderpad.io/944GHN9Q
URL: https://app.coderpad.io/login?login_challenge=2912825072da466e893b2b6a8eb3e92d
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){

    const char aSpacebar = ' ';

    string sentence{};
    cout << "Enter the sentence:\n";
    getline(cin, sentence);

    unsigned sentenceSize = sentence.length();
    //cout << "The input sentence has " << sentenceSize << " characters.\n";

    unsigned i{0},j{1};
    while( i <= j && j < sentenceSize){
        while( j < sentenceSize && sentence.at(j) != '\0' && sentence.at(j) != aSpacebar ){
            ++j;
        }
        char lastChar = sentence[j-1];
        sentence[j-1] = sentence[i];
        sentence[i] = lastChar;
        unsigned k = j++;
        while(k < sentenceSize && sentence.at(k) == aSpacebar){
            ++k;
        }
        i = k;
        j = k;
    }

    cout << sentence << "\n";
    return EXIT_SUCCESS;
}