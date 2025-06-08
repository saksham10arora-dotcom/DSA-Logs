/**
 * Problem: Sliding Window Maximum (LeetCode 239)
 * Link: https://leetcode.com/problems/sliding-window-maximum/
 */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Monotonic Deque) ---
// Time Complexity: O(N)
// Space Complexity: O(K)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        // remove indices outside the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        // remove elements smaller than the current element from the back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        // add maximum element of the current window to the result
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}





















