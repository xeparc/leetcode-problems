// ///////////////////////////////////////////////////////////////////////////
//
// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/description/
//
// ***************************************************************************
//
//
// Given the head of a linked list, return the node where the cycle begins.
// If there is no cycle, return null. There is a cycle in a linked list if there
// is some node in the list that can be reached again by continuously following
// the next pointer. Internally, pos is used to denote the index of the node
// that tail's next pointer is connected to (0-indexed). It is -1 if there is
// no cycle. Note that pos is not passed as a parameter.
// 
// Do not modify the linked list.
// 
// 
// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.
// 
// Example 2:
// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.
// 
// Example 3:
// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.
// 
// Constraints:
// 
//     * The number of the nodes in the list is in the range [0, 10^4].
//     * -10^5 <= Node.val <= 10^5
//     * pos is -1 or a valid index in the linked-list.



/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next;
        if (fast == nullptr)
            return nullptr;
        // Is there a cycle?
        while((fast != nullptr) && (fast != slow)){
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr) break;
            fast = fast->next;
        }
        if (fast == nullptr)
            return nullptr;
        // Measure the length of the cycle
        fast = fast->next;
        int n = 1;
        for(; fast != slow; fast = fast->next, n++);
        // Start iterating againg from head and find the first node of the cycle
        slow = fast = head;
        for(int i = 0; i < n; i++, fast = fast->next);
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
