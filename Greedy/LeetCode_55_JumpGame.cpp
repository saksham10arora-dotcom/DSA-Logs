/**
 * Problem: Jump Game (LeetCode 55)
 * Link: https://leetcode.com/problems/jump-game/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Greedy Goal Post) ---
// Time Complexity: O(N)
// Space Complexity: O(1)
bool canJump(vector<int>& nums) {
    int goal = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (i + nums[i] >= goal) {
            goal = i;
        }
    }
    return goal == 0;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << (canJump(nums) ? "Can Jump" : "Cannot Jump") << endl;
    return 0;
}

















