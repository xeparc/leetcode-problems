// ///////////////////////////////////////////////////////////////////////////
//
// 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/
//
// ***************************************************************************
//
//
// Given the root of a complete binary tree, return the number of
// the nodes in the tree. According to Wikipedia, every level, except
// possibly the last, is completely filled in a complete binary tree,
// and all nodes in the last level are as far left as possible.
// It can have between 1 and 2h nodes inclusive at the last level h.
//
// Design an algorithm that runs in less than O(n) time complexity.
//
//
// Example 1:
// Input: root = [1,2,3,4,5,6]
// Output: 6
//
// Example 2:
// Input: root = []
// Output: 0
//
// Example 3:
// Input: root = [1]
// Output: 1
//
//
// Constraints:
// * The number of nodes in the tree is in the range [0, 5 * 10^4].
// * 0 <= Node.val <= 5 * 10^4
// * The tree is guaranteed to be complete.



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
    int countNodes(TreeNode* root) {
        int leftmost = 0;
        for (TreeNode* x = root; x != nullptr; x = x->left, leftmost++);
        int rightmost = 0;
        for (TreeNode* x = root; x != nullptr; x = x->right, rightmost++);
        if (leftmost == rightmost)
            return (1 << leftmost) - 1;
        int leftmiddle = 1;
        TreeNode* x = root->left;
        for (; x != nullptr; x = x->right, leftmiddle++);
        if (leftmiddle == leftmost)
            return (1 << (leftmost - 1)) + countNodes(root->right);
        else
            return (1 << (rightmost - 1)) + countNodes(root->left);
    }
};
