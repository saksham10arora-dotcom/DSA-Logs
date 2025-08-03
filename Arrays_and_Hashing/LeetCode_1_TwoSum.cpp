/**
 * Problem: Two Sum (LeetCode 1)
 * Link: https://leetcode.com/problems/two-sum/
 * 
 * Description: Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// --- Brute Force ---
// Time Complexity: O(N^2)
// Space Complexity: O(1)
vector<int> twoSumBrute(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

// --- Optimal Solution (using Hash Map) ---
// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> twoSumOptimal(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mpp.find(complement) != mpp.end()) {
            return {mpp[complement], i};
        }
        mpp[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSumOptimal(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}










































