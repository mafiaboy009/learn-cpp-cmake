#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    while (true)
    {
        string str1{}, str2{};
        cout << "Enter string1: \n";
        cin >> str1;
        cout << "Enter string2: \n";
        cin >> str2;

        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        if (str1.length() != str2.length())
        {
            cout << "Not an anagram\n";
        }
        else
        {
            if (!strcmp(str1.c_str(), str2.c_str()))
            {
                cout << "Is an anagram\n";
            }
            else
            {
                cout << "Not an anagram\n";
            }
        }
    }
    return EXIT_SUCCESS;
}