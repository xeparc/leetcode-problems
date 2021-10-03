from collections import deque

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        starting = sorted((t[1], t[0]) for t in trips)
        leaving = sorted((t[2], t[0]) for t in trips)
        
        leaving = deque()
        passengers = 0
        sortq = lambda x: x[1]
        for p, i, j in trips:
            while leaving and leaving[0][1] <= i:
                toleave = leaving.popleft()
                passengers -= toleave[0]
            passengers += p
            if passengers > capacity:
                return False
            leaving.append((p, j))
            leaving = deque(sorted(leaving, key=sortq))
        return True



from collections import defaultdict

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        locations = defaultdict(int)
        for t in trips:
            locations[t[1]] += t[0]
            locations[t[2]] -= t[0]
        passengers = 0
        for k in sorted(locations.keys()):
            passengers += locations[k]
            if passengers > capacity:
                return False
        return True


class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        locations = [0] * 1001
        for p, i, j in trips:
            locations[i] += p
            locations[j] -= p
        passengers = 0
        for p in locations:
            passengers += p
            if passengers > capacity:
                return False
        return True

