```cpp
// Problem: Merge Sorted I I, https://cses.fi/problemset/task/1432, Given two sorted lists, merge them into one sorted list.

// Brute force approach: sorting the combined list (O(n log n))
// However, we can do better by utilizing the fact that the input lists are already sorted.

// Optimal solution: using two pointers to compare elements from both lists (O(n + m))
#include <iostream>
#include <vector>

std::vector<int> merge_sorted_lists(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }

    return result;
}

int main() {
    std::vector<int> a1 = {1, 5, 10};
    std::vector<int> b1 = {2, 6, 11};
    std::vector<int> result1 = merge_sorted_lists(a1, b1);
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> a2 = {1, 3, 5};
    std::vector<int> b2 = {2, 4, 6};
    std::vector<int> result2 = merge_sorted_lists(a2, b2);
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> a3 = {1, 2, 3};
    std::vector<int> b3 = {4, 5, 6};
    std::vector<int> result3 = merge_sorted_lists(a3, b3);
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```