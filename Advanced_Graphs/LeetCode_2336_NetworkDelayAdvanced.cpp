```cpp
// Network Delay Advanced, https://leetcode.com/problems/network-delay-time/, 
// Given an array of time intervals and a start node, return the minimum time it takes for all nodes to receive the signal.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Brute force approach: O(n^2 * m) where n is the number of nodes and m is the number of edges
class Solution_BruteForce {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
        for (auto& time : times) {
            graph[time[0]][time[1]] = time[2];
        }
        for (int i = 1; i <= n; i++) {
            graph[i][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int u = 1; u <= n; u++) {
                    graph[j][u] = min(graph[j][u], graph[j][i] + graph[i][u]);
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (graph[k][i] == INT_MAX) {
                return -1;
            }
            maxTime = max(maxTime, graph[k][i]);
        }
        return maxTime;
    }
};

// Optimal solution: O((n + m) * log(n)) where n is the number of nodes and m is the number of edges
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) {
                continue;
            }
            for (auto& [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << solution.networkDelayTime(times1, 4, 2) << endl;  // Output: 2
    vector<vector<int>> times2 = {{1, 2, 1}};
    cout << solution.networkDelayTime(times2, 2, 1) << endl;  // Output: 1
    vector<vector<int>> times3 = {{1, 2, 1}, {2, 3, 2}, {1, 3, 2}};
    cout << solution.networkDelayTime(times3, 3, 1) << endl;  // Output: 2
    return 0;
}
```