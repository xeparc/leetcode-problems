// ****************************************************************************
// 905. Sort Array By Parity
// https://leetcode.com/problems/sort-array-by-parity/
// ----------------------------------------------------------------------------

// Given an array A of non-negative integers, return an array consisting
// of all the even elements of A, followed by all the odd elements of A.
// You may return any answer array that satisfies this condition.

// Example 1:
// Input: [3,1,2,4]
// Output: [2,4,3,1]
// The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 
// Note:
// 1 <= A.length <= 5000
// 0 <= A[i] <= 5000


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * ASize);
    int i = 0, j = ASize - 1;
    for (int k = 0; k < ASize; k++){
        if (A[k] % 2) res[j--] = A[k];
        else res[i++] = A[k];
    }
    *returnSize = ASize;
    return res;
}