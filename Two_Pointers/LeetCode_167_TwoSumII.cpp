/**
 * Problem: Two Sum II - Input Array Is Sorted (LeetCode 167)
 * Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 */

#include <iostream>
#include <vector>

using namespace std;

// --- Optimal Solution (Two Pointers) ---
// Time Complexity: O(N)
// Space Complexity: O(1)
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        int currentSum = numbers[left] + numbers[right];
        if (currentSum == target) {
            return {left + 1, right + 1};
        } else if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(numbers, target);
    cout << "Indices: " << res[0] << ", " << res[1] << endl;
    return 0;
}


























