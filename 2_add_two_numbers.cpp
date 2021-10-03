// ****************************************************************************
// 
// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/
//
// ----------------------------------------------------------------------------


// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order and each of their
// nodes contain a single digit. Add the two numbers and return
// it as a linked list.

// You may assume the two numbers do not contain any leading zero,
// except the number 0 itself.

// Example:
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.



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

int getValue(ListNode*);

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode result;
        ListNode* curr = &result;
        while (l1 or l2){
            ListNode* node = new ListNode;
            int i = getValue(l1) + getValue(l2) + carry;
            carry = i / 10;
            node->val += i % 10;
            curr->next = node;
            curr = node;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry)
            curr->next = new ListNode(carry);
        return result.next;
    }
};

inline int getValue(ListNode* node){
    return node == nullptr ? 0 : node->val;
}
