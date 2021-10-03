// ****************************************************************************
// 
// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/
//
// ----------------------------------------------------------------------------

// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15
// respectively. Return 24.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int is_leaf(struct TreeNode* root){
    return !root->left && !root->right;
}

int sumOfLeftLeaves(struct TreeNode* root){
    if (!root)
        return 0;
    int sum = 0;
    if (root->left && is_leaf(root->left))
        sum += root->left->val;
    else
        sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    return sum;
}
