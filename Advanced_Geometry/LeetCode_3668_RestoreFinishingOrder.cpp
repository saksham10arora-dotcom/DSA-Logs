```cpp
// LeetCode problem 3668: Restore Finishing Order, https://leetcode.com/problems/restore-finishing-order/
// Given a list of tasks and their dependencies, restore the finishing order of the tasks.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

// Brute force approach with O(n!) complexity
// std::vector<int> restoreFinishingOrderBruteForce(std::vector<int>& tasks, std::vector<std::vector<int>>& dependencies) {
//     // Generate all permutations of tasks
//     // Check each permutation for validity
//     // Return the first valid permutation
// }

// Optimal solution with O(n + m) complexity
std::vector<int> restoreFinishingOrderOptimal(std::vector<int>& tasks, std::vector<std::vector<int>>& dependencies) {
    std::unordered_map<int, std::vector<int>> graph;
    std::unordered_map<int, int> inDegree;
    
    // Build the graph and calculate in-degrees
    for (int task : tasks) {
        inDegree[task] = 0;
    }
    for (std::vector<int>& dependency : dependencies) {
        int u = dependency[0];
        int v = dependency[1];
        graph[u].push_back(v);
        inDegree[v]++;
    }
    
    // Initialize the queue with tasks having in-degree 0
    std::queue<int> queue;
    for (int task : tasks) {
        if (inDegree[task] == 0) {
            queue.push(task);
        }
    }
    
    // Perform topological sorting
    std::vector<int> result;
    while (!queue.empty()) {
        int task = queue.front();
        queue.pop();
        result.push_back(task);
        
        for (int neighbor : graph[task]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                queue.push(neighbor);
            }
        }
    }
    
    // Check for cycles
    if (result.size() != tasks.size()) {
        return {};
    }
    
    return result;
}

int main() {
    // Test case 1
    std::vector<int> tasks1 = {1, 2, 3};
    std::vector<std::vector<int>> dependencies1 = {{1, 2}, {2, 3}};
    std::vector<int> result1 = restoreFinishingOrderOptimal(tasks1, dependencies1);
    for (int task : result1) {
        std::cout << task << " ";
    }
    std::cout << std::endl;
    
    // Test case 2
    std::vector<int> tasks2 = {1, 2, 3, 4};
    std::vector<std::vector<int>> dependencies2 = {{1, 2}, {2, 3}, {3, 4}};
    std::vector<int> result2 = restoreFinishingOrderOptimal(tasks2, dependencies2);
    for (int task : result2) {
        std::cout << task << " ";
    }
    std::cout << std::endl;
    
    // Test case 3
    std::vector<int> tasks3 = {1, 2, 3};
    std::vector<std::vector<int>> dependencies3 = {{1, 2}, {2, 3}, {3, 1}};
    std::vector<int> result3 = restoreFinishingOrderOptimal(tasks3, dependencies3);
    for (int task : result3) {
        std::cout << task << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```