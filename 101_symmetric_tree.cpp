// ///////////////////////////////////////////////////////////////////////////
//
// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/description/
//
// ***************************************************************************
//
//
// Given the root of a binary tree, check whether it is a mirror of itself
// (i.e., symmetric around its center).
// 
// Example 1:
// Input: root = [1,2,2,3,4,4,3]
// Output: true
// 
// Example 2:
// Input: root = [1,2,2,null,3,null,3]
// Output: false
// 
// Constraints:
//     * The number of nodes in the tree is in the range [1, 1000].
//     * -100 <= Node.val <= 100
// 
// Follow up: Could you solve it both recursively and iteratively?



#include <stack>

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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> L;
        stack<TreeNode*> R;
        L.push(root->left);
        R.push(root->right);
        while (!L.empty() && !R.empty()){
            TreeNode* x = L.top();
            TreeNode* y = R.top();
            L.pop(), R.pop();
            if ((x && y && x->val != y->val) || (bool(x) ^ bool(y)))
                return false;
            if ((x && x->right) || (y && y->left)){
                L.push(x->right);
                R.push(y->left);
            }
            if ((x && x->left) || (y && y->right)){
                L.push(x->left);
                R.push(y->right);
            }
        }
        return true;
    }

    bool isSymmetricRecursive(TreeNode* root) {
        if (root == nullptr)
            return true;
        return compareTrees(root->left, root->right);
    }

    bool compareTrees(TreeNode* A, TreeNode* B) {
        if (A == nullptr && B == nullptr)
            return true;
        else if (A && B && A->val == B->val)
            return compareTrees(A->left, B->right) && compareTrees(A->right, B->left);
        return false;
    }
};
