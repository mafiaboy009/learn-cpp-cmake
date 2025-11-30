
#include <vector>
#include <algorithm>

double findMedianSortedArraysV1(const std::vector<int> &nums1, const std::vector<int> &nums2)
{
    int len = nums1.size() + nums2.size();
    std::vector<int> result(len);
    std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), result.begin());
    int lenBy2 = len / 2;
    if ((result.size() % 2) == 0)
    {
        return (double(result[lenBy2]) + double(result[lenBy2 - 1])) / 2;
    }
    else
    {
        return result[lenBy2];
    }
}

double findMedianSortedArraysV2(const std::vector<int> &nums1, const std::vector<int> &nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    int len = len1 + len2;
    double elem1 = 0.0, elem2 = 0.0;
    if (len % 2 == 0)
    {
        int loc2 = len / 2;
        int loc1 = loc2 - 1;
        int i = 0, j = 0, loc = 0;
        do
        {
            if (nums1[i] < nums2[j])
            {
                if (loc == loc1)
                {
                    elem1 = double(nums1[i]);
                }
                if (loc == loc2)
                {
                    elem2 = double(nums1[i]);
                }
                ++i;
            }
            else
            {
                if (loc == loc1)
                {
                    elem1 = double(nums2[j]);
                }
                if (loc == loc2)
                {
                    elem2 = double(nums2[j]);
                }
                ++j;
            }
            ++loc;
        } while (loc <= loc2);
        return (elem1 + elem2) / 2;
    }
    else
    {
        int loc1 = len / 2;
        int i = 0, j = 0, loc = 0;
        do
        {
            if (i < len1 && j < len2 && nums1[i] < nums2[j])
            {
                if (loc == loc1)
                {
                    elem1 = double(nums1[i]);
                }
                ++i;
            }
            else if (i < len1 && j < len2)
            {
                if (loc == loc1)
                {
                    elem1 = double(nums2[j]);
                }
                ++j;
            }
            ++loc;
        } while (loc <= loc1);
        return elem1;
    }
}

double findMedianSortedArraysV3(const std::vector<int> &nums1, const std::vector<int> &nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    int len = len1 + len2;
    int loc1 = (len - 1) / 2;
    int loc2 = len / 2;
    int i = 0, j = 0, loc = 0;
    double elem1 = 0.0, elem2 = 0.0;

    while (loc <= loc2)
    {
        if (i < len1 && (j >= len2 || nums1[i] < nums2[j]))
        {
            if (loc == loc1)
                elem1 = nums1[i];
            if (loc == loc2)
                elem2 = nums1[i];
            i++;
        }
        else
        {
            if (loc == loc1)
                elem1 = nums2[j];
            if (loc == loc2)
                elem2 = nums2[j];
            j++;
        }
        loc++;
    }

    return (len % 2 == 0) ? (elem1 + elem2) / 2 : elem2;
}

double findMedianSortedArraysOptimized(const std::vector<int> &nums1, const std::vector<int> &nums2)
{
    const std::vector<int> &A = (nums1.size() < nums2.size()) ? nums1 : nums2;
    const std::vector<int> &B = (nums1.size() < nums2.size()) ? nums2 : nums1;
    int m = A.size();
    int n = B.size();
    int totalLeft = (m + n + 1) / 2;

    int left = 0, right = m;
    while (left <= right)
    {
        int i = left + (right - left) / 2;
        int j = totalLeft - i;

        if (i < m && B[j - 1] > A[i])
        {
            left = i + 1; // i is too small
        }
        else if (i > 0 && A[i - 1] > B[j])
        {
            right = i - 1; // i is too big
        }
        else
        {
            int maxLeft = 0;
            if (i == 0)
            {
                maxLeft = B[j - 1];
            }
            else if (j == 0)
            {
                maxLeft = A[i - 1];
            }
            else
            {
                maxLeft = std::max(A[i - 1], B[j - 1]);
            }

            if ((m + n) % 2 == 1)
            {
                return maxLeft; // Odd case
            }

            int minRight = 0;
            if (i == m)
            {
                minRight = B[j];
            }
            else if (j == n)
            {
                minRight = A[i];
            }
            else
            {
                minRight = std::min(A[i], B[j]);
            }

            return (maxLeft + minRight) / 2.0; // Even case
        }
    }
    return 0.0; // Should never reach here
}

int main()
{
    // Example usage:
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3};
    double medianV1 = findMedianSortedArraysV1(nums1, nums2);
    double medianV2 = findMedianSortedArraysV2(nums1, nums2);
    double medianV3 = findMedianSortedArraysV3(nums1, nums2);
    double medianOptimized = findMedianSortedArraysOptimized(nums1, nums2);

    nums2.push_back(4);
    double medianV1_even = findMedianSortedArraysV1(nums1, nums2);
    double medianV2_even = findMedianSortedArraysV2(nums1, nums2);
    double medianV3_even = findMedianSortedArraysV3(nums1, nums2);
    double medianOptimized_even = findMedianSortedArraysOptimized(nums1, nums2);
    return 0;
}