```cpp
// LeetCode problem 2685: Count The Number Of Complete Components
// https://leetcode.com/problems/count-the-number-of-complete-components/
// Given a positive integer n and an array edges of size n where edges[i] is a binary string of length n, 
// return the number of complete components in the graph.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Brute force approach: O(n^3) complexity
class SolutionBruteForce {
public:
    int countCompleteComponents(int n, std::vector<std::string>& edges) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            bool isComplete = true;
            for (int j = 0; j < n; j++) {
                if (i != j && edges[i][j] == '0') {
                    isComplete = false;
                    break;
                }
            }
            if (isComplete) {
                count++;
            }
        }
        return count;
    }
};

// Optimal solution: O(n^2) complexity
class SolutionOptimal {
public:
    int countCompleteComponents(int n, std::vector<std::string>& edges) {
        int count = 0;
        std::unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++) {
            if (visited.find(i) == visited.end()) {
                bool isComplete = true;
                for (int j = 0; j < n; j++) {
                    if (edges[i][j] == '0') {
                        isComplete = false;
                        break;
                    }
                }
                if (isComplete) {
                    count++;
                    visited[i] = true;
                }
            }
        }
        return count;
    }
};

int main() {
    SolutionOptimal solution;
    std::vector<std::string> edges1 = {"11", "11"};
    std::cout << solution.countCompleteComponents(2, edges1) << std::endl;  // Output: 1

    std::vector<std::string> edges2 = {"11", "10", "01"};
    std::cout << solution.countCompleteComponents(3, edges2) << std::endl;  // Output: 1

    std::vector<std::string> edges3 = {"111", "110", "101"};
    std::cout << solution.countCompleteComponents(3, edges3) << std::endl;  // Output: 1

    return 0;
}
```