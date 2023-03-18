// ///////////////////////////////////////////////////////////////////////////
//
// 958. Check Completeness of a Binary Tree
// https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
// 
// ***************************************************************************
//
//
// Given the root of a binary tree, determine if it is a complete binary tree.
// In a complete binary tree, every level, except possibly the last, is
// completely filled, and all nodes in the last level are as far left as
// possible. It can have between 1 and 2h nodes inclusive at the last level h.
// 
// 
// Example 1:
// Input: root = [1,2,3,4,5,6]
// Output: true
// Explanation: Every level before the last is full (ie. levels with
// node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6})
// are as far left as possible.
// 
// Example 2:
// Input: root = [1,2,3,4,5,null,7]
// Output: false
// Explanation: The node with value 7 isn't as far left as possible.
// 
// Constraints:
//     * The number of nodes in the tree is in the range [1, 100].
//     * 1 <= Node.val <= 1000



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
    bool isCompleteTree(TreeNode* root) {
        deque<TreeNode*> Q{root};
        bool lastlevel = false;
        while (!Q.empty() && !lastlevel){
            int size = Q.size();
            for (int i = 0; i < size; i++){
                TreeNode* x = Q.front();
                Q.push_back(x->left);
                Q.push_back(x->right);
                if (x->left == nullptr || x->right == nullptr)
                    lastlevel = true;
                Q.pop_front();
            }
        }
        // Pop rightmost null nodes
        while (!Q.empty() && Q.back() == nullptr)
            Q.pop_back();
        // Assert that last level has no children & all nodes are != NULL
        for (auto it : Q){
            if (it && (it->left || it->right))
                return false;
            if (it == nullptr)
                return false;
        }
        return true;
    }
};
