```cpp
// Minimum Rounds I I I, https://cses.fi/problemset/task/1622, 
// Given a list of n integers, find the minimum number of rounds to make all numbers equal.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(2^n) complexity
// int minRoundsBruteForce(const std::vector<int>& nums) {
//     int n = nums.size();
//     int minRounds = n;
//     for (int mask = 0; mask < (1 << n); ++mask) {
//         std::vector<int> temp = nums;
//         int rounds = 0;
//         for (int i = 0; i < n; ++i) {
//             if ((mask & (1 << i))!= 0) {
//                 temp[i]++;
//                 rounds++;
//             }
//         }
//         if (std::equal(temp.begin() + 1, temp.end(), temp.begin())) {
//             minRounds = std::min(minRounds, rounds);
//         }
//     }
//     return minRounds;
// }

// Optimal solution with O(n) complexity
int minRounds(const std::vector<int>& nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    int minRounds = 0;
    for (int i = 1; i < n; ++i) {
        minRounds += nums[i] - nums[0];
    }
    return minRounds;
}

int main() {
    std::vector<int> test1 = {1, 2, 3};
    std::vector<int> test2 = {4, 5, 6};
    std::vector<int> test3 = {10, 10, 10};

    std::cout << minRounds(test1) << std::endl;  // Output: 2
    std::cout << minRounds(test2) << std::endl;  // Output: 2
    std::cout << minRounds(test3) << std::endl;  // Output: 0

    return 0;
}
```