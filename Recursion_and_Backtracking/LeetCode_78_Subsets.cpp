/**
 * Problem: Subsets (LeetCode 78)
 * Link: https://leetcode.com/problems/subsets/
 */

#include <iostream>
#include <vector>

using namespace std;

// --- Optimal Solution (Backtracking) ---
// Time Complexity: O(N * 2^N)
// Space Complexity: O(N)
void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& res) {
    res.push_back(current);
    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);
        backtrack(i + 1, nums, current, res);
        current.pop_back(); // backtrack
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> current;
    backtrack(0, nums, current, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    for (auto& subset : res) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]" << endl;
    }
    return 0;
}

















