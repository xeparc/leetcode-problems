// ///////////////////////////////////////////////////////////////////////////
//
// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
// 
// ***************************************************************************
//
//
// You are given an integer n. There is an undirected graph with n nodes,
// numbered from 0 to n - 1. You are given a 2D integer array edges where
// edges[i] = [ai, bi] denotes that there exists an undirected edge
// connecting nodes ai and bi.
// Return the number of pairs of different nodes that are unreachable
// from each other.
// 
// Example 1:
// Input: n = 3, edges = [[0,1],[0,2],[1,2]]
// Output: 0
// Explanation: There are no pairs of nodes that are unreachable from each other.
// Therefore, we return 0.
// 
// Example 2:
// Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
// Output: 14
// Explanation: There are 14 pairs of nodes that are unreachable from each other:
// [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
// Therefore, we return 14.
// 
// Constraints:
//     * 1 <= n <= 10^5
//     * 0 <= edges.length <= 2 * 10^5
//     * edges[i].length == 2
//     * 0 <= ai, bi < n
//     * ai != bi
//     * There are no repeated edges.


#include <numeric>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parents(n, 0);
        std::iota(parents.begin(), parents.end(), 0);
        vector<long long> ranks(n, 0);
        for (const auto& edge : edges){
            link(edge[0], edge[1], parents, ranks);
        }

        unordered_map<int, long long> counts;
        for (int i = 0; i < n; i++)
            counts[findRoot(i, parents)]++;

        long long result = 0;
        long long nodes = 0;
        for (const auto& pair : counts){
            result += static_cast<long long>(nodes) * pair.second;
            nodes += pair.second;
        }
        return result;
    }

    int findRoot(int node, vector<int>& parents){
        if (node != parents[node])
            parents[node] = findRoot(parents[node], parents);
        return parents[node];
    }

    int link(int a, int b, vector<int>& parents, vector<long long>& ranks) {
        a = findRoot(a, parents);
        b = findRoot(b, parents);
        if (ranks[a] < ranks[b]){
            parents[a] = b;
        } else {
            parents[b] = a;
        }
        if (ranks[a] == ranks[b]){
            ranks[a] = ranks[b] + 1;
        }
        return 0;
    }
};
