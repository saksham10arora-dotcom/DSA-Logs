```cpp
// LeetCode problem 2662: Minimum Cost Of A Path With Special Roads
// https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/
// Given a start and end point, find the minimum cost of a path with special roads.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Brute force approach: Try all possible paths and calculate the cost of each path
// O(2^n) complexity, where n is the number of special roads
// int minCost(vector<vector<int>>& start, vector<vector<int>>& end, vector<vector<int>>& specialRoads) {
//     // ...
// }

// Optimal solution: Use Dijkstra's algorithm to find the shortest path
// O(n log n + m log n) complexity, where n is the number of nodes and m is the number of edges
int minCost(vector<vector<int>>& start, vector<vector<int>>& end, vector<vector<int>>& specialRoads) {
    int n = specialRoads.size() + 2;
    vector<vector<pair<int, int>>> graph(n);
    graph[0] = { {start[0][0], start[0][1]} };
    graph[n-1] = { {end[0][0], end[0][1]} };
    for (int i = 0; i < specialRoads.size(); i++) {
        graph[i+1] = { {specialRoads[i][0], specialRoads[i][1]} };
    }
    for (int i = 0; i < specialRoads.size(); i++) {
        graph[0].push_back({specialRoads[i][0], specialRoads[i][2]});
        graph[specialRoads[i][0]].push_back({0, specialRoads[i][2]});
        graph[specialRoads[i][1]].push_back({n-1, specialRoads[i][2]});
        graph[n-1].push_back({specialRoads[i][1], specialRoads[i][2]});
    }
    vector<int> dist(n, numeric_limits<int>::max());
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& v : graph[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    return dist[n-1];
}

int main() {
    vector<vector<int>> start = {{1, 1}};
    vector<vector<int>> end = {{4, 5}};
    vector<vector<int>> specialRoads = {{1, 4, 5}, {1, 3, 4}, {3, 4, 2}};
    cout << minCost(start, end, specialRoads) << endl;  // Output: 5

    start = {{3, 2}};
    end = {{4, 4}};
    specialRoads = {{1, 2, 3}, {3, 4, 4}};
    cout << minCost(start, end, specialRoads) << endl;  // Output: 5

    start = {{3, 1}};
    end = {{3, 4}};
    specialRoads = {{2, 3, 2}};
    cout << minCost(start, end, specialRoads) << endl;  // Output: 3

    return 0;
}
```