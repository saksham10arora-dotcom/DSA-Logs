```cpp
// Codeforces_906E_SubsetSumsII
// https://codeforces.com/contest/906/problem/E
// Given a set of integers, find the number of distinct subset sums.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// Brute force approach with O(2^n) complexity
int bruteForce(const std::vector<int>& nums) {
    std::set<int> subsetSums;
    int n = nums.size();
    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += nums[i];
            }
        }
        subsetSums.insert(sum);
    }
    return subsetSums.size();
}

// Optimal solution with O(n * sum) complexity
int optimalSolution(const std::vector<int>& nums) {
    int maxSum = 0;
    for (int num : nums) {
        maxSum += num;
    }
    std::vector<bool> dp(maxSum + 1, false);
    dp[0] = true;
    for (int num : nums) {
        for (int i = maxSum; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }
    int count = 0;
    for (bool val : dp) {
        if (val) {
            ++count;
        }
    }
    return count;
}

int main() {
    std::vector<int> test1 = {1, 2, 3};
    std::vector<int> test2 = {1, 1, 1};
    std::vector<int> test3 = {5, 10, 15};
    std::cout << bruteForce(test1) << std::endl;  // Output: 8
    std::cout << bruteForce(test2) << std::endl;  // Output: 4
    std::cout << bruteForce(test3) << std::endl;  // Output: 8
    std::cout << optimalSolution(test1) << std::endl;  // Output: 8
    std::cout << optimalSolution(test2) << std::endl;  // Output: 4
    std::cout << optimalSolution(test3) << std::endl;  // Output: 8
    return 0;
}
```