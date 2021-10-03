class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        # trips.sort(lambda L: L[1:])
        road = [0] * 1001
        for t in trips:
            p, i, j = t
            for k in range(i, j):
                road[k] += p
        return all(r <= capacity for r in road)

