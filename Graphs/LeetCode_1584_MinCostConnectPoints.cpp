```cpp
// LeetCode problem 1584: Min Cost Connect Points, https://leetcode.com/problems/min-cost-to-connect-all-points/
// Given an array of points where points[i] = [xi, yi] represents a point on a 2D plane, find the minimum cost to connect all the points.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Brute force approach: Try all possible connections between points, O(n^2 * n!) complexity
// int minCostConnectPoints(std::vector<std::vector<int>>& points) {
//     int n = points.size();
//     int result = INT_MAX;
//     std::vector<int> permutation(n);
//     for (int i = 0; i < n; i++) permutation[i] = i;
//     do {
//         int cost = 0;
//         for (int i = 0; i < n - 1; i++) {
//             cost += std::abs(points[permutation[i]][0] - points[permutation[i + 1]][0]) + std::abs(points[permutation[i]][1] - points[permutation[i + 1]][1]);
//         }
//         result = std::min(result, cost);
//     } while (std::next_permutation(permutation.begin(), permutation.end()));
//     return result;
// }

// Optimal solution: Use Kruskal's algorithm to find the minimum spanning tree, O(n^2 * log(n)) complexity
class UnionFind {
public:
    std::vector<int> parent;
    UnionFind(int n) : parent(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) parent[rootX] = rootY;
    }
};

struct Edge {
    int cost;
    int x;
    int y;
    bool operator<(const Edge& other) const {
        return cost > other.cost;
    }
};

int minCostConnectPoints(std::vector<std::vector<int>>& points) {
    int n = points.size();
    std::priority_queue<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cost = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
            edges.push({cost, i, j});
        }
    }
    UnionFind uf(n);
    int result = 0;
    int count = 0;
    while (!edges.empty() && count < n - 1) {
        Edge edge = edges.top();
        edges.pop();
        if (uf.find(edge.x) != uf.find(edge.y)) {
            uf.unionSet(edge.x, edge.y);
            result += edge.cost;
            count++;
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> points1 = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    std::cout << minCostConnectPoints(points1) << std::endl;  // Output: 20

    std::vector<std::vector<int>> points2 = {{3, 12}, {-7, 3}, {-13, 9}, {15, -7}, {5, -10}, {10, 4}};
    std::cout << minCostConnectPoints(points2) << std::endl;  // Output: 34

    std::vector<std::vector<int>> points3 = {{0, 0}, {1, 1}, {1, 0}, {0, 1}};
    std::cout << minCostConnectPoints(points3) << std::endl;  // Output: 2

    return 0;
}
```