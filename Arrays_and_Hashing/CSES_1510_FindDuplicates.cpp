```cpp
// Problem: Find Duplicates
// Link: https://cses.fi/problemset/task/1510
// Description: Given an array of n integers, find all duplicates in the array.

#include <iostream>
#include <vector>
#include <unordered_set>

// Brute force approach with O(n^2) complexity
std::vector<int> findDuplicatesBruteForce(const std::vector<int>& arr) {
    std::vector<int> duplicates;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] == arr[j] && std::find(duplicates.begin(), duplicates.end(), arr[i]) == duplicates.end()) {
                duplicates.push_back(arr[i]);
            }
        }
    }
    return duplicates;
}

// Optimal solution with O(n) complexity
std::vector<int> findDuplicatesOptimal(const std::vector<int>& arr) {
    std::vector<int> duplicates;
    std::unordered_set<int> seen;
    std::unordered_set<int> duplicateSet;
    for (int num : arr) {
        if (seen.find(num) != seen.end() && duplicateSet.find(num) == duplicateSet.end()) {
            duplicates.push_back(num);
            duplicateSet.insert(num);
        }
        seen.insert(num);
    }
    return duplicates;
}

int main() {
    std::vector<int> test1 = {1, 2, 3, 2, 4, 5, 6, 2, 3};
    std::vector<int> test2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> test3 = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    std::vector<int> result1 = findDuplicatesOptimal(test1);
    std::vector<int> result2 = findDuplicatesOptimal(test2);
    std::vector<int> result3 = findDuplicatesOptimal(test3);

    std::cout << "Test 1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Test 2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Test 3: ";
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```