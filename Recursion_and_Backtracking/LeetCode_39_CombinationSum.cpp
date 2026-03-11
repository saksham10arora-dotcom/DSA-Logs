```cpp
// Combination Sum, https://leetcode.com/problems/combination-sum/
// Given an array of distinct integers candidates and a target integer target, 
// return a list of all unique combinations in candidates where the candidate number 
// is less than or equal to the target and the sum of the numbers in the combination 
// is equal to the target.

// Brute force approach: Try all possible combinations of numbers, O(2^n) complexity
// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> result;
//         vector<int> current;
//         backtrack(result, current, candidates, target, 0);
//         return result;
//     }
// 
//     void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int target, int start) {
//         if (target < 0) return;
//         if (target == 0) {
//             result.push_back(current);
//             return;
//         }
//         for (int i = start; i < candidates.size(); i++) {
//             current.push_back(candidates[i]);
//             backtrack(result, current, candidates, target - candidates[i], i);
//             current.pop_back();
//         }
//     }
// };

// Optimal solution: Use backtracking to find combinations, O(N^(T/M + 1)) complexity
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(result, current, candidates, target, 0);
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int target, int start) {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
            current.push_back(candidates[i]);
            backtrack(result, current, candidates, target - candidates[i], i);
            current.pop_back();
        }
    }
};

int main() {
    Solution solution;
    vector<int> candidates1 = {2, 3, 5};
    vector<vector<int>> result1 = solution.combinationSum(candidates1, 8);
    for (auto& combination : result1) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> candidates2 = {2, 3, 5};
    vector<vector<int>> result2 = solution.combinationSum(candidates2, 10);
    for (auto& combination : result2) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> candidates3 = {2};
    vector<vector<int>> result3 = solution.combinationSum(candidates3, 1);
    for (auto& combination : result3) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
```