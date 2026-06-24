```cpp
// LeetCode problem 618: https://leetcode.com/problems/search-insert-position/
// Given a sorted array and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.

// Brute force approach with O(n) complexity
class Solution_Brute {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            } else if (nums[i] > target) {
                return i;
            }
        }
        return nums.size();
    }
};

// Optimal solution with O(log n) complexity
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << solution.searchInsert(nums1, target1) << endl;  // Output: 2

    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << solution.searchInsert(nums2, target2) << endl;  // Output: 1

    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << solution.searchInsert(nums3, target3) << endl;  // Output: 4

    return 0;
}
```