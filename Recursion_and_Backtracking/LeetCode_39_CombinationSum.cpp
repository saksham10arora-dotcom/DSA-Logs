/**
 * Problem: Combination Sum (LeetCode 39)
 * Link: https://leetcode.com/problems/combination-sum/
 */

#include <iostream>
#include <vector>

using namespace std;

// --- Optimal Solution (Backtracking) ---
// Time Complexity: O(2^target)
// Space Complexity: O(target/min_val)
void backtrack(int i, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(current);
        return;
    }
    if (target < 0 || i == candidates.size()) return;
    
    // Pick current
    current.push_back(candidates[i]);
    backtrack(i, target - candidates[i], candidates, current, res);
    current.pop_back();
    
    // Skip current
    backtrack(i + 1, target, candidates, current, res);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> current;
    backtrack(0, target, candidates, current, res);
    return res;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = combinationSum(candidates, target);
    for (auto& c : res) {
        cout << "[ ";
        for (int x : c) cout << x << " ";
        cout << "]" << endl;
    }
    return 0;
}





















