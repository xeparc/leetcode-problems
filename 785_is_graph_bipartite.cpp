//////////////////////////////////////////////////////////////////////////////
//
// 785. Is Graph Bipartite?
// https://leetcode.com/problems/is-graph-bipartite/
//
// ***************************************************************************


// There is an undirected graph with n nodes, where each node is numbered
// between 0 and n - 1. You are given a 2D array graph, where graph[u] is an
// array of nodes that node u is adjacent to. More formally, for each v in
// graph[u], there is an undirected edge between node u and node v.

// The graph has the following properties:

// * There are no self-edges (graph[u] does not contain u).
// * There are no parallel edges (graph[u] does not contain duplicate values).
// * If v is in graph[u], then u is in graph[v] (the graph is undirected).
// * The graph may not be connected, meaning there may be two nodes u and v
//   such that there is no path between them.
// * A graph is bipartite if the nodes can be partitioned into two independent
//   sets A and B such that every edge in the graph connects a node in set A
//   and a node in set B.

// Return true if and only if it is bipartite.


// Example 1:

// Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// Output: false
// Explanation: There is no way to partition the nodes into two independent
// sets such that every edge connects a node in one and a node in the other.


// Example 2:

// Input: graph = [[1,3],[0,2],[1,3],[0,2]]
// Output: true
// Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.


// Constraints:

// * graph.length == n
// * 1 <= n <= 100
// * 0 <= graph[u].length < n
// * 0 <= graph[u][i] <= n - 1
// * graph[u] does not contain u.
// * All the values of graph[u] are unique.
// * If graph[u] contains v, then graph[v] contains u.



#include <algorithm>
#include <array>
#include <numeric>
#include <vector>

using namespace std;


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        std::array<int, 100> setA;
        std::array<int, 100> setB;
        std::array<int, 100> visited;
        std::fill_n(setA.begin(), 100, 0);
        std::fill_n(setB.begin(), 100, 0);
        std::fill_n(visited.begin(), 100, 0);

        for (int i = 0; i < graph.size(); i++){
            if (visited[i] == 0 && !dfsAdd(i, graph, setA, setB, visited))
                return false;
        }
        return true;
    }

    bool dfsAdd(int vertex,
                const vector<vector<int>>& graph,
                std::array<int, 100>& setA,
                std::array<int, 100>& setB,
                std::array<int, 100>& visited)
    {
        setA[vertex] = 1;
        visited[vertex] = 1;
        if (setB[vertex])
            return false;
        for (int i : graph[vertex]){
            if (setA[i])
                return false;
            if (!visited[i] && !dfsAdd(i, graph, setB, setA, visited))
                return false;
        }
        return true;
    }
};


// [[2,3,5,6,7,8,9],[2,3,4,5,6,7,8,9],[0,1,3,4,5,6,7,8,9],[0,1,2,4,5,6,7,8,9],
//  [1,2,3,6,9],[0,1,2,3,7,8,9],[0,1,2,3,4,7,8,9],[0,1,2,3,5,6,8,9],[0,1,2,3,5,6,7],[0,1,2,3,4,5,6,7]]