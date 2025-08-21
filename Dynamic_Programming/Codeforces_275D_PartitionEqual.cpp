```cpp
// Codeforces_275D_PartitionEqual, https://codeforces.com/contest/275/problem/D
// Given a set of integers, determine if it can be partitioned into two subsets with equal sums.

#include <iostream>
#include <vector>
#include <numeric>

// Brute force approach: try all possible subsets (O(2^n))
bool bruteForcePartitionEqual(const std::vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    int target = sum / 2;
    for (int mask = 0; mask < (1 << nums.size()); ++mask) {
        int subsetSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if ((mask & (1 << i)) != 0) subsetSum += nums[i];
        }
        if (subsetSum == target) return true;
    }
    return false;
}

// Optimal solution: dynamic programming (O(n*sum))
bool optimalPartitionEqual(const std::vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    int target = sum / 2;
    std::vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : nums) {
        for (int i = target; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }
    return dp[target];
}

int main() {
    std::vector<int> test1 = {1, 5, 11, 5};
    std::vector<int> test2 = {1, 2, 3, 9};
    std::vector<int> test3 = {10, 10, 10, 7, 7, 7, 4, 4, 4};

    std::cout << std::boolalpha;
    std::cout << "Test 1: " << optimalPartitionEqual(test1) << std::endl;
    std::cout << "Test 2: " << optimalPartitionEqual(test2) << std::endl;
    std::cout << "Test 3: " << optimalPartitionEqual(test3) << std::endl;

    return 0;
}
```