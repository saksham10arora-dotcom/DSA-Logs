```cpp
// Problem: Level Order Traversal (Bottom Optimized)
// Link: https://cses.fi/problemset/task/1195
// Description: Given a tree, print the nodes in level order from bottom to top.

#include <iostream>
#include <vector>
#include <queue>

// Brute force approach: O(n^2) due to recursive calls and vector operations
// class Solution {
// public:
//     std::vector<std::vector<int>> levelOrderBottom(std::vector<std::vector<int>>& tree) {
//         std::vector<std::vector<int>> result;
//         std::function<void(int, std::vector<int>&)> dfs = 
//             [&](int node, std::vector<int>& path) {
//                 if (node == -1) return;
//                 path.push_back(node);
//                 if (tree[node].empty()) {
//                     result.push_back(path);
//                     path.clear();
//                 } else {
//                     for (int child : tree[node]) {
//                         dfs(child, path);
//                     }
//                 }
//             };
//         dfs(0, {});
//         std::reverse(result.begin(), result.end());
//         return result;
//     }
// };

// Optimal solution: O(n) using BFS
class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(std::vector<std::vector<int>>& tree) {
        std::vector<std::vector<int>> result;
        if (tree.empty()) return result;
        std::queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int size = q.size();
            std::vector<int> level;
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                level.push_back(node);
                for (int child : tree[node]) {
                    q.push(child);
                }
            }
            result.push_back(level);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> tree1 = {{1, 2}, {3, 4}, {5, 6}, {}, {}, {}, {}};
    std::vector<std::vector<int>> result1 = solution.levelOrderBottom(tree1);
    for (const auto& level : result1) {
        for (int node : level) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> tree2 = {{1}, {2}, {}};
    std::vector<std::vector<int>> result2 = solution.levelOrderBottom(tree2);
    for (const auto& level : result2) {
        for (int node : level) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> tree3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {}, {}, {}, {}, {}, {}};
    std::vector<std::vector<int>> result3 = solution.levelOrderBottom(tree3);
    for (const auto& level : result3) {
        for (int node : level) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```