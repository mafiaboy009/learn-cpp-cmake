#include "chrono.hpp"

int main(){
    const int size{10};
    int sortedArray[]={ 18, 27, 36, 45, 54, 63, 72, 81, 90, 99 };
    int interestedNumber{45};

    cout << "18, 27, 36, 45, 54, 63, 72, 81, 90, 99\n";
    while( true ){
        cout << "Enter interested number\n";
        cin >> interestedNumber;

        auto t0 = chrono::high_resolution_clock::now();
        int index1 = binarySearch( interestedNumber, sortedArray, size );
        auto t1 = chrono::high_resolution_clock::now();
        int index2 = linearSearch( interestedNumber, sortedArray, size );
        auto t2 = chrono::high_resolution_clock::now();
        cout << "binarySearch took " << chrono::duration_cast<chrono::milliseconds>(t1-t0).count() << "mS\n";
        cout << "linearSearch took " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << "mS\n";

        if( index1 != index2 ){
            cout << "Amigo!! bad algos" << endl;
        }


        if( index1 == INVALID_ARRAY_INDEX ){
            cout << "choose a number from list!\n";
        }
        else{
            cout << "Key found at position " << index1 << '\n';
            cout << "There are " << size-size+index1  << " numbers less than " << interestedNumber << '\n';
        }
    }

    return 0;
}
