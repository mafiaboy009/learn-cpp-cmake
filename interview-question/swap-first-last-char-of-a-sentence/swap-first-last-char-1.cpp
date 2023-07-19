/*
URL: https://app.coderpad.io/944GHN9Q
URL: https://app.coderpad.io/login?login_challenge=2912825072da466e893b2b6a8eb3e92d
*/

#include <iostream>
#include <sstream>
using namespace std;

int main(){

    string sentence{};
    cout << "Enter the sentence:\n";
    getline(cin, sentence);

    istringstream strStream{sentence};
    string word{};

    while(strStream >> word){
        //cout << "word length: " << word.length() << endl;
        char temp = word[0];
        word[0] = word[word.length()-1];
        word[word.length()-1] = temp;
        cout << word << " ";
    }

    cout << "\n";

    return EXIT_SUCCESS;
}