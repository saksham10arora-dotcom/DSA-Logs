```cpp
// LeetCode problem 50: Spiral Matrix Variant
// https://leetcode.com/problems/pow-x-n/
// Implement pow(x, n), which calculates x raised to the power of n (i.e., x^n).

// Brute force approach: O(n) complexity
class Solution {
public:
    double myPow_BruteForce(double x, int n) {
        double result = 1.0;
        for (int i = 0; i < abs(n); i++) {
            result *= x;
        }
        if (n < 0) {
            return 1.0 / result;
        }
        return result;
    }
};

// Optimal solution: O(log n) complexity
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 1.0 / myPow(x, -n);
        }
        if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        }
        return x * myPow(x * x, n / 2);
    }
};

int main() {
    Solution solution;
    // Test case 1:
    double x = 2.0;
    int n = 3;
    double result = solution.myPow(x, n);
    // Test case 2:
    x = 2.1;
    n = 3;
    result = solution.myPow(x, n);
    // Test case 3:
    x = 2.0;
    n = -3;
    result = solution.myPow(x, n);
    return 0;
}
```