```cpp
// LeetCode problem 153: Find Min Rotated, https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Given the sorted rotated array nums of distinct integers, return the minimum element of this array.

// Brute force approach with O(n) complexity
class Solution_Brute {
public:
    int findMin(vector<int>& nums) {
        int min_val = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < min_val) {
                min_val = nums[i];
            }
        }
        return min_val;
    }
};

// Optimal solution with O(log n) complexity
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main() {
    Solution solution;
    vector<int> test1 = {3, 4, 5, 1, 2};
    vector<int> test2 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> test3 = {11, 13, 15, 17};
    cout << solution.findMin(test1) << endl;  // Output: 1
    cout << solution.findMin(test2) << endl;  // Output: 0
    cout << solution.findMin(test3) << endl;  // Output: 11
    return 0;
}
```