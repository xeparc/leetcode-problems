# ############################################################################
#
# 381. Insert Delete GetRandom O(1) - Duplicates allowed
# https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
#
# ############################################################################
#
#
# Implement the RandomizedCollection class:
#
# RandomizedCollection()
#     Initializes the RandomizedCollection object.
# bool insert(int val)
#     Inserts an item val into the multiset if not present.
#     Returns true if the item was not present, false otherwise.
# bool remove(int val)
#     Removes an item val from the multiset if present.
#     Returns true if the item was present, false otherwise.
#     Note that if val has multiple occurrences in the multiset,
#     we only remove one of them.
# int getRandom()
#     Returns a random element from the current multiset of elements
#     (it's guaranteed that at least one element exists when this method
#     is called). The probability of each element being returned is
#     linearly related to the number of same values the multiset contains.
#
# You must implement the functions of the class such that each
# function works in average O(1) time complexity.
#
#
# Example 1:
#
# Input
# ["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
# [[], [1], [1], [2], [], [1], []]
# Output
# [null, true, false, true, 2, true, 1]
#
# Explanation
# RandomizedCollection randomizedCollection = new RandomizedCollection();
# randomizedCollection.insert(1);   // return True. Inserts 1 to the collection. Returns true as the collection did not contain 1.
# randomizedCollection.insert(1);   // return False. Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
# randomizedCollection.insert(2);   // return True. Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
# randomizedCollection.getRandom(); // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
# randomizedCollection.remove(1);   // return True. Removes 1 from the collection, returns true. Collection now contains [1,2].
# randomizedCollection.getRandom(); // getRandom should return 1 and 2 both equally likely.
#
#
# Constraints:
#
# * -2^31 <= val <= 2^31 - 1
# * At most 2 * 10^5  calls will be made to insert, remove, and getRandom.
# * There will be at least one element in the data structure when getRandom is called.



from random import randint
from collections import defaultdict


class RandomizedCollection:

    def __init__(self):
        self.keys = defaultdict(set)
        self.array = []

    def insert(self, val: int) -> bool:
        present = val in self.keys
        self.array.append(val)
        self.keys[val].add(len(self.array) - 1)
        return not present

    def remove(self, val: int) -> bool:
        present = val in self.keys
        if present:
            indices = self.keys[val]
            i = indices.pop()
            k = self.array[-1]
            self.array[i] = k
            self.array.pop()
            self.keys[k].add(i)
            self.keys[k].remove(len(self.array))
            if not self.keys[val]:
                del self.keys[val]
        return present

    def getRandom(self) -> int:
        i = randint(0, len(self.array) - 1)
        return self.array[i]


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()