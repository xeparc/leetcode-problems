// ****************************************************************************
// 
// 445. Add Two Numbers II
// https://leetcode.com/problems/add-two-numbers-ii/
//
// ----------------------------------------------------------------------------


// You are given two non-empty linked lists representing two non-negative
// integers. The most significant digit comes first and each of their nodes
// contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero,
// except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words,
// reversing the lists is not allowed.

// Example:
// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7


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

#include <stack>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> num1;
        std::stack<int> num2;
        for (; l1; l1 = l1->next)
            num1.push(l1->val);
        for (; l2; l2 = l2->next)
            num2.push(l2->val);
        int carry = 0;
        ListNode* head = new ListNode;
        while (!num1.empty() or !num2.empty()){
            int a = 0, b = 0;
            if (!num1.empty()){
                a = num1.top();
                num1.pop();
            }
            if (!num2.empty()){
                b = num2.top();
                num2.pop();
            }
            head->val = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            ListNode* curr = new ListNode;
            curr->next = head;
            head = curr;
        }
        if (carry){
            head->val = carry;
            return head;
        } else {
            ListNode* result = head->next;
            delete head;
            return result;
        }
    }
};

// 
// With std::vector
// ****************************************************************************
#include <vector>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::vector<int> num1;
        std::vector<int> num2;
        for (; l1; l1 = l1->next)
            num1.push_back(l1->val);
        for (; l2; l2 = l2->next)
            num2.push_back(l2->val);
        int carry = 0;
        ListNode* head = new ListNode;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 or j >= 0){
            int a = i >= 0 ? num1[i--] : 0;
            int b = j >= 0 ? num2[j--] : 0;
            head->val = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            ListNode* curr = new ListNode;
            curr->next = head;
            head = curr;
        }
        if (carry){
            head->val = carry;
            return head;
        } else {
            ListNode* result = head->next;
            delete head;
            return result;
        }
    }
};


// 
// O(1) extra memory, but overflows
// ****************************************************************************
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = 0, b = 0;
        for (; l1; l1 = l1->next){
            a *= 10;
            a += l1->val;
        }
        for (; l2; l2 = l2->next){
            b *= 10;
            b += l2->val;
        }
        a += b;
        ListNode* head = new ListNode;
        while (a > 9){
            head->val = a % 10;
            a /= 10;
            head = new ListNode(0, head);
        }
        head->val = a;
        return head;
    }
};
