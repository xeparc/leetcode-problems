class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        d = {}
        for n in nums:
            if n in d:
                d[n] += 1
            else:
                if len(d) < 2:
                    d[n] = 1
                else:
                    d = {k:v - 1 for k, v in d.items() if v > 1}
        N = len(nums) // 3
        res = []
        for k in d:
            if nums.count(k) > N:
                res.append(k)
        return res


