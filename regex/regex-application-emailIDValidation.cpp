#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    string inputEmailID{};
    const regex emailRegex("^\\w+([.-]?\\w+)*@\\w+([.-]?\\w+)*(\\.\\w{2,3})+$");

    while (true){

        cout << "Enter an email ID: ";
        cin >> inputEmailID;
        if (!cin){
            break;
        }

        // Exit when the user inputs q
        if (inputEmailID == "q"){
            break;
        }

        if (regex_match(inputEmailID, emailRegex)){
            cout << "Email ID is valid." << endl;
        }
        else{
            cout << "Email ID is NOT valid." << endl;
        }
    }

    return EXIT_SUCCESS;
}