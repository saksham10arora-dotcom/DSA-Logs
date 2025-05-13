```cpp
// LeetCode problem 1486: Redundant Connection Optimized
// https://leetcode.com/problems/redundant-connection-optimized/
// In this problem, we are given an array of edges in a graph and we need to find the redundant connection.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach: O(n^2) complexity
// This approach involves checking every possible subset of edges to see if it forms a connected graph.
// However, this approach is inefficient and will not work for large inputs.

// Optimal solution: O(n) complexity
// We can use a union-find data structure to keep track of the connected components in the graph.
// We iterate over the edges and for each edge, we check if the two nodes are already in the same connected component.
// If they are, then this edge is the redundant connection.

class UnionFind {
public:
    std::vector<int> parent;
    UnionFind(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
    UnionFind uf(edges.size());
    for (const auto& edge : edges) {
        int x = edge[0];
        int y = edge[1];
        if (uf.find(x) == uf.find(y)) {
            return edge;
        }
        uf.union_(x, y);
    }
    return {};
}

int main() {
    std::vector<std::vector<int>> edges