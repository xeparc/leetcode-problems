// ///////////////////////////////////////////////////////////////////////////
//
// 2096. Step-By-Step Directions From a Binary Tree Node to Another
// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
//
// ***************************************************************************
//
//
// You are given the root of a binary tree with n nodes.
// Each node is uniquely assigned a value from 1 to n. You are also given an
// integer startValue representing the value of the start node s, and a
// different integer destValue representing the value of the destination node t.
// 
// Find the shortest path starting from node s and ending at node t.
// Generate step-by-step directions of such path as a string consisting of
// only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a
// specific direction:
// 
//     'L' means to go from a node to its left child node.
//     'R' means to go from a node to its right child node.
//     'U' means to go from a node to its parent node.
// 
// Return the step-by-step directions of the shortest path from node s to node t.
// 
// 
// Example 1:
// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
// 
// Example 2:
// Input: root = [2,1], startValue = 2, destValue = 1
// Output: "L"
// Explanation: The shortest path is: 2 → 1.
// 
// Constraints:
//     * The number of nodes in the tree is n.
//     * 2 <= n <= 10^5
//     * 1 <= Node.val <= n
//     * All the values in the tree are unique.
//     * 1 <= startValue, destValue <= n
//     * startValue != destValue



#include <deque>
#include <string>

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Find the lowest common ancestor
        deque<TreeNode*> startPath {root};
        deque<TreeNode*> destPath {root};
        if (search(startValue, startPath) && search(destValue, destPath)){
            TreeNode* ancestor = root;
            while ( !startPath.empty() &&
                    !destPath.empty() && 
                    startPath.front() == destPath.front()){
                ancestor = startPath.front();
                startPath.pop_front();
                destPath.pop_front();
            }
            string directions(startPath.size(), 'U');
            TreeNode* y = ancestor;
            while (!destPath.empty()){
                TreeNode* x = destPath.front();
                if (y->left == x)
                    directions += 'L';
                else if (y->right == x)
                    directions += 'R';
                destPath.pop_front();
                y = x;
            }
            return directions; 
        }
        return "";
    }

    TreeNode* search(int value, deque<TreeNode*>& path) {
        TreeNode* root = path.back();
        if (root == nullptr || root->val == value)
            return root;
        if (root->left){
            path.push_back(root->left);
            if (search(value, path))
                return path.front();
            path.pop_back();
        }
        if (root->right){
            path.push_back(root->right);
            if (search(value, path))
                return path.front();
            path.pop_back();
        }
        path.pop_back();
        return nullptr;
    }
};
