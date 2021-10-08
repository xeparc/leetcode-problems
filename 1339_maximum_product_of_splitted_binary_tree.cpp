// ///////////////////////////////////////////////////////////////////////////
//
// 1339. Maximum Product of Splitted Binary Tree
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
//
// ***************************************************************************
//
//
// Given the root of a binary tree, split the binary tree into two subtrees
// by removing one edge such that the product of the sums of the subtrees is maximized.
// Return the maximum product of the sums of the two subtrees.
// Since the answer may be too large, return it modulo 10^9 + 7.
//
// Note that you need to maximize the answer before taking the mod
// and not after taking it.
//
// Example 1:
// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10.
// Their product is 110 (11*10)
//
// Example 2:
// Input: root = [1,null,2,3,4,null,null,5,6]
// Output: 90
// Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.
// Their product is 90 (15*6)
//
// Example 3:
// Input: root = [2,3,9,10,7,8,6,5,4,11,1]
// Output: 1025
//
// Example 4:
// Input: root = [1,1]
// Output: 1
//
// Constraints:
// The number of nodes in the tree is in the range [2, 5 * 10^4].
// 1 <= Node.val <= 10^4



#include <unordered_map>
#include <stack>
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
    int maxProduct(TreeNode* root) {
        std::unordered_map<TreeNode*, unsigned long> visited;
        visited[root] = root->val;
        std::stack<TreeNode*> stack({root});
        while (!stack.empty()){
            TreeNode* current = stack.top();
            if ((current->left != nullptr) & !visited.count(current->left)){
                stack.push(current->left);
                visited[current->left] = current->left->val;
            }
            else if ((current->right != nullptr) & !visited.count(current->right)){
                stack.push(current->right);
                visited[current->right] = current->right->val;
            }
            // Propagate value to parents and remove from stack
            else{
                stack.pop();
                if (!stack.empty()){
                    TreeNode* parent = stack.top();
                    visited[parent] += visited[current];
                }
            }
        }
        // for (auto it = visited.begin(); it != visited.end(); it++){
        //     std::cout << it->first->val << ": " << it->second << ";\n";
        // }

        // Do Breadth-First Search to calculate optimal split
        // (maximum product of subtrees)
        unsigned long rootsum = visited[root];
        unsigned long maxprod = 0;
        std:deque<TreeNode*> queue {root};
        while (!queue.empty()){
            TreeNode* current = queue.front();
            queue.pop_front();
            if (current->left){
                queue.push_back(current->left);
                unsigned long left_sum = visited[current->left];
                maxprod = std::max(maxprod, left_sum * (rootsum - left_sum));
            }
            if (current->right){
                queue.push_back(current->right);
                unsigned long right_sum = visited[current->right];
                maxprod = std::max(maxprod, right_sum * (rootsum - right_sum));
            }
        }
        return maxprod % 1'000'000'007;
    }
};
