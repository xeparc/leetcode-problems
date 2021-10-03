from functools import reduce
from operator import mul

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        def C(n, k):
            return reduce(mul, range(n, n - k, -1), 1) // reduce(mul, range(1, k + 1), 1)
        return C(m + n - 2, m - 1)
 
