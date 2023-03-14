// ///////////////////////////////////////////////////////////////////////////
//
// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/description/
//
// ***************************************************************************
//
//
// Given a binary tree, determine if it is height-balanced.
// 
// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true
// 
// Example 2:
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// 
// Example 3:
// Input: root = []
// Output: true
// 
// Constraints:
//     * The number of nodes in the tree is in the range [0, 5000].
//     * -10^4 <= Node.val <= 10^4



#include <cmath>
#include <algorithm>

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
        bool isBalanced(TreeNode* root) {
            return balance(root) >= 0;
        }

        int balance(TreeNode* root){
            if (root == nullptr)
                return 0;
            int L = balance(root->left);
            int R = balance(root->right);
            if (L >= 0 && R >= 0 && abs(L - R) < 2)
                return std::max(L, R) + 1;
            return -1;
        }
    };
