```cpp
// Codeforces_511D_ConstructTreeAdvanced
// https://codeforces.com/contest/511/problem/D
// Construct a tree with given degrees of vertices.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Brute force approach with O(n!) complexity
// This approach is not efficient and will not be used.

// Optimal solution with O(n log n) complexity
// We use a priority queue to store the degrees of vertices.
// We always connect the two vertices with the highest degrees.

std::vector<std::vector<int>> constructTree(std::vector<int>& degrees) {
    int n = degrees.size();
    std::vector<std::vector<int>> tree(n);
    std::priority_queue<std::pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({degrees[i], i});
    }
    while (pq.size() > 1) {
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();
        tree[a.second].push_back(b.second);
        tree[b.second].push_back(a.second);
        a.first--;
        b.first--;
        if (a.first > 0) {
            pq.push(a);
        }
        if (b.first > 0) {
            pq.push(b);
        }
    }
    return tree;
}

void printTree(const std::vector<std::vector<int>>& tree) {
    for (const auto& neighbors : tree) {
        std::cout << neighbors.size() << " ";
        for (int neighbor : neighbors) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> degrees1 = {2, 2, 1, 1};
    std::vector<std::vector<int>> tree1 = constructTree(degrees1);
    printTree(tree1);

    std::vector<int> degrees2 = {3, 2, 2, 1};
    std::vector<std::vector<int>> tree2 = constructTree(degrees2);
    printTree(tree2);

    std::vector<int> degrees3 = {4, 3, 2, 1, 1};
    std::vector<std::vector<int>> tree3 = constructTree(degrees3);
    printTree(tree3);

    return 0;
}
```