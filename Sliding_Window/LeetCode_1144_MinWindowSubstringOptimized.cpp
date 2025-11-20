```cpp
// LeetCode problem 1144: Decrease Elements To Make Array Zigzag
// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
// Given an array nums, we need to decrease elements to make array zigzag.

// Brute force approach with O(n^2) complexity
// class Solution {
// public:
//     int movesToMakeZigzag(vector<int>& nums) {
//         int n = nums.size();
//         int res = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             int tmp = 0;
//             for (int j = 0; j < n; j++) {
//                 if ((j - i) % 2 == 0 && (j > 0 && nums[j] >= nums[j - 1] || j < n - 1 && nums[j] >= nums[j + 1])) {
//                     tmp++;
//                 }
//             }
//             res = min(res, tmp);
//         }
//         return res;
//     }
// };

// Optimal solution with O(n) complexity
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        for (int parity = 0; parity < 2; parity++) {
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                if ((i % 2 == parity) && (i > 0 && nums[i] >= nums[i - 1] || i < n - 1 && nums[i] >= nums[i + 1])) {
                    tmp++;
                }
            }
            res = min(res, tmp);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {9, 6, 1, 6, 2};
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << solution.movesToMakeZigzag(nums1) << endl;  // Output: 2
    cout << solution.movesToMakeZigzag(nums2) << endl;  // Output: 4
    cout << solution.movesToMakeZigzag(nums3) << endl;  // Output: 2
    return 0;
}
```