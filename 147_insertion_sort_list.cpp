// ****************************************************************************
// 
// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/
//
// ----------------------------------------------------------------------------

// Sort a linked list using insertion sort.

// Example 1:
// Input: 4->2->1->3
// Output: 1->2->3->4

// Example 2:
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5



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

#define CLEVER

ListNode* insertSortedList(ListNode* head, ListNode* elem);


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* res = head;
        ListNode* iter = head->next;
        res->next = nullptr;
        while (iter){
            #ifdef CLEVER
            ListNode* _next = iter->next;
            res = insertSortedList(res, iter);
            iter = _next;
            #else
            ListNode* next_iter = iter->next;
            ListNode* curr_iter = res;
            ListNode* prev_iter = nullptr;
            while (curr_iter && curr_iter->val < iter->val){
                prev_iter = curr_iter;
                curr_iter = curr_iter->next;
            }
            iter->next = curr_iter;
            if (prev_iter){
                prev_iter->next = iter;
            } else {
                res = iter;
            }
            iter = next_iter;
            #endif
        }
        return res;
    }
};


ListNode* insertSortedList(ListNode* head, ListNode* elem){
    ListNode** iter = &head;
    while ((*iter) and elem->val > (*iter)->val){
        iter = &((*iter)->next);
    }
    elem->next = (*iter);
    *iter = elem;
    return head;
}
