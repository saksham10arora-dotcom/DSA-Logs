```cpp
// LeetCode problem 1716: Calculate Money In Leetcode Bank
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/
// Calculate the total amount of money in the LeetCode bank after n days.

class Solution {
public:
    int totalMoney(int n) {
        // Brute force approach: O(n) complexity
        // int total = 0;
        // for (int i = 1; i <= n; i++) {
        //     int week = (i - 1) / 7;
        //     total += week + (i - week * 7);
        // }
        // return total;

        // Optimal solution: O(1) complexity
        int total = 0;
        int weeks = n / 7;
        int remainingDays = n % 7;
        int startWeek = 1;
        int endWeek = startWeek + weeks - 1;
        total += (weeks * 7) * (startWeek + endWeek) / 2;
        total += (remainingDays * (remainingDays + 1)) / 2 + remainingDays * weeks;
        return total;
    }
};

int main() {
    Solution solution;
    // Test case 1:
    int n1 = 4;
    int result1 = solution.totalMoney(n1);
    // Test case 2:
    int n2 = 10;
    int result2 = solution.totalMoney(n2);
    // Test case 3:
    int n3 = 20;
    int result3 = solution.totalMoney(n3);
    return 0;
}
```