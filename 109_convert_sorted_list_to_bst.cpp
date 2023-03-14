// ///////////////////////////////////////////////////////////////////////////
//
// 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
//
// ***************************************************************************
//
//
// Given the head of a singly linked list where elements are sorted in
// ascending order, convert it to a height-balanced binary search tree.
// 
// Example 1:
// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which
// represents the shown height balanced BST.
// 
// Example 2:
// Input: head = []
// Output: []
// 
// Constraints:
//     * The number of nodes in head is in the range [0, 2 * 10^4].
//     * -10^5 <= Node.val <= 10^5



/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head, nullptr);
    }

    TreeNode* buildBST(ListNode* head, ListNode* sentinel){
        if (head == nullptr || head == sentinel)
            return nullptr;
        // Find the mid node
        ListNode* mid = head;
        ListNode* fast = head;
        // 0-0, 1-2, 2-4, 3-6
        for (; fast != sentinel;){
            fast = fast->next;
            if (fast != sentinel)
                fast = fast->next;
            else
                break;
            mid = mid->next;
        }
        TreeNode* left = buildBST(head, mid);
        TreeNode* right = buildBST(mid->next, sentinel);
        TreeNode* root = new TreeNode(mid->val, left, right);
        return root;
    }
};
