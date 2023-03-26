// ///////////////////////////////////////////////////////////////////////////
//
// 2360. Longest Cycle in a Graph
// https://leetcode.com/problems/longest-cycle-in-a-graph/description/
// 
// ***************************************************************************
//
//
// You are given a directed graph of n nodes numbered from 0 to n - 1,
// where each node has at most one outgoing edge.
// The graph is represented with a given 0-indexed array edges of size n,
// indicating that there is a directed edge from node i to node edges[i].
// If there is no outgoing edge from node i, then edges[i] == -1.
// Return the length of the longest cycle in the graph. If no cycle exists, return -1.
// A cycle is a path that starts and ends at the same node.
// 
// 
// Example 1:
// Input: edges = [3,3,4,2,3]
// Output: 3
// Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
// The length of this cycle is 3, so 3 is returned.
// 
// Example 2:
// Input: edges = [2,-1,3,1]
// Output: -1
// Explanation: There are no cycles in this graph.
// 
// Constraints:
//     * n == edges.length
//     * 2 <= n <= 10^5
//     * -1 <= edges[i] < n
//     * edges[i] != i



#include <deque>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:

    /* DFS solution */
    int longestCycle(vector<int>& edges) {
        vector<int> visited(edges.size(), 0);
        int maxlen = -1;
        for (int i = 0; i < edges.size(); i++){
            if (visited[i])
                continue;
            unordered_map<int, int> cycle;
            // Save the visit time of each node
            int visit = 0;
            int x = i;
            // Follow neighbours
            while (true){
                if (x == -1 || visited[x])
                    break;
                if (cycle.count(x)){
                    int len = visit - cycle[x];
                    maxlen = max(len, maxlen);
                    break;
                }
                cycle[x] = visit++;
                x = edges[x];
            }
            for (const auto& pair : cycle){
                visited[pair.first] = 1;
            }
        }
        return maxlen;
    }

/*
        Kahn’s algorithm works by keeping track of the number of incoming
        edges into each node (indegree). It works by repeatedly visiting the
        nodes with an indegree of zero and deleting all the edges associated
        with it leading to a decrement of indegree for the nodes whose
        incoming edges are deleted. This process continues until no element
        with zero indegree can be found. If there is a cycle, there is no way of
        making the indegree of nodes in the cycle to 0 due to the cyclic
        dependency. We cannot visit nodes in the cycle.
        Because each node can only have one outgoing edge, no node in the cycle
        can have an outgoing edge to a node that is not in the cycle.
        The only outoging edge of a node in the cycle would be consumed by the
        cycle itself. This means that there would be no other node that would
        not be visited because of the unvisited nodes in the cycle.
        As a result, all the nodes not in the cycle would be visited and
        only the nodes in the cycle would be not visited using this algorithm.
        After completing Kahn's algorithm, we iterate over all the unvisited nodes
        to determine the length of the longest cycle. For an unvisited node node,
        we begin by traversing from node to its neighbor using edge[node],
        then to its neighbor, and so on, until we return to node. We keep track
        of the number of nodes in the cycle (the number of nodes in the cycle
        equals the length of the cycle) and mark all of the nodes in this cycle
        as visited so that we don't visit them again. From all the formed cycles,
        we chose the one with the longest cycle length.
        If all of the nodes are visited during Kahn's algorithm, the graph
        has no cycle.
*/
    int longestCycleKahn(vector<int>& edges) {
        // Compute indegree
        vector<int> indegree(edges.size(), 0);
        for (int v : edges)
            if (v != -1) indegree[v]++;

        // Initialize queue with nodes of indegree == 0
        deque<int> Q;
        for (int i = 0; i < edges.size(); i++){
            if (indegree[i] == 0) Q.push_back(i);
        }

        // Kahn's algorithm. Delete incoming edges.
        while (!Q.empty()) {
            int x = Q.front();
            int y = edges[x];
            Q.pop_front();
            if (y != -1){
                indegree[y]--;
                if (indegree[y] == 0)
                    Q.push_back(y);
            }
        }

        // Count the lenght of cycles
        int maxlen = -1;
        vector<int> visited(edges.size(), 0);
        for (int i = 0; i < edges.size(); i++){
            if (visited[i] == 0 && indegree[i]){
                int len = 1;
                for (int j = edges[i]; j != i; j = edges[j], len++){
                    if (visited[j])
                        break;
                    visited[j] = 1;
                }
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};
