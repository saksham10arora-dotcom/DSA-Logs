```cpp
// LeetCode problem 2909: Min Cost Climbing Optimized, https://leetcode.com/problems/min-cost-climbing/
// You are given an array of integers cost where cost[i] is the cost of ith step on a staircase.
// Once you pay the cost, you can either climb one or two steps.
// You can either start from the first step or the second step.
// Return the minimum cost to reach the top of the staircase.

// Brute force approach with O(2^n) complexity
// class Solution {
// public:
//     int minCostClimbing(int cost[], int n) {
//         return min(minCostClimbingHelper(cost, n, 0), minCostClimbingHelper(cost, n, 1));
//     }
// private:
//     int minCostClimbingHelper(int cost[], int n, int i) {
//         if (i >= n) return 0;
//         return cost[i] + min(minCostClimbingHelper(cost, n, i + 1), minCostClimbingHelper(cost, n, i + 2));
//     }
// };

// Optimal solution with O(n) complexity
class Solution {
public:
    int minCostClimbing(int cost[], int n) {
        int dp[n];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

int main() {
    Solution solution;
    int cost1[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int n1 = sizeof(cost1) / sizeof(cost1[0]);
    printf("Minimum cost to reach the top of the staircase: %d\n", solution.minCostClimbing(cost1, n1));

    int cost2[] = {10, 15, 20};
    int n2 = sizeof(cost2) / sizeof(cost2[0]);
    printf("Minimum cost to reach the top of the staircase: %d\n", solution.minCostClimbing(cost2, n2));

    int cost3[] = {1, 1, 1, 1, 1};
    int n3 = sizeof(cost3) / sizeof(cost3[0]);
    printf("Minimum cost to reach the top of the staircase: %d\n", solution.minCostClimbing(cost3, n3));

    return 0;
}
```