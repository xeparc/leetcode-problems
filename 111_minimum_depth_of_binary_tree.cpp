//////////////////////////////////////////////////////////////////////////////
//
// 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/
//
// ***************************************************************************


// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path
// from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 2

// Example 2:

// Input: root = [2,null,3,null,4,null,5,null,6]
// Output: 5
 

// Constraints:

// The number of nodes in the tree is in the range [0, 10^5].
// -1000 <= Node.val <= 1000



#include <deque>

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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left)
            return 1 + minDepth(root->right);
        else if (!root->right)
            return 1 + minDepth(root->left);
        else
            return min(1 + minDepth(root->left), 1 + minDepth(root->right));
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        std::deque<int> levels {1};
        std::deque<TreeNode*> nodes {root};
        while (!nodes.empty()){
            TreeNode* x = nodes.front();
            int l = levels.front();
            levels.pop_front();
            nodes.pop_front();
            if (!x->left and !x->right)
                return l;
            if (x->left){
                nodes.push_back(x->left);
                levels.push_back(l + 1);
            }
            if (x->right){
                nodes.push_back(x->right);
                levels.push_back(l + 1);
            }
        }
        return 0;
    }
};
