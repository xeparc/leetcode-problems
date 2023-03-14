// ///////////////////////////////////////////////////////////////////////////
//
// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
//
// ***************************************************************************
//
//
// Given the root of a binary tree, return the level order traversal of its
// nodes' values. (i.e., from left to right, level by level).
// 
// 
// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
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



#include <deque>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        deque<TreeNode*> Q {root};
        while (!Q.empty()){
            vector<int> level;
            int n = Q.size();
            for (int i = 0; i < n; i++){
                TreeNode* x = Q.front();
                if (x->left)
                    Q.push_back(x->left);
                if (x->right)
                    Q.push_back(x->right);
                level.push_back(Q.front()->val);
                Q.pop_front();
            }
            result.push_back(level);
        }
        return result;
    }
};
