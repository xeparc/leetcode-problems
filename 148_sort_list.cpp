// ****************************************************************************
// 
// 148. Sort List
// https://leetcode.com/problems/sort-list/
//
// ----------------------------------------------------------------------------

// Sort a linked list in O(n log n) time using constant space complexity.

// Example 1:
// Input: 4->2->1->3
// Output: 1->2->3->4

// Example 2:
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5



#include <utility>
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
ListNode* mergeLists(ListNode*, ListNode*);
std::pair<ListNode*, ListNode*> splitList(ListNode*);

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: 0 or 1 elements
        if (head == nullptr or head->next == nullptr)
            return head;
        auto [A, B] = splitList(head);
        A = sortList(A);
        B = sortList(B);
        return mergeLists(A, B);
    }
};


ListNode* mergeLists(ListNode* A, ListNode* B){
    ListNode head;
    ListNode* curr = &head;
    while (A && B){
        if (A->val < B->val){
            curr->next = A;
            A = A->next;
        } else{
            curr->next = B;
            B = B->next;
        }
        curr = curr->next;
    }
    while (A){
        curr->next = A;
        A = A->next;
        curr = curr->next;
    }
    while (B){
        curr->next = B;
        B = B->next;
        curr = curr->next;
    }
    return head.next;
}


std::pair<ListNode*, ListNode*> splitList(ListNode* head){
    if (head == nullptr or head->next == nullptr)
        return std::pair{head, nullptr};
    ListNode* slow = head;
    ListNode* fast = head->next;
    ListNode* prev = nullptr;
    while (fast){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast != nullptr)
            fast = fast->next;
    }
    prev->next = nullptr;
    return std::pair<ListNode*, ListNode*>{head, slow};
}

