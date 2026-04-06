/**
 * Problem: Best Time to Buy and Sell Stock (LeetCode 121)
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Sliding Window / Kadane's Idea) ---
// Time Complexity: O(N)
// Space Complexity: O(1)
int maxProfit(vector<int>& prices) {
    int minPrice = 1e9;
    int maxP = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxP = max(maxP, price - minPrice);
    }
    return maxP;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
    return 0;
}
















































