
// ///////////////////////////////////////////////////////////////////////////
//
// 653. Two Sum IV - Input is a BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
//
// ***************************************************************************
//
//
// Given the root of a Binary Search Tree and a target number k,
// return true if there exist two elements in the BST such that their
// sum is equal to the given target.
//
// Example 1:
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
// 
// Example 2:
// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
// 
// Constraints:
//     * The number of nodes in the tree is in the range [1, 10^4].
//     * -10^4 <= Node.val <= 10^4
//     * root is guaranteed to be a valid binary search tree.
//     * -10^5 <= k <= 10^5



#include <stack>

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


TreeNode* successor(std::stack<TreeNode*>& ancestors)
{
    if (ancestors.empty())
        return nullptr;
    TreeNode* x = ancestors.top();
    // Case 1: x has right child.
    // Return the leftmost child in the right subtree of x
    if (x->right){
        ancestors.push(x = x->right);
        while (x->left)
            ancestors.push(x = x->left);
        return x;
    }
    // Case 2: x has no right child and x is a left child
    // of it's parent. Return parent
    ancestors.pop();
    if (!ancestors.empty()){
        TreeNode* p = ancestors.top();
        if (p->left == x)
            return p;
        // Case 3: x has no right child and x is right child
        // of it's parent. Return the first node in ancestor
        // chain which has a left child in ancestors.
        while (!ancestors.empty() && ancestors.top()->right == x){
            x = ancestors.top();
            ancestors.pop();
        }
        if (ancestors.empty())
            return nullptr;
        return ancestors.top();
    }
    // Case 4: x is root with no right child
    return nullptr;
}

TreeNode* predecessor(std::stack<TreeNode*>& ancestors)
{
    if (ancestors.empty())
        return nullptr;
    TreeNode* x = ancestors.top();
    // Case 1: x has left child. Return the rightmost
    // child in the left subtree of x
    if (x->left){
        ancestors.push(x = x->left);
        while (x->right)
            ancestors.push(x = x->right);
        return x;
    }
    ancestors.pop();
    // Case 2: x has no left child and x is a right child
    // of it's parent. Return parent
    if (!ancestors.empty()){
        TreeNode* p = ancestors.top();
        if (p->right == x)
            return p;
        // Case 3: x has not left child and x is a left
        // child of it's parent. Return the first node
        // in ancestors chain with a right child in ancestors.
        while (!ancestors.empty() && ancestors.top()->left == x){
            x = ancestors.top();
            ancestors.pop();
        }
        if (ancestors.empty())
            return nullptr;
        return ancestors.top();
    }        
    // Case 4: x is root node with no left child
    return nullptr;
}

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        std::stack<TreeNode*> left_ancestors;
        std::stack<TreeNode*> right_ancestors;
        TreeNode* x = root;
        while (x){
            left_ancestors.push(x);
            x = x->left;
        }
        x = root;
        while (x){
            right_ancestors.push(x);
            x = x->right;
        }
        while (true){
            TreeNode* left = left_ancestors.top();
            TreeNode* right = right_ancestors.top();
            if (left->val > right->val || left == right)
                break;
            int sum = left->val + right->val;
            if (sum == k)
                return true;
            if (sum < k)
                successor(left_ancestors);
            else
                predecessor(right_ancestors);
        }
        return false;
    }
};
