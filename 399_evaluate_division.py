from collections import defaultdict
from functools import reduce
from operator import mul


class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:

        graph = defaultdict(list)
        for (num, denom), val in zip(equations, values):
            graph[num].append((num, denom, val))
            graph[denom].append((denom, num, 1 / val))
        
        result = []
        for n, d in queries:
            if n not in graph or d not in graph:
                result.append(-1.0)
                continue
            chain = search(graph, n, d, set())
            # print(chain)
            if not chain:
                result.append(-1.0)
            else:
                result.append(reduce(mul, (x[2] for x in chain)))
        return result
            
            
def search(graph, N, D, visited):
    for n in graph[N]:
        if n not in visited:
            visited.add(n)
            if n[1] == D:
                return [n]
            else:
                r = search(graph, n[1], D, visited)
                if r:
                    return [n] + r
    return []


