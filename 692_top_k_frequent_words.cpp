// ****************************************************************************
// 
// 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/
//
// ----------------------------------------------------------------------------

// Given a non-empty list of words, return the k most frequent elements.

// Your answer should be sorted by frequency from highest to lowest.
// If two words have the same frequency, then the word with the
// lower alphabetical order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.

// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.

// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.


#include <algorithm>
#include <unordered_map>
#include <utility>

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<string, int> counts;
        for (string& word : words)
            counts[word]++;
        std::vector<std::pair<int, string>> heap;
        for (auto& p : counts)
            heap.push_back({p.second, p.first});
        const auto cmp =
            [](const auto& p1, const auto& p2){
                if (p1.first == p2.first)
                    return !(p1.second < p2.second);
                else
                    return p1 < p2;
                };
        std::make_heap(heap.begin(), heap.end(), cmp);
        vector<string> res;
        while (!heap.empty() and k--){
            std::pop_heap(heap.begin(), heap.end(), cmp);
            res.push_back(heap.back().second);
            heap.pop_back();
        }
        return res;
    }
};
