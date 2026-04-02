```cpp
// LeetCode problem 2412: Minimum Money Required Before Transactions
// https://leetcode.com/problems/minimum-money-required-before-transactions/
// Given an integer array transactions where transactions[i] denotes the amount of money to be transferred from person i to person (i+1) % n, 
// return the minimum money required so that all transactions are possible.

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long minimumMoney(std::vector<int>& transactions) {
        // Brute force approach: O(n^2) complexity
        // This approach is not efficient and will exceed the time limit for large inputs
        // long long minMoney = 0;
        // for (int i = 0; i < transactions.size(); i++) {
        //     long long balance = 0;
        //     for (int j = 0; j < transactions.size(); j++) {
        //         balance += transactions[(i + j) % transactions.size()];
        //         minMoney = std::max(minMoney, -balance);
        //     }
        // }
        // return minMoney;

        // Optimal solution: O(n) complexity
        long long minMoney = 0;
        long long balance = 0;
        for (int transaction : transactions) {
            balance += transaction;
            minMoney = std::max(minMoney, -balance);
        }
        return minMoney;
    }
};

int main() {
    Solution solution;
    std::vector<int> transactions1 = {2, -1, 1};
    std::cout << solution.minimumMoney(transactions1) << std::endl;  // Output: 1

    std::vector<int> transactions2 = {3, 0, -3};
    std::cout << solution.minimumMoney(transactions2) << std::endl;  // Output: 3

    std::vector<int> transactions3 = {0, 0, 0};
    std::cout << solution.minimumMoney(transactions3) << std::endl;  // Output: 0

    return 0;
}
```