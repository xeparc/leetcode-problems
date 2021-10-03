// ****************************************************************************
// 
// 845. Longest Mountain in Array
// https://leetcode.com/problems/longest-mountain-in-array/
//
// ----------------------------------------------------------------------------


// Let's call any (contiguous) subarray B (of A) a mountain
// if the following properties hold:
//  * B.length >= 3
//  * There exists some 0 < i < B.length - 1 such that
//    B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
// 
// (Note that B could be any subarray of A, including the entire array A.)

// Given an array A of integers, return the length of the longest mountain. 
// Return 0 if there is no mountain.

// Example 1:
// Input: [2,1,4,7,3,2,5]
// Output: 5
// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

// Example 2:
// Input: [2,2,2]
// Output: 0
// Explanation: There is no mountain.

// Note:
// 0 <= A.length <= 10000
// 0 <= A[i] <= 10000

// Follow up:
// Can you solve it using only one pass?
// Can you solve it in O(1) space?


class Solution {
public:
    int longestMountain(vector<int>& A) {
        int longest = 0;
        size_t i = 0;
        while (i + 1 < A.size()){
            size_t j = i + 1;
            for(; j < A.size() && A[j - 1] < A[j]; j++);
            if (j == i + 1){
                i = j;
                continue;
            }
            size_t k = j;
            for(; k < A.size() && A[k - 1] > A[k]; k++);
            if (k == j){
                i = j;
                continue;
            }
            if (k - i >= 3 and k - i > longest){
                longest = k - i;
            }
            i = k - 1;
        }
        return longest;
    }
};