/**
 * Problem: Kth Largest Element in an Array (LeetCode 215)
 * Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// --- Optimal Solution (Min-Heap) ---
// Time Complexity: O(N log K)
// Space Complexity: O(K)
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minpq;
    for (int x : nums) {
        minpq.push(x);
        if (minpq.size() > k) minpq.pop();
    }
    return minpq.top();
}

int main() {
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    cout << "Kth Largest: " << findKthLargest(nums, k) << endl;
    return 0;
}















