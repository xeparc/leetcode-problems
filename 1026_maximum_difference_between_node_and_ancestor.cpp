// ****************************************************************************
// 
// 1026. Maximum Difference Between Node and Ancestor
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// 
// ----------------------------------------------------------------------------


// Given the root of a binary tree, find the maximum value V for which there
// exist different nodes A and B where V = |A.val - B.val| and
// A is an ancestor of B.
// A node A is an ancestor of B if either: any child of A is equal to B,
// or any child of A is an ancestor of B.


// Example 1:

// Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
// Output: 7
// Explanation: We have various ancestor-node differences, some of which are given below :
// |8 - 3| = 5
// |3 - 7| = 4
// |8 - 1| = 7
// |10 - 13| = 3
// Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.


// Example 2:

// Input: root = [1,null,2,null,0,3]
// Output: 3


// Constraints:

// The number of nodes in the tree is in the range [2, 5000].
// 0 <= Node.val <= 10^5



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

int findMax(TreeNode* root){
    int m = root->val;
    int mleft = m, mright = m;
    if (root->left)
        mleft = findMax(root->left);
    if (root->right)
        mright = findMax(root->right);
    return std::max(m, std::max(mleft, mright));
}

int findMin(TreeNode* root){
    int m = root->val;
    int mleft = m, mright = m;
    if (root->left)
        mleft = findMin(root->left);
    if (root->right)
        mright = findMin(root->right);
    return std::min(m, std::min(mleft, mright));
}

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return 0;
        int x = root->val;
        int tmax = x, tmin = x;
        if (root->left){
            tmax = findMax(root->left);
            tmin = findMin(root->left);
        }
        if (root->right){
            tmax = std::max(tmax, findMax(root->right));
            tmin = std::min(tmin, findMin(root->right));
        }
        int thismax = std::max(std::abs(tmax - x), std::abs(x - tmin));
        int leftmax = thismax, rightmax = thismax;
        if (root->left)
            leftmax = maxAncestorDiff(root->left);
        if (root->right)
            rightmax = maxAncestorDiff(root->right);
        return std::max(thismax, std::max(leftmax, rightmax));
           
    }
};
