// ****************************************************************************
// 
// 725. Split Linked List in Parts
// https://leetcode.com/problems/split-linked-list-in-parts/
//
// ----------------------------------------------------------------------------
//
//
// Given the head of a singly linked list and an integer k, split the linked
// list into k consecutive linked list parts.
// The length of each part should be as equal as possible: no two parts
// should have a size differing by more than one.
// This may lead to some parts being null.
// The parts should be in the order of occurrence in the input list,
// and parts occurring earlier should always have a size greater than
// or equal to parts occurring later.
// Return an array of the k parts.
//
//
// Example 1:
//
// Input: head = [1,2,3], k = 5
// Output: [[1],[2],[3],[],[]]
// Explanation:
// The first element output[0] has output[0].val = 1, output[0].next = null.
// The last element output[4] is null, but its string representation as a ListNode is [].
//
//
// Example 2:
//
// Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
// Output: [[1,2,3,4],[5,6,7],[8,9,10]]
// Explanation:
// The input has been split into consecutive parts with size difference at most 1,
// and earlier parts are a larger size than the later parts.
//
//
// Constraints:
//
// The number of nodes in the list is in the range [0, 1000].
// 0 <= Node.val <= 1000
// 1 <= k <= 50


#include <vector>

using namespace std;

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

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> parts(k);
        ListNode* current = head;
        int N = 0;
        while(current){
            N += 1;
            current = current->next;
        }
        current = head;
        // `j` is the index of the current part
        for (int j = 0; j < k && current; j++){
            // How many elements are in this part?
            int n = j < (N % k) ? N / k + 1 : N / k;
            parts[j] = current;
            for (int i = 1; i < n; i++, current=current->next);
            ListNode* last = current;
            current = current->next;
            last->next = nullptr;
        }
        return parts;
        // Fill first k
        // int j = 0;
        // for(int i = 0; i < k && current; i++, j++, current=current->next)
        //     parts[j] = current;
        // if (j < k)
        //     return parts;
        // j = 1;
        // while (current){
        //     for (int i = j; i < k; i++)
        //         parts[i] = parts[i]->next;
        //     if (j == k)
        //         j = 1;
        //     else
        //         j += 1;
        //     current = current->next;
        // }
        // Append NULL pointers
    }
};
