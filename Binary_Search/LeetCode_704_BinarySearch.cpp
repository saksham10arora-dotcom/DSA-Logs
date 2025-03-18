/**
 * Problem: Binary Search (LeetCode 704)
 * Link: https://leetcode.com/problems/binary-search/
 */

#include <iostream>
#include <vector>

using namespace std;

// --- Optimal Solution (Standard Binary Search) ---
// Time Complexity: O(log N)
// Space Complexity: O(1)
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << "Index: " << search(nums, target) << endl;
    return 0;
}










































