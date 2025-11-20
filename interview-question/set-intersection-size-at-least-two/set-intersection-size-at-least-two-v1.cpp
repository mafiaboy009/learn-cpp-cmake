/*
URL: https://leetcode.com/problems/set-intersection-size-at-least-two

You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.

A containing set is an array nums where each interval from intervals has at least two integers in nums.

For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
Return the minimum possible size of a containing set.

*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

void printSet(string str, const std::set<int> &s);

int intersectionSizeTwo(vector<vector<int>> &intervals)
{
    std::set<int> *intervalSet = new std::set<int>[intervals.size()];
    int idx = 0;
    for (vector<int> &interval : intervals)
    {
        int i = interval[0];
        int j = interval[1];
        for (; i <= j; ++i)
        {
            intervalSet[idx].insert(i);
        }
        ++idx;
    }

/*     for (int i = 0; i < idx; ++i)
    {
        cout << "Interval " << i << ": ";
        printSet("-- interval --", intervalSet[i]);
    }  */

    int combinations = idx * (idx - 1) / 2;

    // Create an array to store the intersections
    std::set<int> intersections[combinations];

    int index = 0;
    // Find the intersection of all combinations of 2 sets
    for (int i = 0; i < idx; ++i) {
        for (int j = i + 1; j < idx; ++j) {
            std::set_intersection(intervalSet[i].begin(), intervalSet[i].end(),
                                  intervalSet[j].begin(), intervalSet[j].end(),
                                  std::inserter(intersections[index], intersections[index].begin()));
            index++;
        }
    }

    for (int i = 0; i < combinations; ++i)
    {
        cout << "Intersections " << i << ": ";
        printSet("-- intersection --",intersections[i]);
    }

    // Create a set to store the union
    std::set<int> unionSet;

    // Find the union of all sets
    for (int i = 0; i < idx; ++i) {
        unionSet.insert(intervalSet[i].begin(), intervalSet[i].end());
    }

    printSet("-- union set --",unionSet);

    // initial result set
    std::set<int> resultSet;

    // Find the union of all sets
    for (int i = 0; i < combinations; ++i) {
        resultSet.insert(intersections[i].begin(), intersections[i].end());
    }
    printSet("initial result set",resultSet);

    for (int i = 0; i < idx; ++i)
    {
        printSet("-- interval --", intervalSet[i]);
        std::set<int> tempSet;
        std::set_intersection(intervalSet[i].begin(), intervalSet[i].end(),
                                  resultSet.begin(), resultSet.end(),
                                  std::inserter(tempSet, tempSet.begin()));
        printSet("-- tempset --", tempSet);
        if(tempSet.empty())
        {
            auto it = intervalSet[i].begin();
            int elem1 = *it++;
            int elem2 = *it++;
            resultSet.insert(elem1);
            resultSet.insert(elem2);
        }
        else if (tempSet.size() >= 2)
        {
            int numberOfExtraElements = tempSet.size() - 2;
            auto it = tempSet.end();
            for (int j = 0; j < numberOfExtraElements; ++j)
            {
                int elem = *it--;
                resultSet.erase(elem);
            }
        }
        else
        {
            // difference
            std::set<int> differenceSet;
            std::set_difference(intervalSet[i].begin(), intervalSet[i].end(),
                                      resultSet.begin(), resultSet.end(),
                                      std::inserter(differenceSet, differenceSet.begin()));
            // printSet("-- difference set --", differenceSet);
            int elem = *(differenceSet.begin());
            resultSet.insert(elem);
        }
        printSet("interim resultSet --", resultSet);
    } 
    printSet("final resultSet", resultSet);

    delete intervalSet;

    return resultSet.size();
}

int main()
{
    std::cout << "-- [INCORRECT] Set Intersection Size At Least Two --" << std::endl;

    vector<vector<int>> intervals = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
    int result = intersectionSizeTwo(intervals);
    std::cout << "Minimum size of a containing set: " << result << std::endl;

    return 0;
}

void printSet(string str, const std::set<int> &s)
{
    cout << str << ": " << endl;
    for (int elem : s)
    {
        cout << elem << " ";
    }
    cout << endl;
}