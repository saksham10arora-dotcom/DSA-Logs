```cpp
// LeetCode problem 201: Bitwise AND of Numbers Range
// https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

class Solution {
public:
    // Brute force approach with O(n) complexity
    int rangeBitwiseAnd_BruteForce(int m, int n) {
        int result = m;
        for (int i = m + 1; i <= n; i++) {
            result = result & i;
        }
        return result;
    }

    // Optimal solution with O(log n) complexity
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while (m < n) {
            m = m >> 1;
            n = n >> 1;
            shift++;
        }
        return m << shift;
    }
};

int main() {
    Solution solution;
    // Test case 1
    int m1 = 5;
    int n1 = 7;
    int result1 = solution.rangeBitwiseAnd(m1, n1);
    // Test case 2
    int m2 = 2;
    int n2 = 3;
    int result2 = solution.rangeBitwiseAnd(m2, n2);
    // Test case 3
    int m3 = 1;
    int n3 = 2147483647;
    int result3 = solution.rangeBitwiseAnd(m3, n3);
    return 0;
}
```