from collections import deque

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        starting = deque(sorted((t[1], t[0]) for t in trips))
        leaving = deque(sorted((t[2], t[0]) for t in trips))
        passengers = 0
        for i in range(1000):
            if not starting:
                break
            while starting and starting[0][0] == i:
                _, p = starting.popleft()
                passengers += p
            while leaving and leaving[0][0] == i:
                _, p = leaving.popleft()
                passengers -= p
            if passengers > capacity:
                return False
        return True

