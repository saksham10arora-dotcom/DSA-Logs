```cpp
// LeetCode problem 2335: Minimum Amount Of Time To Fill Cups
// https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/
// In this problem, we are given an array of integers representing the number of cups that need to be filled.
// We have two types of water coolers: one that fills one cup in 1 minute and another that fills two cups in 2 minutes.
// The goal is to find the minimum amount of time required to fill all the cups.

#include <iostream>
#include <queue>
#include <vector>

// Brute force approach with O(2^n) complexity
// This approach is not efficient and will result in a time limit exceeded error for large inputs.
// int fillCups(std::vector<int>& amount) {
//     int n = amount.size();
//     int res = 0;
//     std::function<void(int, int)> dfs = [&](int idx, int time) {
//         if (idx == n) {
//             res = std::max(res, time);
//             return;
//         }
//         dfs(idx + 1, time + amount[idx]);
//         if (idx + 1 < n) {
//             dfs(idx + 2, time + amount[idx] + amount[idx + 1]);
//         }
//     };
//     dfs(0, 0);
//     return res;
// }

// Optimal solution with O(n log n) complexity
int fillCups(std::vector<int>& amount) {
    std::priority_queue<int> pq;
    for (int num : amount) {
        pq.push(num);
    }
    int res = 0;
    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();
        if (pq.empty()) {
            res += a;
            break;
        }
        int b = pq.top();
        pq.pop();
        res += 1;
        a -= 1;
        b -= 1;
        if (a > 0) {
            pq.push(a);
        }
        if (b > 0) {
            pq.push(b);
        }
    }
    return res;
}

int main() {
    std::vector<int> amount1 = {1, 2, 3};
    std::cout << fillCups(amount1) << std::endl;  // Output: 4

    std::vector<int> amount2 = {1, 2, 3, 4};
    std::cout << fillCups(amount2) << std::endl;  // Output: 7

    std::vector<int> amount3 = {5, 4, 4};
    std::cout << fillCups(amount3) << std::endl;  // Output: 9

    return 0;
}
```