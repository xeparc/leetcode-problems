// ///////////////////////////////////////////////////////////////////////////
//
// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
//
// ***************************************************************************
//
//
// Given an integer array nums where the elements are sorted in ascending order,
// convert it to a height-balanced binary search tree.
// 
// Example 1:
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:
// 
// Example 2:
// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
// 
// Constraints:
//     * 1 <= nums.length <= 10^4
//     * -10^4 <= nums[i] <= 10^4
//     * nums is sorted in a strictly increasing order.


#include <vector>

using namespace std;


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums.begin(), nums.end());
    }

    TreeNode* buildBST(const vector<int>::iterator begin, const vector<int>::iterator end) {
        if (begin == end)
            return nullptr;
        int i = (end - begin) / 2;
        TreeNode* left = buildBST(begin, begin + i);
        TreeNode* right = buildBST(begin + i + 1, end);
        TreeNode* root = new TreeNode(*(begin + i), left, right);
        return root;
    }
};
