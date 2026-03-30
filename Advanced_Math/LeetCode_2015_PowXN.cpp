```cpp
// LeetCode problem 2015: Pow(x, n)
// https://leetcode.com/problems/powx-n/
// Implement pow(x, n), which calculates x raised to the power of n (i.e., x^n).

class Solution {
public:
    // Brute force approach: O(n) complexity
    double myPow_BruteForce(double x, int n) {
        double result = 1.0;
        for (int i = 0; i < abs(n); i++) {
            result *= x;
        }
        return n < 0 ? 1 / result : result;
    }

    // Optimal solution: O(log n) complexity
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double half = myPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        if (n > 0) return x * half * half;
        return (1 / x) * half * half;
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