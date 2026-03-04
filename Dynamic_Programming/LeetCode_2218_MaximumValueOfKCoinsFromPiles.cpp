```cpp
// Maximum Value Of K Coins From Piles, https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
// Given an array of piles where each pile contains a number of coins, and a number k, 
// return the maximum number of coins that can be obtained by choosing k coins from the piles.

// Brute force approach with O(2^n * k) complexity
// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) {
//         int n = nums.size();
//         int res = 0;
//         for (int mask = 0; mask < (1 << n); mask++) {
//             int sum = 0;
//             for (int i = 0; i < n; i++) {
//                 if ((mask >> i) & 1) {
//                     sum += nums[i];
//                 }
//             }
//             if (sum <= k) {
//                 res = max(res, sum);
//             }
//         }
//         return res;
//     }
// };

// Optimal solution with O(n * k) complexity
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        int sum = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum + k < nums[right] * (right - left + 1)) {
                sum -= nums[left];
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 4};
    int k1 = 5;
    cout << solution.maxFrequency(nums1, k1) << endl;  // Output: 3

    vector<int> nums2 = {3, 1, 2, 4};
    int k2 = 4;
    cout << solution.maxFrequency(nums2, k2) << endl;  // Output: 3

    vector<int> nums3 = {1, 1, 1, 1};
    int k3 = 10;
    cout << solution.maxFrequency(nums3, k3) << endl;  // Output: 4

    return 0;
}
```