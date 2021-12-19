/*
 * Input: AAABBCDDFAGG
 * Outout: 3A2B2D2G
 */


#include <iostream>

using namespace std;


int main(){

    string input{};

    cout << "Enter string\n";
    cin >> input;
    int i{0};

    while( input[i] != '\0' ){
        int count{1};
        while( input[i] == input[i+1] )
        {
            ++count;
            ++i;
        }
        if( count > 1 ){
            cout << count << input[i];
        }
        ++i;
    }
    return 0;
}
