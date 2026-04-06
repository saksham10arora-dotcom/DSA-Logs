```cpp
// Best Time to Buy and Sell Stock, https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Given an array of integers representing the daily stock prices, find the maximum possible profit.

class Solution {
public:
    // Brute force approach: O(n^2) complexity
    int maxProfitBruteForce(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxProfit;
    }

    // Optimal solution: O(n) complexity
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

int main() {
    Solution solution;
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};
    vector<int> prices3 = {2, 4, 1};

    cout << "Max Profit 1: " << solution.maxProfit(prices1) << endl;  // Output: 5
    cout << "Max Profit 2: " << solution.maxProfit(prices2) << endl;  // Output: 0
    cout << "Max Profit 3: " << solution.maxProfit(prices3) << endl;  // Output: 2

    return 0;
}
```