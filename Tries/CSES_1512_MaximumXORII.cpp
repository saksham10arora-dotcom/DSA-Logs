```cpp
// Maximum X O R I I, https://cses.fi/problemset/task/1512
// Given an array of n integers and an integer x, find the maximum value of a ^ x for all a in the array.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n * 2^31) complexity
int bruteForce(const std::vector<int>& a, int x) {
    int max = 0;
    for (int i = 0; i < a.size(); i++) {
        max = std::max(max, a[i] ^ x);
    }
    return max;
}

// Optimal solution with O(n * 31) complexity
class Trie {
public:
    Trie() : root(new Node()) {}

    void insert(int x) {
        Node* node = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new Node();
            }
            node = node->children[bit];
        }
    }

    int query(int x) {
        Node* node = root;
        int result = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (node->children[1 - bit]) {
                result |= (1 << i);
                node = node->children[1 - bit];
            } else {
                node = node->children[bit];
            }
        }
        return result;
    }

private:
    struct Node {
        Node* children[2] = {nullptr, nullptr};
    };

    Node* root;
};

int optimalSolution(const std::vector<int>& a, int x) {
    Trie trie;
    for (int i = 0; i < a.size(); i++) {
        trie.insert(a[i]);
    }
    return trie.query(x);
}

int main() {
    std::vector<int> a1 = {3, 7, 5};
    std::cout << optimalSolution(a1, 2) << std::endl; // 6

    std::vector<int> a2 = {4, 8, 12, 16};
    std::cout << optimalSolution(a2, 5) << std::endl; // 7

    std::vector<int> a3 = {1, 2, 3, 4, 5};
    std::cout << optimalSolution(a3, 6) << std::endl; // 7

    return 0;
}
```