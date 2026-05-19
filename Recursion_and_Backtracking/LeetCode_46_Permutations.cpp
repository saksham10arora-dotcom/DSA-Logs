/**
 * Problem: Permutations (LeetCode 46)
 * Link: https://leetcode.com/problems/permutations/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Backtracking) ---
// Time Complexity: O(N * N!)
// Space Complexity: O(N)
void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& res) {
    if (current.size() == nums.size()) {
        res.push_back(current);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, current, used, res);
        current.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    backtrack(nums, current, used, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = permute(nums);
    for (auto& p : res) {
        cout << "[ ";
        for (int x : p) cout << x << " ";
        cout << "]" << endl;
    }
    return 0;
}




















