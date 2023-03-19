// ///////////////////////////////////////////////////////////////////////////
//
// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
// 
// ***************************************************************************
//
//
// Given two sorted arrays nums1 and nums2 of size m and n respectively,
// return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).
// 
// 
// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// 
// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
// 
// 
// Constraints:
//     * nums1.length == m
//     * nums2.length == n
//     * 0 <= m <= 1000
//     * 0 <= n <= 1000
//     * 1 <= m + n <= 2000
//     * -10^6 <= nums1[i], nums2[i] <= 10^6



#include <vector>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int merged_size = nums1.size() + nums2.size();
        int m1 = merged_size / 2;
        int mval1 = lookupMerged(m1, nums1.begin(), nums1.end(), nums2.begin(), nums2.end());
        if (merged_size % 2 == 0){
            int mval2 = lookupMerged(m1 - 1, nums1.begin(), nums1.end(), nums2.begin(), nums2.end());
            return static_cast<double>(mval1 + mval2) / 2.0;
        }
        return static_cast<double>(mval1);
    }

    int lookupMerged(
        int index,
        const vector<int>::iterator A_begin,
        const vector<int>::iterator A_end,
        const vector<int>::iterator B_begin,
        const vector<int>::iterator B_end
    ) {
        int M = A_end - A_begin;
        int N = B_end - B_begin;
        if (M == 0)
            return *(B_begin + index);
        if (N == 0)
            return *(A_begin + index);
        int i = M / 2;
        int a = *(A_begin + i);
        int j = std::lower_bound(B_begin, B_end, a) - B_begin;
        if (index < i + j)
            return lookupMerged(index, A_begin, A_begin + i, B_begin, B_begin + j);
        else if (index == i + j)
            return a;
        else
            return lookupMerged(index - i - j - 1, A_begin + i + 1, A_end, B_begin + j, B_end);
    }
};
