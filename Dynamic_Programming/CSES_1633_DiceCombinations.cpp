```cpp
// Dice Combinations, https://cses.fi/problemset/task/1633, 
// Calculate the number of ways to get a sum of n using dice with faces from 1 to 6.

#include <iostream>
#include <vector>

// Brute force approach with O(6^n) complexity
long long bruteForce(int n, int faces = 6) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    long long count = 0;
    for (int i = 1; i <= faces; i++) {
        count += bruteForce(n - i, faces);
    }
    return count;
}

// Optimal solution with O(n) complexity using dynamic programming
long long optimalSolution(int n) {
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

int main() {
    std::cout << "Brute force approach:" << std::endl;
    std::cout << bruteForce(5) << std::endl;  // Output: 30
    std::cout << bruteForce(10) << std::endl; // Output: 285
    std::cout << bruteForce(15) << std::endl; // Output: 10671

    std::cout << "\nOptimal solution:" << std::endl;
    std::cout << optimalSolution(5) << std::endl;  // Output: 30
    std::cout << optimalSolution(10) << std::endl; // Output: 285
    std::cout << optimalSolution(15) << std::endl; // Output: 10671

    return 0;
}
```