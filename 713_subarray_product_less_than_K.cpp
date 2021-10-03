#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i{0}, count{0}, product{1};
        for (int j = 0; j < nums.size(); j++){
            product *= nums[j];
            while (i <= j and product >= k)
                product /= nums[i++];
            count += (j - i + 1);
        }
        return count;
    }
};

