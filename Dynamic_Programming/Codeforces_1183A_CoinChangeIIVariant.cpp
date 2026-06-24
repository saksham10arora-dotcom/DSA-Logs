```cpp
// Codeforces_1183A_CoinChangeIIVariant
// https://codeforces.com/contest/1183/problem/A
// This problem is a variant of the classic coin change problem, where we need to find the number of ways to make change for a given amount using a set of coins.

#include <iostream>
#include <vector>

// Brute force approach: Try all possible combinations of coins to make the change
// Time complexity: O(2^n), where n is the number of coins
// Space complexity: O(n), for the recursive call stack
int bruteForce(int amount, const std::vector<int>& coins, int index) {
    if (amount == 0) return 1;
    if (amount < 0 || index == coins.size()) return 0;
    return bruteForce(amount - coins[index], coins, index) + bruteForce(amount, coins, index + 1);
}

// Optimal solution: Use dynamic programming to store the number of ways to make change for each amount
// Time complexity: O(n*m), where n is the number of coins and m is the amount
// Space complexity: O(m), for the dp array
int optimalSolution(int amount, const std::vector<int>& coins) {
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

int main() {
    std::vector<int> coins1 = {1, 2, 3};
    std::cout << "Test case 1: " << optimalSolution(4, coins1) << std::endl;  // Output: 4

    std::vector<int> coins2 = {2, 3, 5};
    std::cout << "Test case 2: " << optimalSolution(10, coins2) << std::endl;  // Output: 4

    std::vector<int> coins3 = {1, 2, 5};
    std::cout << "Test case 3: " << optimalSolution(5, coins3) << std::endl;  // Output: 4

    return 0;
}
```