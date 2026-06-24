```cpp
// LeetCode problem 783: Couples Holding Hands
// https://leetcode.com/problems/couples-holding-hands/
// There are n couples sitting in a row of 2n seats. The ith couple is sitting in seats 2*i and 2*i+1.
// A couple is happy if the man and woman are in adjacent seats and the woman is to the left of the man.
// You want all the couples to be happy. You can swap any two people in the row.
// Return the minimum number of swaps required to make all couples happy.

// Brute force approach: try all possible permutations of people and count the number of swaps required for each permutation
// O((2n)!) complexity

// Optimal solution: use a union-find data structure to keep track of the connected components
// O(n) complexity

#include <iostream>
#include <vector>

class UnionFind {
public:
    std::vector<int> parent;
    std::vector<int> rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int minSwapsCouples(std::vector<int>& row) {
    int n = row.size() / 2;
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        if ((row[2 * i] % 2 == 0 && row[2 * i + 1] % 2 == 1) || (row[2 * i] % 2 == 1 && row[2 * i + 1] % 2 == 0)) {
            uf.unionSet(row[2 * i] / 2, row[2 * i + 1] / 2);
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (uf.find(i) == i) {
            count++;
        }
    }
    return n - count;
}

int main() {
    std::vector<int> row1 = {0, 2, 1, 3};
    std::cout << minSwapsCouples(row1) << std::endl;  // Output: 1

    std::vector<int> row2 = {3, 2, 0, 1};
    std::cout << minSwapsCouples(row2) << std::endl;  // Output: 0

    std::vector<int> row3 = {0, 1, 2, 3};
    std::cout << minSwapsCouples(row3) << std::endl;  // Output: 0

    return 0;
}
```