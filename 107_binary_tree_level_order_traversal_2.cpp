// ///////////////////////////////////////////////////////////////////////////
//
// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
//
// ***************************************************************************
//
//
// Given the root of a binary tree, return the bottom-up level order traversal
// of its nodes' values. (i.e., from left to right, level by level from
// leaf to root).
// 
// 
// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]
// 
// Example 2:
// Input: root = [1]
// Output: [[1]]
// 
// Example 3:
// Input: root = []
// Output: []
// 
// Constraints:
//     * The number of nodes in the tree is in the range [0, 2000].
//     * -1000 <= Node.val <= 1000



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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        deque<TreeNode*> Q {root};
        while (!Q.empty()){
            vector<int> level;
            int n = Q.size();
            for (int i = 0; i < n; i++){
                TreeNode* x = Q.front();
                level.push_back(x->val);
                if (x->left) Q.push_back(x->left);
                if (x->right) Q.push_back(x->right);
                Q.pop_front();
            }
            result.push_back(level);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
