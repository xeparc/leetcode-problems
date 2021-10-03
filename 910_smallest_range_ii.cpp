//////////////////////////////////////////////////////////////////////////////
//
// 910. Smallest Range II
// https://leetcode.com/problems/smallest-range-ii/
//
// ***************************************************************************

// Given an array A of integers, for each integer A[i] we need to choose
// either x = -K or x = K, and add x to A[i] (only once).
// After this process, we have some array B.
// Return the smallest possible difference between the maximum value
// of B and the minimum value of B.


// Example 1:

// Input: A = [1], K = 0
// Output: 0
// Explanation: B = [1]


// Example 2:

// Input: A = [0,10], K = 2
// Output: 6
// Explanation: B = [2,8]


// Example 3:

// Input: A = [1,3,6], K = 3
// Output: 3
// Explanation: B = [4,6,3]


// Note:

// 1 <= A.length <= 10000
// 0 <= A[i] <= 10000
// 0 <= K <= 10000




#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        if (A.empty())
            return 0;
        std::sort(A.begin(), A.end());
        // The difference if we were to add (or subtract) K
        // to all elements in A
        int diff = A.back() - A.front();
        // The difference if we were to add K to some elements
        // and subtrack it from the rest
        int left = A.front(), right = A.back();
        // pivots[0] : the smallest element to which we +K
        // pivots[1] : the largest element to which we +K
        // pivots[2] : the smallest element to which we -K
        // pivots[3] : the largest element to which we -K
        int pivots[4] = {left + K, 0, 0, right - K};
        for (size_t i = 0; i < A.size() - 1; i++){
            pivots[1] = A[i] + K;
            pivots[2] = A[i + 1] - K;
            const auto [min, max] = std::minmax_element(pivots, pivots + 4);
            diff = std::min(diff, *max - *min);
        }
        return diff;
    }
};
