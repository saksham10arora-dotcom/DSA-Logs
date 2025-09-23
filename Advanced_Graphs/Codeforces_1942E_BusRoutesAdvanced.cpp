```cpp
// Codeforces_1942E_BusRoutesAdvanced, https://codeforces.com/contest/1942/problem/E
// Given a graph with n nodes and m edges, find the shortest path from node 1 to all other nodes.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// Brute force approach: O(n * m) complexity
void bruteForce(int n, const std::vector<std::vector<int>>& graph) {
    std::vector<int> distance(n + 1, std::numeric_limits<int>::max());
    distance[1] = 0;

    for (int i = 1; i <= n; ++i) {
        for (const auto& edge : graph) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (distance[u] != std::numeric_limits<int>::max() && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << distance[i] << " ";
    }
    std::cout << std::endl;
}

// Optimal solution: O(n * m * log(n)) complexity using Bellman-Ford algorithm
void optimalSolution(int n, const std::vector<std::vector<int>>& graph) {
    std::vector<int> distance(n + 1, std::numeric_limits<int>::max());
    distance[1] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        for (const auto& edge : graph) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (distance[u] != std::numeric_limits<int>::max() && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << distance[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test case 1
    int n = 5;
    std::vector<std::vector<int>> graph = {{1, 2, 1}, {2, 3, 1}, {1, 3, 3}, {3, 4, 1}, {4, 5, 1}};
    std::cout << "Test case 1:" << std::endl;
    optimalSolution(n, graph);

    // Test case 2
    n = 4;
    graph = {{1, 2, 1}, {2, 3, 1}, {3, 4, 1}, {1, 4, 4}};
    std::cout << "Test case 2:" << std::endl;
    optimalSolution(n, graph);

    // Test case 3
    n = 3;
    graph = {{1, 2, 1}, {2, 3, 1}, {1, 3, 3}};
    std::cout << "Test case 3:" << std::endl;
    optimalSolution(n, graph);

    return 0;
}
```