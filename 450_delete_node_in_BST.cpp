// ****************************************************************************
// 
// 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/
//
// ----------------------------------------------------------------------------

// Given a root node reference of a BST and a key, delete the node with the
// given key in the BST. Return the root node reference
// (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:
// Search for a node to remove.
// If the node is found, delete the node.

// Note: Time complexity should be O(height of tree).


// Example:
// root = [5,3,6,2,4,null,7]
// key = 3

//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

//     5
//    / \
//   4   6
//  /     \
// 2       7

// Another valid answer is [5,2,6,null,4,null,7].

//     5
//    / \
//   2   6
//    \   \
//     4   7



void updateParent(TreeNode*, TreeNode*, TreeNode*);

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        TreeNode r {root->val, root, root};
        TreeNode* p = &r;
        TreeNode* x = p->left;
        while (x && (x->val != key)){
            p = x;
            if (key < x->val)
                x = x->left;
            else
                x = x->right;
        }
        // Case 1: Not found
        if (!x)
            return r.left;
        // Case 2: `x` has single left child
        else if (!x->right)
            updateParent(p, x, x->left);
        // Case 3: `x` has right child
        else {
            // Find successor
            TreeNode* psuc = x;
            TreeNode* succ = x->right;
            while (succ && succ->left){
                psuc = succ;
                succ = succ->left;
            }
            // Case 3.1: successor(x) == x->right
            succ->left = x->left;
            // Case 3.2: successor(x) != x->right
            if (psuc != x){
                psuc->left = succ->right;
                succ->right = x->right;
            }
            updateParent(p, x, succ);
        }
        delete x;
        return r.left;
    }
};


void updateParent(TreeNode* p, TreeNode* x, TreeNode* y){
    if (!p) return;
    if (p->left == x)
        p->left = y;
    else if (p->right == x)
        p->right = y;
}
