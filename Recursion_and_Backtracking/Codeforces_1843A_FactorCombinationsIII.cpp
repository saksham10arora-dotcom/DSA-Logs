```cpp
// Codeforces_1843A_FactorCombinationsIII
// https://codeforces.com/contest/1843/problem/A
// Find all factor combinations of a given number.

#include <iostream>
#include <vector>

// Brute force approach: O(2^n) - generate all subsets of numbers from 1 to n
void bruteForce(int n, int current, std::vector<int>& currentCombination, std::vector<std::vector<int>>& combinations) {
    if (current > n) {
        int product = 1;
        for (int num : currentCombination) {
            product *= num;
        }
        if (product == n) {
            combinations.push_back(currentCombination);
        }
        return;
    }

    // include current number
    currentCombination.push_back(current);
    bruteForce(n, current + 1, currentCombination, combinations);
    currentCombination.pop_back();

    // exclude current number
    bruteForce(n, current + 1, currentCombination, combinations);
}

// Optimal solution: O(sqrt(n)) - only consider factors up to sqrt(n)
void optimalSolution(int n, int current, std::vector<int>& currentCombination, std::vector<std::vector<int>>& combinations) {
    if (current > n) {
        if (currentCombination.size() > 0) {
            combinations.push_back(currentCombination);
        }
        return;
    }

    if (n % current == 0) {
        // include current number
        currentCombination.push_back(current);
        optimalSolution(n, current, currentCombination, combinations);
        currentCombination.pop_back();
    }

    optimalSolution(n, current + 1, currentCombination, combinations);
}

int main() {
    int n1 = 12;
    std::vector<std::vector<int>> combinations1;
    std::vector<int> currentCombination1;
    optimalSolution(n1, 2, currentCombination1, combinations1);
    std::cout << "Combinations for " << n1 << ": ";
    for (const auto& combination : combinations1) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    int n2 = 24;
    std::vector<std::vector<int>> combinations2;
    std::vector<int> currentCombination2;
    optimalSolution(n2, 2, currentCombination2, combinations2);
    std::cout << "Combinations for " << n2 << ": ";
    for (const auto& combination : combinations2) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    int n3 = 36;
    std::vector<std::vector<int>> combinations3;
    std::vector<int> currentCombination3;
    optimalSolution(n3, 2, currentCombination3, combinations3);
    std::cout << "Combinations for " << n3 << ": ";
    for (const auto& combination : combinations3) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```