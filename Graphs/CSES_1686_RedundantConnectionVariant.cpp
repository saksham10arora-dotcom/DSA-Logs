```cpp
// Redundant Connection Variant, https://cses.fi/problemset/task/1686
// Given a directed graph, find the edge that, when removed, will make the graph a directed acyclic graph (DAG).

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

// Brute force approach: Try removing each edge and check if the resulting graph is a DAG. O(n^2 * m)
// class Solution {
// public:
//     int redundantConnection(std::vector<std::vector<int>>& edges) {
//         int n = edges.size();
//         for (int i = 0; i < n; i++) {
//             std::vector<std::vector<int>> graph(n + 1);
//             for (int j = 0; j < n; j++) {
//                 if (i != j) {
//                     graph[edges[j][0]].push_back(edges[j][1]);
//                 }
//             }
//             if (!hasCycle(graph)) {
//                 return edges[i][0];
//             }
//         }
//         return -1;
//     }

//     bool hasCycle(const std::vector<std::vector<int>>& graph) {
//         std::vector<bool> visited(graph.size(), false);
//         std::vector<bool> onStack(graph.size(), false);
//         for (int i = 1; i < graph.size(); i++) {
//             if (!visited[i] && hasCycleUtil(graph, i, visited, onStack)) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     bool hasCycleUtil(const std::vector<std::vector<int>>& graph, int node, std::vector<bool>& visited, std::vector<bool>& onStack) {
//         if (onStack[node]) {
//             return true;
//         }
//         if (visited[node]) {
//             return false;
//         }
//         visited[node] = true;
//         onStack[node] = true;
//         for (int neighbor : graph[node]) {
//             if (hasCycleUtil(graph, neighbor, visited, onStack)) {
//                 return true;
//             }
//         }
//         onStack[node] = false;
//         return false;
//     }
// };

// Optimal solution: Use union-find to detect cycles. O(n * alpha(n))
class Solution {
public:
    int redundantConnection(std::vector<std::vector<int>>& edges) {
        int n = edges.size();
        std::vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (const auto& edge : edges) {
            if (!unionNodes(parent, edge[0], edge[1])) {
                return edge[0];
            }
        }
        return -1;
    }

    int findParent(const std::vector<int>& parent, int node) {
        if (parent[node] != node) {
            parent[node] = findParent(parent, parent[node]);
        }
        return parent[node];
    }

    bool unionNodes(std::vector<int>& parent, int node1, int node2) {
        int parent1 = findParent(parent, node1);
        int parent2 = findParent(parent, node2);
        if (parent1 == parent2) {
            return false;
        }
        parent[parent1] = parent2;
        return true;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
    std::cout << solution.redundantConnection(edges1) << std::endl;  // Output: 3

    std::vector<std::vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    std::cout << solution.redundantConnection(edges2) << std::endl;  // Output: 1

    std::vector<std::vector<int>> edges3 = {{1, 2}, {2, 3}, {3, 1}};
    std::cout << solution.redundantConnection(edges3) << std::endl;  // Output: 3

    return 0;
}
```