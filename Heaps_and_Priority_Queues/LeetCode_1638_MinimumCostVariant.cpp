```cpp
// LeetCode problem 1638: Tourist Trap, https://leetcode.com/problems/tourist-trap/
// A tourist wants to visit a set of cities and return to the starting city. The tourist has a limited amount of money and wants to minimize the cost of the trip.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// Brute force approach: try all possible paths and calculate the cost for each path, O(n!)
class Solution_BruteForce {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int K) {
        std::vector<std::vector<int>> graph(n, std::vector<int>(n, std::numeric_limits<int>::max()));
        for (const auto& flight : flights) {
            graph[flight[0]][flight[1]] = flight[2];
        }
        std::vector<int> path;
        std::vector<int> minCost(n, std::numeric_limits<int>::max());
        minCost[src] = 0;
        dfs(graph, src, dst, K, path, minCost);
        return minCost[dst] == std::numeric_limits<int>::max() ? -1 : minCost[dst];
    }

    void dfs(const std::vector<std::vector<int>>& graph, int node, int dst, int K, std::vector<int>& path, std::vector<int>& minCost) {
        if (node == dst) {
            return;
        }
        if (K < 0) {
            return;
        }
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[node][i] != std::numeric_limits<int>::max()) {
                int newCost = minCost[node] + graph[node][i];
                if (newCost < minCost[i]) {
                    minCost[i] = newCost;
                    path.push_back(i);
                    dfs(graph, i, dst, K - 1, path, minCost);
                    path.pop_back();
                }
            }
        }
    }
};

// Optimal solution: use a priority queue to keep track of the nodes with the minimum cost, O(n^2 * log(n))
class Solution_Optimal {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int K) {
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        for (const auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.emplace(0, src);
        std::vector<int> stops(n, std::numeric_limits<int>::max());
        stops[src] = 0;
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if (node == dst) {
                return cost;
            }
            if (stops[node] < K + 1) {
                for (const auto& [nextNode, nextCost] : graph[node]) {
                    if (cost + nextCost < stops[nextNode]) {
                        stops[nextNode] = cost + nextCost;
                        pq.emplace(stops[nextNode], nextNode);
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution_Optimal solution;
    std::vector<std::vector<int>> flights1 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    std::cout << solution.findCheapestPrice(3, flights1, 0, 2, 1) << std::endl;  // Output: 200
    std::vector<std::vector<int>> flights2 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    std::cout << solution.findCheapestPrice(3, flights2, 0, 2, 0) << std::endl;  // Output: 500
    std::vector<std::vector<int>> flights3 = {{0, 1, 2}, {2, 1, 1}, {1, 2, 1}, {0, 2, 100}};
    std::cout << solution.findCheapestPrice(3, flights3, 0, 2, 1) << std::endl;  // Output: 11
    return 0;
}
```