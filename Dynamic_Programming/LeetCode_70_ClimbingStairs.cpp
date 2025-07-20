/**
 * Problem: Climbing Stairs (LeetCode 70)
 * Link: https://leetcode.com/problems/climbing-stairs/
 */

#include <iostream>
#include <vector>

using namespace std;

// --- Brute Force (Recursive) ---
// Time Complexity: O(2^N)
// Space Complexity: O(N)
int climbStairsRecursive(int n) {
    if (n <= 2) return n;
    return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
}

// --- Better Solution (Memoization) ---
// Time Complexity: O(N)
// Space Complexity: O(N)
int memo[100];
int climbStairsMemo(int n) {
    if (n <= 2) return n;
    if (memo[n] != 0) return memo[n];
    return memo[n] = climbStairsMemo(n - 1) + climbStairsMemo(n - 2);
}

// --- Optimal Solution (Space Optimized Iterative) ---
// Time Complexity: O(N)
// Space Complexity: O(1)
int climbStairsOptimal(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev = 2;
    for (int i = 3; i <= n; i++) {
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main() {
    int n = 5;
    cout << "Ways: " << climbStairsOptimal(n) << endl;
    return 0;
}

































