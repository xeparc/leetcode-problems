// ****************************************************************************
// 
// 718. Maximum Length of Repeated Subarray
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
//
// ----------------------------------------------------------------------------


// Given two integer arrays A and B, return the maximum length of an
// subarray that appears in both arrays.

// Example 1:

// Input:
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// Output: 3
// Explanation: 
// The repeated subarray with maximum length is [3, 2, 1].
 

// Note:

// 1 <= len(A), len(B) <= 1000
// 0 <= A[i], B[i] < 100



#include <algorithm>

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        size_t N = A.size(), M = B.size();
        vector<int> table(N * M, 0);
        // N rows, M cols
        for (size_t i = 0; i < M; i++)
            if (A[0] == B[i]) table[i] = 1;
        for (size_t j = 0; j < N; j++)
            if (A[j] == B[0]) table[M * j] = 1;
        int max_length = 0;
        for (size_t i = 1; i < N; i++)
            for (size_t j = 1; j < M; j++)
                if (A[i] == B[j]){
                    table[i * M + j] = 1 + table[(i - 1) * M + (j - 1)];
                    max_length = std::max(max_length, table[i * M + j]);
                }
        return max_length;
    }
};
