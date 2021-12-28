#include <iostream>
#include <map>

using namespace std;

void printWordsFromEndOfLine(string inLine){
    map<int, int> wordPos{};
    int startPos{0};
    for( unsigned int i=0; i < inLine.length(); ++i){
        if( inLine[i] == ' ' ){
            wordPos.insert({startPos, i-startPos});
            startPos = i+1;
        }
    }
    wordPos.insert({startPos, inLine.length()});

    for( auto iter = wordPos.rbegin(); iter != wordPos.rend(); ++iter ){
        cout << inLine.substr(iter->first, iter->second) << " ";
    }
    cout << '\n';
}

int main(){
    string inLine;
    cout << "Enter sentence:\n";
    getline(cin, inLine);
    printWordsFromEndOfLine(inLine);
    return 0;
}
