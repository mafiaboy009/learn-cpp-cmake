/*
 * A person has 'n' chocolates and after its consumption
 * there are 'n' wrappers. These wrappers can be exchanged 
 * to get new chocolates, i.e., if you give 'k' wrappers, 
 * then you get 1 chocolate.
 *
 * Write a program to find the number of chocolates a person
 * can consume, given 'n' and 'k'.
 *
 */

#include<iostream>

using namespace std;

// n : number of chocolates; k : recycle rate
int numberOfChoclatesConsumed (int n, int k){

    int totalNumberOfChocolates = n;
    int totalNumberOfWrappers = n;

    if( n < k ){
        return totalNumberOfChocolates;
    }

    while( totalNumberOfWrappers >= k ){
        totalNumberOfChocolates += totalNumberOfWrappers/k;
        totalNumberOfWrappers = ( totalNumberOfWrappers/k ) + ( totalNumberOfWrappers%k );
    }

    return totalNumberOfChocolates;
}

int main(){
    int startNumberOfChocolates{}, rateOfRecycle{};
    cout << "Enter number of chocolates and rate of recycle" << '\n';
    cin >> startNumberOfChocolates >> rateOfRecycle;
    cout << numberOfChoclatesConsumed( startNumberOfChocolates, rateOfRecycle ) << '\n';
    return 0;
}
