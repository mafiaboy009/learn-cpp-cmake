#include "count-numbers-less-than-a-particular-number.hpp"

int main(){
    const int size{10};
    int sortedArray[]={ 18, 27, 36, 45, 54, 63, 72, 81, 90, 99 };
    int interestedNumber{45};

    cout << "18, 27, 36, 45, 54, 63, 72, 81, 90, 99\n";
    while( true ){
        cout << "Enter interested number\n";
        cin >> interestedNumber;

        int index = binarySearch( interestedNumber, sortedArray, size );

        if( index == INVALID_ARRAY_INDEX ){
            cout << "choose a number from list!\n";
        }
        else{
            cout << "There are " << size-size+index  << " numbers less than " << interestedNumber << '\n';
        }
    }

    return 0;
}
