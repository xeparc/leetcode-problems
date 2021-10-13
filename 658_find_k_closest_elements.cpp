// ///////////////////////////////////////////////////////////////////////////
//
// 658. Find K Closest Elements
// https://leetcode.com/problems/find-k-closest-elements/
//
// ***************************************************************************
//
//
// Given a sorted integer array arr, two integers k and x, return the k
// closest integers to x in the array. The result should also be sorted
// in ascending order.
// An integer a is closer to x than an integer b if:
//     |a - x| < |b - x|, or
//     |a - x| == |b - x| and a < b
//
//
// Example 1:
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]
//
// Example 2:
// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]
//
// Constraints:
// 1 <= k <= arr.length
// 1 <= arr.length <= 10^4
// arr is sorted in ascending order.
// -10^4 <= arr[i], x <= 10^4



#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Do binary search for the insert position of `x`
        int lo = 0, hi = arr.size();
        int mid = 0;
        while (lo < hi){
            mid = lo + (hi - lo) / 2;
            if (arr[mid] == x)
                break;
            else if (arr[mid] < x)
                lo = mid + 1;
            else
                hi = mid;
        }
        // The element arr[mid] must be <= x.
        // Enforce this constraint.
        if (mid < arr.size() - 1 && arr[mid] < x)
            mid++;
        // The range of k-closest elements is [i, j)
        int i = mid, j = mid;
        while (i > 0 && j < arr.size() && j - i < k){
            if (abs(arr[i - 1] - x) <= abs(arr[j] - x))
                i--;
            else
                j++;
        }
        for (; i > 0 && j - i < k; i--);
        for (; j < arr.size() && j - i < k; j++);
        return std::vector<int>(arr.begin() + i, arr.begin() + j);
    }
};
