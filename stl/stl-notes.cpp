#include <iostream>

using namespace std;

const string notes{R"(
/*
 * Standard Template Library - STL
 *
 * Algorithm never works directly on the Containers
 * Algorithm works on Iterators
 *
 * Reasons to use C++ standard library:
 * 1. Code reuse, no need to re-invent the wheel
 * 2. Efficiency (fast and use less resources). Modern C++ compiler are usually tuned to optimize for C++ standard library code
 * 3. Accurate, less buggy
 * 4. Terse, readable code; reduced control flow
 * 5. Standardization, guaranteed availability
 * 6. A role model of writing library
 * 7. Good knowledge of data structures and algorithms
 *
 * Containers
 * -- there are 3 types of containers
 *  ---- Sequence Containers ( array and linked list ):
 *  ------ vector, deque, list, forward_list, array
 *  ---- Associative Containers ( binary tree ):
 *  ------ set, multiset
 *  ------ map, multimap
 *  ---- Unordered Containers ( hash table ):
 *  ------ unordered_set, unordered_multiset
 *  ------ unordered_map, unordered_multimap
 *
 * Headers
 * #include <vector>
 * #include <deque>
 * #include <list>
 * #include <set> // set and multiset
 * #include <map> // map and multimap
 * #include <unordered_set> // unordered_set/unordered_multiset
 * #include <unordered_map> // unordered_map/unordered_multimap
 * #include <iterator>
 * #include <algorithm>
 * #include <numeric> // some numeric algorithm
 * #include <functional> // for the functors
 *
 */)"};

int main(){

    cout << notes << endl;
    return 0;
}
