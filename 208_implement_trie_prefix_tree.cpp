// ///////////////////////////////////////////////////////////////////////////
//
// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/
//
// ***************************************************************************
//
//
// A trie (pronounced as "try") or prefix tree is a tree data structure
// used to efficiently store and retrieve keys in a dataset of strings.
// There are various applications of this data structure,
// such as autocomplete and spellchecker.
//
// Implement the Trie class:
//
// Trie()                              Initializes the trie object.
// void insert(String word)            Inserts the string word into the trie.
// boolean search(String word)         Returns true if the string word is in
//                                     the trie (i.e., was inserted before),
//                                     and false otherwise.
// boolean startsWith(String prefix)   Returns true if there is a previously
//                                     inserted string word that has the prefix
//                                     prefix, and false otherwise.
//
//
// Example 1:
//
// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]
//
// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True
//
//
// Constraints:
//
// * 1 <= word.length, prefix.length <= 2000
// * word and prefix consist only of lowercase English letters.
// * At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.



#include <string>
#include <vector>

using namespace std;


struct TrieNode {
    int val;
    int terminal;
    vector<TrieNode*> children;
};

class Trie {
public:
    Trie() : root{-1, 0, {}} {}

    void insert(string word) {
        TrieNode* x = &root;
        for (int i = 0; i < word.size() - 1; i++){
            bool create = true;
            for (TrieNode* node : x->children){
                if (node->val == word[i]){
                    x = node;
                    create = false;
                    break;
                }
            }
            if (create){
                TrieNode* next = new TrieNode{word[i], 0, {}};
                x->children.push_back(next);
                x = next;
            }
        }
        for (TrieNode* node : x->children){
            if (node->val == word.back()){
                node->terminal = 1;
                return;
            }
        }
        TrieNode* t = new TrieNode{word.back(), 1, {}};
        x->children.push_back(t);
        return;
    }

    bool search(string word) {
        TrieNode* x = &root;
        for (char c : word){
            bool flag = false;
            for (TrieNode* node : x->children){
                if (node->val == c){
                    x = node;
                    flag = true;
                    break;
                }
            }
            if (!flag) return false;
        }
        return x->terminal;
    }

    bool startsWith(string prefix) {
        TrieNode* x = &root;
        for (char c: prefix){
            bool found = false;
            for (TrieNode* node : x->children){
                if (node->val == c){
                    x = node;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }

private:
    TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
