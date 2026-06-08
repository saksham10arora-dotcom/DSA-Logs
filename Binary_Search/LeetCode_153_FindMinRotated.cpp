/**
 * Problem: Find Minimum in Rotated Sorted Array (LeetCode 153)
 * Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution ---
// Time Complexity: O(log N)
// Space Complexity: O(1)
int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    int ans = nums[0];
    while (low <= high) {
        if (nums[low] <= nums[high]) {
            ans = min(ans, nums[low]);
            break;
        }
        int mid = low + (high - low) / 2;
        ans = min(ans, nums[mid]);
        if (nums[mid] >= nums[low]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << "Min: " << findMin(nums) << endl;
    return 0;
}




































