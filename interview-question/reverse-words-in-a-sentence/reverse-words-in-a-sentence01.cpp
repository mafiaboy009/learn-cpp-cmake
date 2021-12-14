#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string line{};
    getline( cin, line);
    cout << line << endl;

    istringstream iss(line);
    string word{};

    while( iss >> word ){
        reverse( word.begin(), word.end() );
        cout << word << endl;
    }

    return 0;
}
