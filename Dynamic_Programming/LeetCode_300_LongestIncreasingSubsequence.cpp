/**
 * Problem: Longest Increasing Subsequence (LeetCode 300)
 * Link: https://leetcode.com/problems/longest-increasing-subsequence/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Better Solution (Dynamic Programming) ---
// Time Complexity: O(N^2)
// Space Complexity: O(N)
int lengthOfLIS_DP(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    int maxLen = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

// --- Optimal Solution (Binary Search + Patience Sorting Idea) ---
// Time Complexity: O(N log N)
// Space Complexity: O(N)
int lengthOfLIS_Optimal(vector<int>& nums) {
    vector<int> tails;
    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS Length: " << lengthOfLIS_Optimal(nums) << endl;
    return 0;
}





































