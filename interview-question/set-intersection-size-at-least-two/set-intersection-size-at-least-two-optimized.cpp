/*
URL: https://leetcode.com/problems/set-intersection-size-at-least-two

You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.

A containing set is an array nums where each interval from intervals has at least two integers in nums.

For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
Return the minimum possible size of a containing set.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void printSet(string str, const std::set<int> &s)
{
    cout << str << ": " << endl;
    for (int elem : s)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int intersectionSizeTwo(vector<vector<int>> &intervals)
{
    auto cmp = [](const vector<int> &a, const vector<int> &b)
    {
        if (a[1] != b[1])
            return a[1] < b[1];
        return a[0] > b[0];
    };

    sort(intervals.begin(), intervals.end(), cmp);

    int ans = 0;
    int first = INT_MIN, second = INT_MIN; // first < second, the two largest chosen points so far

    std::set<int> resultSet;

    for (auto &iv : intervals)
    {
        int l = iv[0], r = iv[1];
        int cnt = 0;
        if (first >= l)
            ++cnt;
        if (second >= l)
            ++cnt;

        if (cnt >= 2)
            continue;

        if (cnt == 1)
        {
            // add one point: r
            ++ans;
            first = second;
            second = r;
            resultSet.insert(second);
        }
        else
        { // cnt == 0
            // add two points: r-1 and r
            ++ans;
            ++ans;
            first = r - 1;
            second = r;
            resultSet.insert(first);
            resultSet.insert(second);
        }
    }
    printSet("final resultSet", resultSet);
    return ans;
}

int main()
{
    std::cout << "-- Set Intersection Size At Least Two --" << std::endl;

    //vector<vector<int>> intervals = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
    //vector<vector<int>> intervals = {{1,3}, {3,7}, {8,9}};
    //vector<vector<int>> intervals = {{1,2}, {2,3}, {2,4}, {4,5}};
    vector<vector<int>> intervals = {{1,3}, {3,7}, {5,7}, {7,8}};
    int result = intersectionSizeTwo(intervals);
    std::cout << "Minimum size of a containing set: " << result << std::endl;

    return 0;
}
