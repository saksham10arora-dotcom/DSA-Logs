```cpp
// Create Sorted Array Optimized, https://cses.fi/problemset/task/1047
// Given an array of n distinct integers, create a sorted array with the minimum number of operations.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
long long bruteForce(std::vector<int>& operations) {
    std::vector<int> sortedArray;
    long long count = 0;
    for (int num : operations) {
        auto it = std::lower_bound(sortedArray.begin(), sortedArray.end(), num);
        count += it - sortedArray.begin() + 1;
        sortedArray.insert(it, num);
    }
    return count;
}

// Optimal solution with O(n log n) complexity using Binary Indexed Tree (BIT)
class BIT {
public:
    BIT(int size) : tree(size + 1, 0) {}

    void update(int index, int value) {
        while (index < tree.size()) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

private:
    std::vector<int> tree;
};

long long optimalSolution(std::vector<int>& operations) {
    std::vector<int> sortedOperations = operations;
    std::sort(sortedOperations.begin(), sortedOperations.end());
    std::vector<int> compressedOperations;
    for (int num : operations) {
        compressedOperations.push_back(std::lower_bound(sortedOperations.begin(), sortedOperations.end(), num) - sortedOperations.begin() + 1);
    }

    BIT bit(sortedOperations.size() + 1);
    long long count = 0;
    for (int num : compressedOperations) {
        count += bit.query(num - 1);
        bit.update(num, 1);
    }
    return count;
}

int main() {
    std::vector<int> operations1 = {5, 3, 1, 4, 2};
    std::vector<int> operations2 = {2, 1, 3};
    std::vector<int> operations3 = {1, 2, 3, 4, 5};

    std::cout << optimalSolution(operations1) << std::endl;  // Output: 7
    std::cout << optimalSolution(operations2) << std::endl;  // Output: 2
    std::cout << optimalSolution(operations3) << std::endl;  // Output:    return 0;
}
```