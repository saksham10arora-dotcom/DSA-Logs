```cpp
// LeetCode problem 1192: Critical Connections
// https://leetcode.com/problems/critical-connections-in-a-network/
// Given an undirected graph with n nodes, find all critical connections.

// Brute force approach: Generate all possible edges, then for each edge, 
// remove it and check if the graph is still connected. O(n^2 * (n + m))

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections) {
        // Optimal solution: Tarjan's algorithm with DFS, O(n + m)
        std::unordered_map<int, std::vector<int>> graph;
        for (const auto& connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        std::vector<std::vector<int>> critical;
        std::vector<int> low(n, -1);
        std::vector<int> disc(n, -1);
        std::vector<bool> visited(n, false);
        int time = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, -1, graph, critical, low, disc, visited, time);
            }
        }

        return critical;
    }

    void dfs(int u, int parent, std::unordered_map<int, std::vector<int>>& graph, 
             std::vector<std::vector<int>>& critical, std::vector<int>& low, 
             std::vector<int>& disc, std::vector<bool>& visited, int& time) {
        visited[u] = true;
        disc[u] = low[u] = time++;
        for (int v : graph[u]) {
            if (!visited[v]) {
                dfs(v, u, graph, critical, low, disc, visited, time);
                low[u] = std::min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    critical.push_back({u, v});
                }
            } else if (v != parent) {
                low[u] = std::min(low[u], disc[v]);
            }
        }
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> connections1 = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    std::vector<std::vector<int>> result1 = solution.criticalConnections(4, connections1);
    for (const auto& connection : result1) {
        for (int node : connection) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> connections2 = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    std::vector<std::vector<int>> result2 = solution.criticalConnections(5, connections2);
    for (const auto& connection : result2) {
        for (int node : connection) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> connections3 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    std::vector<std::vector<int>> result3 = solution.criticalConnections(5, connections3);
    for (const auto& connection : result3) {
        for (int node : connection) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```