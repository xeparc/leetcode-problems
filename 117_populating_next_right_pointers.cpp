//////////////////////////////////////////////////////////////////////////////
//
// 117. Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
//
// ***************************************************************************


// Given a binary tree

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node.
// If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Follow up:

// You may only use constant extra space.
// Recursive approach is fine, you may assume implicit stack space does not
// count as extra space for this problem.


// Example 1:
// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]
// Explanation: Given the above binary tree (Figure A), your function should
// populate each next pointer to point to its next right node, just like in
// Figure B. The serialized output is in level order as connected by the next
// pointers, with '#' signifying the end of each level.


// Constraints:

// The number of nodes in the given tree is less than 6000.
// -100 <= node.val <= 100



// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        // x points to the leftmost node at depth i
        // y points to the leftmost node at depth i + 1
        // w iterates at depth i
        // z iterates at depth i + 1
        Node* x = root;
        while(x) {
            Node* w = x;
            Node* y = nullptr;
            // Find leftmost node at depth i + 1, given the leftmost at depth i
            while(w && !y){
                y = w->left ? w->left : w->right;
                if (!y) w = w->next;
            }
            // Check if we actually found a node at depth i + 1
            if (!y) break;
            Node* z = y;
            // If y has sibling, set z to it's sibling
            if ((z == w->left) && w->right)
                z = z->next = w->right;
            // Advance w
            w = w->next;
            // Chain all nodes at depth i + 1
            while(w && z){
                if(w->left)  z = z->next = w->left;
                if(w->right) z = z->next = w->right;
                w = w->next;
            }
            // Move to depth i + 1
            x = y;
        }
        return root;
    }
};