/**
 * Problem: Coin Change (LeetCode 322)
 * Link: https://leetcode.com/problems/coin-change/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Tabulation) ---
// Time Complexity: O(N * Amount)
// Space Complexity: O(Amount)
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    return (dp[amount] > amount) ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Min Coins: " << coinChange(coins, amount) << endl;
    return 0;
}



































