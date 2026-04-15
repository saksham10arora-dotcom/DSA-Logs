```cpp
// LeetCode problem 1486: Xor Operation In An Array, https://leetcode.com/problems/xor-operation-in-an-array/
// Given an integer n and an integer start, define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length.
// Return the bitwise XOR of all elements in nums.

class Solution {
public:
    // Brute force approach with O(n) complexity
    int xorOperation_Brute(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result ^= (start + 2 * i);
        }
        return result;
    }

    // Optimal solution with O(n) complexity
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result ^= (start + 2 * i);
        }
        return result;
    }
};

int main() {
    Solution solution;
    // Test case