```cpp
// Codeforces_689D_LevelOrderBottom
// https://codeforces.com/contest/689/problem/D
// Given a tree, print the nodes in level order from bottom to top.

#include <iostream>
#include <vector>
#include <queue>

// Brute force approach: Perform DFS and store the nodes at each level, then print from bottom to top. O(n^2) complexity due to vector insertion.
// However, we can optimize this by using a queue for BFS and storing the nodes at each level.

// Optimal solution: Use BFS to traverse the tree level by level from top to bottom, storing the nodes at each level. Then print the nodes from bottom to top. O(n) complexity.

void levelOrderBottom(std::vector<std::vector<int>>& tree, int root) {
    if (tree.empty() || root < 0 || root >= tree.size()) {
        return;
    }

    std::vector<std::vector<int>> levels;
    std::queue<int> queue;
    queue.push(root);
    while (!queue.empty()) {
        int size = queue.size();
        std::vector<int> level;
        for (int i = 0; i < size; i++) {
            int node = queue.front();
            queue.pop();
            level.push_back(node);
            for (int child : tree[node]) {
                queue.push(child);
            }
        }
        levels.push_back(level);
    }

    // Print levels from bottom to top
    for (int i = levels.size() - 1; i >= 0; i--) {
        for (int node : levels[i]) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Test case 1:
    std::vector<std::vector<int>> tree1 = {{1, 2}, {3}, {3}, {}};
    levelOrderBottom(tree1, 0);

    // Test case 2:
    std::vector<std::vector<int>> tree2 = {{1, 2, 3}, {4}, {5}, {6}, {}, {}, {}};
    levelOrderBottom(tree2, 0);

    // Test case 3:
    std::vector<std::vector<int>> tree3 = {{1}, {2}, {}};
    levelOrderBottom(tree3, 0);

    return 0;
}
```