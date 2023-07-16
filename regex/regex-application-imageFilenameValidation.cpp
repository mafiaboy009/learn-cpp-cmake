#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    string inputImageFilename;
    const regex imageFilenameRegex("^\\w+\\.(png|jpg|jpeg|gif)$"); // \w should be in actual regex but for C++ it is \\w; similar for \w; \ is \\ in C++

    while (true){

        cout << "Enter the input image filename: ";
        cin >> inputImageFilename;
        if (!cin){
            break;
        }

        // Exit when the user inputs q
        if (inputImageFilename == "q"){
            break;
        }

        if (regex_match(inputImageFilename, imageFilenameRegex)){
            cout << "Input filename is a valid image filename" << endl;
        }
        else{
            cout << "Input filename is an invalid image filename" << endl;
        }
    }

    return EXIT_SUCCESS;
}