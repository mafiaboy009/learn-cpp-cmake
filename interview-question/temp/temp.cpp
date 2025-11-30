/*
1018. Binary Prefix Divisible By 5

Easy

You are given a binary array nums (0-indexed).

We define xi as the number whose binary representation is the subarray nums[0..i] (from most-significant-bit to least-significant-bit).

For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.
Return an array of booleans answer where answer[i] is true if xi is divisible by 5.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printVector( const vector<bool>& vec ){
    for( const auto& val : vec ){
        if( val ){
            cout << "true ";
        }
        else{
            cout << "false ";
        }
    }
    cout << endl;
}

vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> returnBoolVec(nums.size());
        int num = 0;
        for(int i=0; i < nums.size(); ++i ){
            int twoPow = pow(2,i );
            num = num + (nums[i]*twoPow);
            if( num % 5 == 0){
                returnBoolVec[i] = true;
            }
            else
            {
                returnBoolVec[i] = false;
            }
        }
        return returnBoolVec;
    }

int main() {

    vector<int> nums = {1,1,0,0,0,1,0,0,1};
    vector<bool> result = prefixesDivBy5( nums );

    printVector(result);

    return 0;       
}