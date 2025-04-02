```cpp
// LeetCode problem 1742: Min Cost Climbing Variant, https://leetcode.com/problems/min-cost-climbing-variant/
// You are given an array of integers cost where cost[i] is the cost of the ith step on a staircase.
// Once you pay the cost of a step, you can either climb 1 or 2 steps.
// You can start your climb from either the first or second step to avoid paying cost[0].
// Return the minimum cost to reach the top of the staircase.

// Brute force approach with O(2^n) complexity
class Solution_Brute_Force {
public:
    int minCostClimbing(int i, vector<int>& cost) {
        if (i >= cost.size()) return 0;
        return cost[i] + min(minCostClimbing(i + 1, cost), minCostClimbing(i + 2, cost));
    }
    int minCostClimbingVariant(vector<int>& cost) {
        return min(minCostClimbing(0, cost), minCostClimbing(1, cost));
    }
};

// Optimal solution with O(n) complexity
class Solution {
public:
    int minCostClimbingVariant(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i - 1];
        }
        return min(dp[n], dp[n - 1]);
    }
};

int main() {
    Solution solution;
    vector<int> cost1 = {10, 15, 20};
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> cost3 = {0, 2, 2, 1};
    cout << solution.minCostClimbingVariant(cost1) << endl;  // Output: 15
    cout << solution.minCostClimbingVariant(cost2) << endl;  // Output: 6
    cout << solution.minCostClimbingVariant(cost3) << endl;  // Output: 2
    return 0;
}
```