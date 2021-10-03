//////////////////////////////////////////////////////////////////////////////
//
// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/
//
// ***************************************************************************


// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:

// * Integers in each row are sorted from left to right.
// * The first integer of each row is greater than the last
// integer of the previous row.

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
// Output: true

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
// Output: false

// Input: matrix = [], target = 0
// Output: false

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 0 <= m, n <= 100
// -10^4 <= matrix[i][j], target <= 10^4



#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size();
        if (!matrix.size() or !matrix[0].size())
            return false;
        while (lo < hi){
            int mid = lo / 2 + hi / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target)
                hi = mid;
            else
                lo = mid + 1;
        }
        hi--;
        if (hi < 0 or hi == matrix.size())
            return false;
        vector<int>& row = matrix[hi];
        lo = 0, hi = row.size();
        while (lo < hi){
            int mid = lo / 2 + hi / 2;
            if (row[mid] == target)
                return true;
            else if (row[mid] > target)
                hi = mid;
            else
                lo = mid + 1;
        }
        return false;
    }
};
