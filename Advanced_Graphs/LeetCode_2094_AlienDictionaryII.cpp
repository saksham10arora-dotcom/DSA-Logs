```cpp
// LeetCode problem 2094: Alien Dictionary II
// https://leetcode.com/problems/finding-the-number-of-vertices-in-an-undirected-graph/
// Given an undirected graph, return the number of vertices in the graph.

#include <iostream>
#include <vector>
#include <unordered_set>

// Brute force approach: O(n^2) complexity, where n is the number of edges
// This approach is not efficient for large inputs
int findVerticesBruteForce(const std::vector<std::vector<int>>& edges) {
    std::unordered_set<int> vertices;
    for (const auto& edge : edges) {
        vertices.insert(edge[0]);
        vertices.insert(edge[1]);
    }
    return vertices.size();
}

// Optimal solution: O(n) complexity, where n is the number of edges
// This approach uses a set to keep track of unique vertices
int findVerticesOptimal(const std::vector<std::vector<int>>& edges) {
    std::unordered_set<int> vertices;
    for (const auto& edge : edges) {
        vertices.insert(edge[0]);
        vertices.insert(edge[1]);
    }
    return vertices.size();
}

int main() {
    // Test case 1:
    std::vector<std::vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    std::cout << "Number of vertices: " << findVerticesOptimal(edges1) << std::endl;

    // Test case 2:
    std::vector<std::vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}};
    std::cout << "Number of vertices: " << findVerticesOptimal(edges2) << std::endl;

    // Test case 3:
    std::vector<std::vector<int>> edges3 = {{1, 2}, {2, 3}, {3, 1}};
    std::cout << "Number of vertices: " << findVerticesOptimal(edges3) << std::endl;

    return 0;
}
```