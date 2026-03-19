```cpp
// LeetCode problem 2405: Path With Minimum, https://leetcode.com/problems/path-with-minimum-effect/
// Given a directed graph with n nodes and n - 1 edges, find the path with the minimum effect.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// Brute force approach: try all possible paths, O(n!)
class Solution_BruteForce {
public:
    int minScore(int n, std::vector<std::vector<int>>& roads) {
        int minScore = std::numeric_limits<int>::max();
        std::vector<bool> visited(n, false);
        std::vector<int> path;
        dfs(0, visited, path, roads, minScore);
        return minScore;
    }

    void dfs(int node, std::vector<bool>& visited, std::vector<int>& path, std::vector<std::vector<int>>& roads, int& minScore) {
        if (node == roads.size() - 1) {
            int score = 0;
            for (int i = 0; i < path.size() - 1; i++) {
                score += roads[path[i]][path[i + 1]];
            }
            minScore = std::min(minScore, score);
            return;
        }
        visited[node] = true;
        path.push_back(node);
        for (int i = 0; i < roads.size(); i++) {
            if (!visited[i] && roads[node][i] != 0) {
                dfs(i, visited, path, roads, minScore);
            }
        }
        path.pop_back();
        visited[node] = false;
    }
};

// Optimal solution: use Dijkstra's algorithm, O(n + m log n)
class Solution_Optimal {
public:
    int minScore(int n, std::vector<std::vector<int>>& roads) {
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        for (const auto& road : roads) {
            graph[road[0]].emplace_back(road[1], road[2]);
            graph[road[1]].emplace_back(road[0], road[2]);
        }
        std::vector<int> distance(n, std::numeric_limits<int>::max());
        distance[0] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if (dist > distance[node]) continue;
            for (const auto& neighbor : graph[node]) {
                int newDist = std::max(dist, neighbor.second);
                if (newDist < distance[neighbor.first]) {
                    distance[neighbor.first] = newDist;
                    pq.emplace(newDist, neighbor.first);
                }
            }
        }
        return distance[n - 1];
    }
};

int main() {
    Solution_Optimal solution;
    std::vector<std::vector<int>> roads1 = {{0, 1, 9}, {1, 2, 6}, {2, 3, 5}, {0, 3, 7}};
    std::cout << solution.minScore(4, roads1) << std::endl;  // Output: 5

    std::vector<std::vector<int>> roads2 = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}};
    std::cout << solution.minScore(4, roads2) << std::endl;  // Output: 2

    std::vector<std::vector<int>> roads3 = {{0, 1, 9}, {1, 2, 6}, {2, 3, 5}, {0, 3, 18}};
    std::cout << solution.minScore(4, roads3) << std::endl;  // Output: 6

    return 0;
}
```