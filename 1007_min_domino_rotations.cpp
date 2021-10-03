#include <algorithm>
#include <array>

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int a = minRotationsAuxiliary(A, B);
        int b = minRotationsAuxiliary(B, A);
        swap(A[0], B[0]);
        int c = minRotationsAuxiliary(A, B);
        int d = minRotationsAuxiliary(B, A);
        c = c == -1 ? c : c + 1;
        d = d == -1 ? d : d + 1;
        swap(A[0], B[0]);
        const array<int, 4> all = {a, b, c, d};
        int res = *max_element(all.begin(), all.end());
        for (int x : all){
            if (x > -1 and x < res)
                res = x;
        }
        return res;
    }
    
    int minRotationsAuxiliary(vector<int>& A, vector<int>& B){
        int a0 = A[0];
        int swaps_a = 0;
        for (size_t i = 1; i < A.size(); i++){
            if (A[i] == a0)
                continue;
            else if (B[i] == a0)
                swaps_a += 1;
            else
                return -1;
        }
        return swaps_a;
    }
};
