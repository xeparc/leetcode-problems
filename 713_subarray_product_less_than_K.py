class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        i, prod, count = 0, 1, 0
        for j, n in enumerate(nums):
            prod *= n
            while i <= j and prod >= k:
                prod /= nums[i]
                i += 1
            count += j - i + 1
        return count

