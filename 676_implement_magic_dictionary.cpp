// ///////////////////////////////////////////////////////////////////////////
//
// 676. Implement Magic Dictionary
// https://leetcode.com/problems/implement-magic-dictionary/
//
// ***************************************************************************
//
//
// Design a data structure that is initialized with a list of different words.
// Provided a string, you should determine if you can change exactly one
// character in this string to match any word in the data structure.
//
// Implement the MagicDictionary class:
//
// * MagicDictionary()                     Initializes the object.
// * void buildDict(String[] dictionary)   Sets the data structure with an
//                                         array of distinct strings dictionary.
// * bool search(String searchWord)        Returns true if you can change exactly
//                                         one character in searchWord to match
//                                         any string in the data structure,
//                                         otherwise returns false.
//
//
// Example 1:
//
// Input
// ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
// [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
// Output
// [null, null, false, true, false, false]
// Explanation
// MagicDictionary magicDictionary = new MagicDictionary();
// magicDictionary.buildDict(["hello", "leetcode"]);
// magicDictionary.search("hello"); // return False
// magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
// magicDictionary.search("hell"); // return False
// magicDictionary.search("leetcoded"); // return False
//
//
// Constraints:
//
// * 1 <= dictionary.length <= 100
// * 1 <= dictionary[i].length <= 100
// * dictionary[i] consists of only lower-case English letters.
// * All the strings in dictionary are distinct.
// * 1 <= searchWord.length <= 100
// * searchWord consists of only lower-case English letters.
// * buildDict will be called only once before search.
// * At most 100 calls will be made to search.



#include <algorithm>
#include <iterator>
#include <map>
#include <string>
#include <vector>

using namespace std;


struct PrefixTrieNode {
    int val;
    vector<PrefixTrieNode*> children;
    vector<int> wordIds;
};

class PrefixTrie {
public:
    PrefixTrie() : root{-1, {}, {}} {}

    void insert(string word, int wordId){
        PrefixTrieNode* x = &root;
        bool duplicate = find(x->wordIds.begin(),
                         x->wordIds.end(),
                         wordId) != x->wordIds.end();
        if (!duplicate)
            x->wordIds.push_back(wordId);
        for (int i = 0; i < word.size(); i++){
            bool found = false;
            bool duplicate = false;
            for (PrefixTrieNode* node : x->children){
                if (node->val == word[i]){
                    found = true;
                    duplicate = find(node->wordIds.begin(),
                                     node->wordIds.end(),
                                     wordId) != node->wordIds.end();
                    if (duplicate)
                        break;
                    else{
                        node->wordIds.push_back(wordId);
                        x = node;
                        break;
                    }
                }
            }
            if (duplicate)
                break;
            if (!found){
                PrefixTrieNode* t = new PrefixTrieNode{word[i], {}, {wordId}};
                x->children.push_back(t);
                x = t;
            }
        }
    }

    vector<int> search(string word){
        PrefixTrieNode* x = &root;
        for (int i = 0; i < word.size(); i++){
            bool found = false;
            for (PrefixTrieNode* node : x->children){
                if (node->val == word[i]){
                    found = true;
                    x = node;
                    break;
                }
            }
            if (!found) break;
        }
        return x->wordIds;
    }

private:
    PrefixTrieNode root;
};


// "Smart", but very slow solution
// ----------------------------------------------------------------------------
class MagicDictionary {
public:
    MagicDictionary() : prefixTrie(), suffixTrie(), wordMap(), idCounter{0} {};

    void buildDict(vector<string> dictionary) {
        for (const string& word : dictionary) {
            idCounter++;
            prefixTrie.insert(word, idCounter);
            string reversed = string(word.rbegin(), word.rend());
            suffixTrie.insert(reversed, idCounter);
            wordMap[idCounter] = word;
        }
    }

    bool search(string searchWord) {
        for (int i = 0; i < searchWord.size(); i++){
            string prefix = searchWord.substr(0, i);
            string suffix = searchWord.substr(i+1, searchWord.size());
            suffix = string(suffix.rbegin(), suffix.rend());
            vector<int> prefixIds = prefixTrie.search(prefix);
            vector<int> suffixIds = suffixTrie.search(suffix);
            sort(prefixIds.begin(), prefixIds.end());
            sort(suffixIds.begin(), suffixIds.end());
            vector<int> common;
            set_intersection(
                prefixIds.begin(), prefixIds.end(),
                suffixIds.begin(), suffixIds.end(),
                back_inserter(common)
            );
            for (int id : common){
                string W = wordMap[id];
                if (W.size() != searchWord.size())
                    continue;
                int i = 0, j = searchWord.size() - 1;
                for(; i < searchWord.size() && searchWord[i] == W[i]; i++);
                for(; j >= 0 && searchWord[j] == W[j]; j--);
                if (i == j && searchWord[i] != W[i])
                    return true;
            }
        }
        return false;
    }

private:
    PrefixTrie prefixTrie;
    PrefixTrie suffixTrie;
    map<int, string> wordMap;
    int idCounter;
};


// Naive, but very fast - 98%
// ----------------------------------------------------------------------------
class MagicDictionaryFast {
public:
    MagicDictionaryFast() : words() {};

    void buildDict(vector<string> dictionary) {
        words.clear();
        words.insert(words.end(), dictionary.begin(), dictionary.end());
    }

    bool search(string searchWord) {
        for (const string& word : words){
            if (word.size() != searchWord.size())
                continue;
            int i = 0, j = searchWord.size() - 1;
            for(; i < searchWord.size() && searchWord[i] == word[i]; i++);
            for(; j >= 0 && searchWord[j] == word[j]; j--);
                if (i == j && searchWord[i] != word[i])
                    return true;
        }
        return false;
    }

public:
    vector<string> words;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
