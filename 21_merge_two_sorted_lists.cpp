// ****************************************************************************
// 
// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
//
// ----------------------------------------------------------------------------


// Merge two sorted linked lists and return it as a new sorted list.
// The new list should be made by splicing together the nodes
// of the first two lists.

// Example:
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head;
        ListNode* curr = &head;
        while (l1 && l2){
            if (l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            } else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        while (l1){
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }
        while (l2){
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        return head.next;
    }
};
