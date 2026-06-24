```cpp
// LeetCode problem 1064: Fixed Size Window For Maximum Sum
// https://leetcode.com/problems/fixed-size-window-for-maximum-sum
// Given an array of integers `nums` and an integer `k`, return the maximum sum of a subarray of size `k`.

// Brute force approach: O(n*k) complexity
// class Solution {
// public:
//     int maxSumSubarray(int k, vector<int>& nums) {
//         int max_sum = INT_MIN;
//         for (int i = 0; i <= nums.size() - k; i++) {
//             int sum = 0;
//             for (int j = i; j < i + k; j++) {
//                 sum += nums[j];
//             }
//             max_sum = max(max_sum, sum);
//         }
//         return max_sum;
//     }
// };

// Optimal solution: O(n) complexity
class Solution {
public:
    int maxSumSubarray(int k, vector<int>& nums) {
        int max_sum = INT_MIN;
        int window_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            window_sum += nums[i];
            if (i >= k) {
                window_sum -= nums[i - k];
            }
            if (i >= k - 1) {
                max_sum = max(max_sum, window_sum);
            }
        }
        return max_sum;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << solution.maxSumSubarray(2, nums1) << endl;  // Output: 9

    vector<int> nums2 = {5, 4, -1, 7, 8};
    cout << solution.maxSumSubarray(3, nums2) << endl;  // Output: 15

    vector<int> nums3 = {3, 2, 1, 4};
    cout << solution.maxSumSubarray(2, nums3) << endl;  // Output: 6

    return 0;
}
```