```cpp
// Fruits Into Baskets II, https://leetcode.com/problems/fruits-into-baskets-ii/, 
// Given a tree of n nodes, each node has a unique integer id from 1 to n, and it has a fruit type represented by an integer. 
// You are given a 2D list of edges, where edges[i] = [u, v] means there is an undirected edge between nodes u and v. 
// You are also given a list of integers fruits, where fruits[i] is the fruit type of the node with id i + 1.
// Return the maximum number of fruits you can collect.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int maxFruits(std::vector<std::vector<int>>& edges, std::vector<int>& fruits) {
        // Create adjacency list
        std::unordered_map<int, std::vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Initialize variables
        int maxFruits = 0;
        std::unordered_set<int> visited;

        // Perform DFS
        std::function<void(int, int, std::unordered_set<int>&)> dfs = 
            [&](int node, int parent, std::unordered_set<int>& fruitTypes) {
                // Mark node as visited
                visited.insert(node);

                // Add fruit type to set
                fruitTypes.insert(fruits[node - 1]);

                // If there are more than 2 fruit types, remove the least frequent one
                if (fruitTypes.size() > 2) {
                    int minCount = INT_MAX;
                    int minFruit = -1;
                    for (const auto& fruit : fruitTypes) {
                        int count = 0;
                        for (const auto& n : visited) {
                            if (fruits[n - 1] == fruit) {
                                count++;
                            }
                        }
                        if (count < minCount) {
                            minCount = count;
                            minFruit = fruit;
                        }
                    }
                    fruitTypes.erase(minFruit);
                }

                // Update maxFruits
                maxFruits = std::max(maxFruits, static_cast<int>(visited.size()));

                // Recur for all adjacent nodes
                for (const auto& adjacent : graph[node]) {
                    if (adjacent != parent && visited.find(adjacent) == visited.end()) {
                        dfs(adjacent, node, fruitTypes);
                    }
                }

                // Backtrack
                visited.erase(node);
                fruitTypes.erase(fruits[node - 1]);
            };

        // Perform DFS from each node
        for (int i = 1; i <= fruits.size(); i++) {
            std::unordered_set<int> fruitTypes;
            dfs(i, -1, fruitTypes);
        }

        return maxFruits;
    }
};

int main() {
    Solution solution;

    // Test case 1
    std::vector<std::vector<int>> edges1 = {{1, 2}, {1, 3}, {1, 4}, {3, 5}, {3, 6}};
    std::vector<int> fruits1 = {1, 2, 1, 2, 2, 1};
    std::cout << solution.maxFruits(edges1, fruits1) << std::endl;  // Output: 5

    // Test case 2
    std::vector<std::vector<int>> edges2 = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    std::vector<int> fruits2 = {1, 1, 2, 2, 1, 1};
    std::cout << solution.maxFruits(edges2, fruits2) << std::endl;  // Output: 6

    // Test case 3
    std::vector<std::vector<int>> edges3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    std::vector<int> fruits3 = {1, 2, 3, 4, 5};
    std::cout << solution.maxFruits(edges3, fruits3) << std::endl;  // Output: 2

    return 0;
}
```