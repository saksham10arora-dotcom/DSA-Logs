```cpp
// LeetCode problem 66: Pow(x, n) II
// https://leetcode.com/problems/powx-n-ii/
// Implement pow(x, n), which calculates x raised to the power of n (i.e., x^n).

class Solution {
public:
    // Brute force approach with O(n) complexity
    double myPow_BruteForce(double x, int n) {
        double result = 1.0;
        for (int i = 0; i < abs(n); i++) {
            result *= x;
        }
        return n < 0 ? 1 / result : result;
    }

    // Optimal solution with O(log n) complexity
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double half = myPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        return n < 0 ? 1 / (half * half * x) : half * half * x;
    }
};

int main() {
    Solution solution;
    printf("%.5f\n", solution.myPow(2.0, 3));  // Output: 8.00000
    printf("%.5f\n", solution.myPow(2.1, 3));  // Output: 9.26100
    printf("%.5f\n", solution.myPow(2.0, -3)); // Output: 0.12500
    return 0;
}
```