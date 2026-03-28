```cpp
// LeetCode problem 322: Coin Change
// https://leetcode.com/problems/coin-change/
// Given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money,
// return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

#include <vector>
#include <climits>
#include <iostream>

// Brute force approach with O(2^n) complexity
class Solution_Brute_Force {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        return helper(coins, amount, 0);
    }
    
    int helper(std::vector<int>& coins, int amount, int index) {
        if (amount == 0) return 0;
        if (amount < 0 || index >= coins.size()) return -1;
        
        int take = helper(coins, amount - coins[index], index);
        int notTake = helper(coins, amount, index + 1);
        
        if (take == -1 && notTake == -1) return -1;
        if (take == -1) return notTake;
        if (notTake == -1) return take + 1;
        
        return std::min(take + 1, notTake);
    }
};

// Optimal solution with O(n*m) complexity
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution solution;
    
    std::vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    std::cout << "Minimum coins needed: " << solution.coinChange(coins1, amount1) << std::endl;
    
    std::vector<int> coins2 = {2};
    int amount2 = 3;
    std::cout << "Minimum coins needed: " << solution.coinChange(coins2, amount2) << std::endl;
    
    std::vector<int> coins3 = {1};
    int amount3 = 0;
    std::cout << "Minimum coins needed: " << solution.coinChange(coins3, amount3) << std::endl;
    
    return 0;
}
```