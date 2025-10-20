```cpp
// Last Stone Weight III, https://leetcode.com/problems/last-stone-weight-iii/, 
// Given an array of integers stones where stones[i] represents the weight of the ith stone, 
// we need to divide the stones into two piles such that the difference between the total weight of the two piles is minimized.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: Try all possible combinations of stones in two piles, O(2^n)
class Solution_Brute_Force {
public:
    int lastStoneWeightIII(std::vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (int stone : stones) sum += stone;
        int diff = INT_MAX;
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum1 = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) sum1 += stones[i];
            }
            diff = std::min(diff, std::abs(sum1 - (sum - sum1)));
        }
        return diff;
    }
};

// Optimal solution: Use dynamic programming to find the maximum sum of stones that is less than or equal to half of the total sum, O(n * sum)
class Solution {
public:
    int lastStoneWeightIII(std::vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (int stone : stones) sum += stone;
        int target = sum / 2;
        std::vector<int> dp(target + 1, 0);
        for (int stone : stones) {
            for (int i = target; i >= stone; i--) {
                dp[i] = std::max(dp[i], dp[i - stone] + stone);
            }
        }
        return sum - 2 * dp[target];
    }
};

int main() {
    Solution solution;
    std::vector<int> stones1 = {2,7,4,1,8,1};
    std::cout << solution.lastStoneWeightIII(stones1) << std::endl;  // Output: 1
    std::vector<int> stones2 = {1,2};
    std::cout << solution.lastStoneWeightIII(stones2) << std::endl;  // Output: 1
    std::vector<int> stones3 = {1,1,1};
    std::cout << solution.lastStoneWeightIII(stones3) << std::endl;  // Output: 1
    return 0;
}
```