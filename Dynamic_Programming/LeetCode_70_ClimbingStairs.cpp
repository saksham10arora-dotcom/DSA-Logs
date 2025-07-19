```cpp
// LeetCode Problem: Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/
// You are climbing a staircase. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top of a staircase with n steps?

// Brute force approach with O(2^n) complexity
class Solution_Brute_Force {
public:
    int climbStairs(int n) {
        return climb(n);
    }
    
    int climb(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        return climb(n - 1) + climb(n - 2);
    }
};

// Optimal solution with O(n) complexity
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    // Test case 1
    int n1 = 2;
    int result1 = solution.climbStairs(n1);
    // Test case 2
    int n2 = 3;
    int result2 = solution.climbStairs(n2);
    // Test case 3
    int n3 = 4;
    int result3 = solution.climbStairs(n3);
    return 0;
}
```