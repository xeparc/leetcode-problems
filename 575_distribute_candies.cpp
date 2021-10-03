//////////////////////////////////////////////////////////////////////////////
//
// 575. Distribute Candies
// https://leetcode.com/problems/distribute-candies/
//
// ***************************************************************************



#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        std::sort(candyType.begin(), candyType.end());
        int last = candyType[0];
        int eat = 1;
        for (size_t i = 1; i < candyType.size(); i++){
            if (candyType[i] != last){
                last = candyType[i];
                eat++;
            }
        }
        return std::min(candyType.size() / 2, (size_t)eat);
    }
};
