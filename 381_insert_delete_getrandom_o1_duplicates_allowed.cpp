// ///////////////////////////////////////////////////////////////////////////
//
// 381. Insert Delete GetRandom O(1) - Duplicates allowed
// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
//
// ***************************************************************************
//
//
// Implement the RandomizedCollection class:
//
// RandomizedCollection()
//     Initializes the RandomizedCollection object.
// bool insert(int val)
//     Inserts an item val into the multiset if not present.
//     Returns true if the item was not present, false otherwise.
// bool remove(int val)
//     Removes an item val from the multiset if present.
//     Returns true if the item was present, false otherwise.
//     Note that if val has multiple occurrences in the multiset,
//     we only remove one of them.
// int getRandom()
//     Returns a random element from the current multiset of elements
//     (it's guaranteed that at least one element exists when this method
//     is called). The probability of each element being returned is
//     linearly related to the number of same values the multiset contains.
//
// You must implement the functions of the class such that each
// function works in average O(1) time complexity.
//
//
// Example 1:
//
// Input
// ["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
// [[], [1], [1], [2], [], [1], []]
// Output
// [null, true, false, true, 2, true, 1]
//
// Explanation
// RandomizedCollection randomizedCollection = new RandomizedCollection();
// randomizedCollection.insert(1);   // return True. Inserts 1 to the collection. Returns true as the collection did not contain 1.
// randomizedCollection.insert(1);   // return False. Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
// randomizedCollection.insert(2);   // return True. Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
// randomizedCollection.getRandom(); // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
// randomizedCollection.remove(1);   // return True. Removes 1 from the collection, returns true. Collection now contains [1,2].
// randomizedCollection.getRandom(); // getRandom should return 1 and 2 both equally likely.
//
//
// Constraints:
//
// * -2^31 <= val <= 2^31 - 1
// * At most 2 * 10^5  calls will be made to insert, remove, and getRandom.
// * There will be at least one element in the data structure when getRandom is called.



#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


class RandomizedCollection {
public:
    RandomizedCollection(){}

    bool insert(int val) {
        bool flag = _pos[val].empty();
        _array.push_back(val);
        _pos[val].insert(_array.size() - 1);
        return flag;
    }

    bool remove(int val) {
        bool flag = !_pos[val].empty();
        if (flag){
            // Update _pos[val]
            unordered_set<size_t>& indices = _pos[val];
            size_t i = *indices.begin();
            indices.erase(i);
            // Update _array (halfway)
            size_t j = _array.back();
            _array[i] = j;
            // Update pos[i]
            _pos[j].insert(i);
            _pos[j].erase(_array.size() - 1);
            _array.pop_back();
        }
        return flag;
    }

    int getRandom() {
        uniform_int_distribution<int> dist(0, _array.size() - 1);
        return _array[dist(_engine)];
    }

private:
    unordered_map<int, unordered_set<size_t>> _pos;
    vector<int> _array;
    default_random_engine _engine;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */