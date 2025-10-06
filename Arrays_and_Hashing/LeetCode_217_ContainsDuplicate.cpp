/**
 * Problem: Contains Duplicate (LeetCode 217)
 * Link: https://leetcode.com/problems/contains-duplicate/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// --- Brute Force ---
// Time Complexity: O(N^2)
// Space Complexity: O(1)
bool containsDuplicateBrute(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}

// --- Better Solution (Sorting) ---
// Time Complexity: O(N log N)
// Space Complexity: O(1)
bool containsDuplicateBetter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size() - 1; i++) {
        if (nums[i] == nums[i+1]) return true;
    }
    return false;
}

// --- Optimal Solution (Hash Set) ---
// Time Complexity: O(N)
// Space Complexity: O(N)
bool containsDuplicateOptimal(vector<int>& nums) {
    unordered_set<int> st;
    for (int x : nums) {
        if (st.count(x)) return true;
        st.insert(x);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << (containsDuplicateOptimal(nums) ? "True" : "False") << endl;
    return 0;
}
































