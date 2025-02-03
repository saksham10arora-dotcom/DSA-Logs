```cpp
// LeetCode problem 2182: Redundant Connection Variant
// https://leetcode.com/problems/redundant-connection-variant/
// In this problem, we are given a list of edges in a graph and we need to find the redundant connection.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach with O(n^2) complexity
// class Solution {
// public:
//     std::vector<int> findRedundantDirectedConnection(std::vector<std::vector<int>>& edges) {
//         // Create an adjacency list
//         std::unordered_map<int, std::vector<int>> graph;
//         for (const auto& edge : edges) {
//             graph[edge[0]].push_back(edge[1]);
//         }
//         // Check for cycles
//         for (const auto& edge : edges) {
//             graph[edge[0]].pop_back();
//             if (hasCycle(graph)) {
//                 return edge;
//             }
//             graph[edge[0]].push_back(edge[1]);
//         }
//         return {};
//     }
// private:
//     bool hasCycle(const std::unordered_map<int, std::vector<int>>& graph) {
//         std::unordered_set<int> visited;
//         for (const auto& node : graph) {
//             if (hasCycle(graph, node.first, visited)) {
//                 return true;
//             }
//         }
//         return false;
//     }
//     bool hasCycle(const std::unordered_map<int, std::vector<int>>& graph, int node, std::unordered_set<int>& visited) {
//         if (visited.find(node) != visited.end()) {
//             return true;
//         }
//         visited.insert(node);
//         for (const auto& neighbor : graph.at(node)) {
//             if (hasCycle(graph, neighbor, visited)) {
//                 return true;
//             }
//         }
//         visited.erase(node);
//         return false;
//     }
// };

// Optimal solution with O(n) complexity
class Solution {
public:
    std::vector<int> findRedundantDirectedConnection(std::vector<std::vector<int>>& edges) {
        int n = edges.size();
        std::vector<int> parent(n + 1, 0);
        std::vector<int> candidate1, candidate2;
        for (const auto& edge : edges) {
            if (parent[edge[1]] != 0) {
                candidate1 = {parent[edge[1]], edge[1]};
                candidate2 = edge;
                edge[1] = 0;
            } else {
                parent[edge[1]] = edge[0];
            }
        }
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        for (const auto& edge : edges) {
            if (edge[1] == 0) {
                continue;
            }
            int rootX = find(parent, edge[0]);
            int rootY = find(parent, edge[1]);
            if (rootX != rootY) {
                parent[rootY] = rootX;
            } else {
                if (candidate1.empty()) {
                    return edge;
                } else {
                    return candidate1;
                }
            }
        }
        return candidate2;
    }
private:
    int find(std::vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
    std::vector<int> result1 = solution.findRedundantDirectedConnection(edges1);
    std::cout << "[" << result1[0] << ", " << result1[1] << "]" << std::endl;

    std::vector<std::vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 1}, {4, 2}};
    std::vector<int> result2 = solution.findRedundantDirectedConnection(edges2);
    std::cout << "[" << result2[0] << ", " << result2[1] << "]" << std::endl;

    std::vector<std::vector<int>> edges3 = {{2, 1}, {3, 1}, {4, 2}, {1, 4}};
    std::vector<int> result3 = solution.findRedundantDirectedConnection(edges3);
    std::cout << "[" << result3[0] << ", " << result3[1] << "]" << std::endl;

    return 0;
}
```