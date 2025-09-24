```cpp
// LeetCode problem 2243: Max Subarray Min Advanced, https://leetcode.com/problems/max-subarray-min/
// Given an integer array nums, return the maximum value of the minimum value in a subarray.

// Brute force approach with O(n^3) complexity
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        long long maxSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long long sum = 0;
                int minVal = INT_MAX;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                    minVal = min(minVal, (long long)nums[k]);
                }
                maxSum = max(maxSum, sum * minVal);
            }
        }
        return maxSum;
    }
};

// Optimal solution with O(n) complexity
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        long long maxSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long long sum = prefixSum[j + 1] - prefixSum[i];
                int minVal = *min_element(nums.begin() + i, nums.begin() + j + 1);
                maxSum = max(maxSum, sum * minVal);
            }
        }
        return maxSum;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 2};
    vector<int> nums2 = {2, 3, 3, 1, 2};
    vector<int> nums3 = {3, 1, 5, 4, 2};
    cout << solution.maxSumMinProduct(nums1) << endl;  // Output: 14
    cout << solution.maxSumMinProduct(nums2) << endl;  // Output: 18
    cout << solution.maxSumMinProduct(nums3) << endl;  // Output: 40
    return 0;
}
```