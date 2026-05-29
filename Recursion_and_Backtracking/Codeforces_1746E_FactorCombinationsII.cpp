```cpp
// Codeforces_1746E_FactorCombinationsII
// https://codeforces.com/contest/1746/problem/E
// Given a positive integer n, find all possible factor combinations of n.

#include <iostream>
#include <vector>

// Brute force approach with O(2^n) complexity
// void bruteForce(int n) {
//     for (int i = 1; i <= n; i++) {
//         if (n % i == 0) {
//             std::cout << i << " ";
//         }
//     }
// }

// Optimal solution with O(sqrt(n)) complexity
void factorCombinations(int n, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    if (n == 1) {
        result.push_back(current);
        return;
    }
    for (int i = start; i * i <= n; i++) {
        if (n % i == 0) {
            current.push_back(i);
            factorCombinations(n / i, i, current, result);
            current.pop_back();
        }
    }
}

int main() {
    int n;
    std::vector<std::vector<int>> result;
    std::vector<int> current;

    n = 12;
    result.clear();
    factorCombinations(n, 1, current, result);
    std::cout << "Factor combinations of " << n << ":" << std::endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    n = 24;
    result.clear();
    factorCombinations(n, 1, current, result);
    std::cout << "Factor combinations of " << n << ":" << std::endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    n = 36;
    result.clear();
    factorCombinations(n, 1, current, result);
    std::cout << "Factor combinations of " << n << ":" << std::endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```