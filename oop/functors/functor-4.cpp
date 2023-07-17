// C++ Predefined Functors
// more on functors: https://www.programiz.com/cpp-programming/functors

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main() {

  // initialize vector of int
  vector<int> nums = {1, 20, 3, 89, 2};

  sort(nums.begin(), nums.end());

  for(auto num: nums) {
    cout << num << ", ";
  }

  cout << endl;

  // sort the vector in descending order
  sort(nums.begin(), nums.end(), greater<int>());

  for(auto num: nums) {
    cout << num << ", ";
  }

  return 0;
}