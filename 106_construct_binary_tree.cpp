// ///////////////////////////////////////////////////////////////////////////
//
// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
//
// ***************************************************************************
//
//
// Given two integer arrays inorder and postorder where inorder is the inorder
// traversal of a binary tree and postorder is the postorder traversal of the
// same tree, construct and return the binary tree.
// 
// 
// Example 1:
// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// 
// Example 2:
// Input: inorder = [-1], postorder = [-1]
// Output: [-1]
// 
// Constraints:
//     * 1 <= inorder.length <= 3000
//     * postorder.length == inorder.length
//     * -3000 <= inorder[i], postorder[i] <= 3000
//     * inorder and postorder consist of unique values.
//     * Each value of postorder also appears in inorder.
//     * inorder is guaranteed to be the inorder traversal of the tree.
//     * postorder is guaranteed to be the postorder traversal of the tree.



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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(
            inorder.begin(), inorder.end(), postorder.begin(), postorder.end()
        );
    }

    TreeNode* build(vector<int>::iterator inorder_begin,
                    vector<int>::iterator inorder_end,
                    vector<int>::iterator postorder_begin,
                    vector<int>::iterator postorder_end) {

        if (inorder_begin == inorder_end)
            return nullptr;
        // inorder:     L root R
        // postorder:   L R root

        // Find the root in `inorder` list
        TreeNode* root = new TreeNode(*(postorder_end - 1));
        auto inorder_root = find(inorder_begin, inorder_end, root->val);
        int n_left = inorder_root - inorder_begin;
        int n_right = inorder_end - inorder_root - 1;

        root->left = build(
            inorder_begin,
            inorder_root,
            postorder_begin,
            postorder_begin + n_left
        );
        root->right = build(
            inorder_root + 1,
            inorder_end,
            postorder_begin + n_left,
            postorder_end - 1
        );
        return root;
        }
};
