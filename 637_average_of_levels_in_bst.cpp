// ///////////////////////////////////////////////////////////////////////////
//
// 637. Average of Levels in Binary Tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
//
// ***************************************************************************
//
//
// Given the root of a binary tree, return the average value of the nodes
// on each level in the form of an array. Answers within 10-5 of the
// actual answer will be accepted.
// 
// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [3.00000,14.50000,11.00000]
// Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
// Hence return [3, 14.5, 11].
// 
// Example 2:
// Input: root = [3,9,20,15,7]
// Output: [3.00000,14.50000,11.00000]
// 
// Constraints:
//     * The number of nodes in the tree is in the range [1, 10^4].
//     * -2^31 <= Node.val <= 2^31 - 1



#include <deque>
#include <vector>
#include <numeric>

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<double> level;
        if (root == nullptr)
            return result;
        deque<TreeNode*> Q {root};
        while (!Q.empty()){
            int n = Q.size();
            level.clear();
            for (int i = 0; i < n; i++){
                TreeNode* x = Q.front();
                level.push_back(static_cast<double>(x->val));
                if (x->left) Q.push_back(x->left);
                if (x->right) Q.push_back(x->right);
                Q.pop_front();
            }
            double mean = accumulate(level.begin(), level.end(), 0.0) / static_cast<double>(n);
            result.push_back(mean);
        }
        return result;
    }
};
