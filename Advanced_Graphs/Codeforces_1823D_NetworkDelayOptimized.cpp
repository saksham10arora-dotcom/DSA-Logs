```cpp
// Codeforces_1823D_NetworkDelayOptimized, https://codeforces.com/contest/1823/problem/D, 
// Given a directed graph with n nodes and m edges, find the minimum time to send a signal from node 1 to all other nodes.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// Brute force approach: O(n * m) complexity, not efficient for large inputs
// int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
//     std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, INT_MAX));
//     for (int i = 1; i <= n; i++) {
//         graph[i][i] = 0;
//     }
//     for (const auto& time : times) {
//         graph[time[0]][time[1]] = time[2];
//     }
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             for (int l = 1; l <= n; l++) {
//                 graph[j][l] = std::min(graph[j][l], graph[j][i] + graph[i][l]);
//             }
//         }
//     }
//     int maxTime = 0;
//     for (int i = 1; i <= n; i++) {
//         if (graph[k][i] == INT_MAX) {
//             return -1;
//         }
//         maxTime = std::max(maxTime, graph[k][i]);
//     }
//     return maxTime;
// }

// Optimal solution: O(m + n log n) complexity using Dijkstra's algorithm
int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
    std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
    for (const auto& time : times) {
        graph[time[0]].emplace_back(time[1], time[2]);
    }
    std::vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.emplace(0, k);
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            return -1;
        }
        maxTime = std::max(maxTime, dist[i]);
    }
    return maxTime;
}

int main() {
    std::vector<std::vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    std::cout << networkDelayTime(times1, 4, 2) << std::endl;  // Output: 2

    std::vector<std::vector<int>> times2 = {{1, 2, 1}};
    std::cout << networkDelayTime(times2, 2, 1) << std::endl;  // Output: 1

    std::vector<std::vector<int>> times3 = {{1, 2, 1}, {2, 3, 2}, {1, 3, 2}};
    std::cout << networkDelayTime(times3, 3, 1) << std::endl;  // Output: 2

    return 0;
}
```