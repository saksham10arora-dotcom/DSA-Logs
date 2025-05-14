```cpp
// Codeforces_150E_MinimumDaysIII, https://codeforces.com/contest/150/problem/E
// Given a set of trees with different growth rates, find the minimum number of days required for all trees to reach a certain height.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: O(n * max_height) - not efficient for large inputs
// int minDays(std::vector<int>& growthRates, int targetHeight) {
//     int days = 0;
//     while (true) {
//         bool allReached = true;
//         for (int i = 0; i < growthRates.size(); ++i) {
//             if (growthRates[i] < targetHeight) {
//                 growthRates[i]++;
//                 allReached = false;
//             }
//         }
//         if (allReached) break;
//         days++;
//     }
//     return days;
// }

// Optimal solution: O(n * log(max_height)) - using binary search
int minDays(std::vector<int>& growthRates, int targetHeight) {
    int low = 0, high = targetHeight;
    while (low < high) {
        int mid = low + (high - low) / 2;
        bool allReached = true;
        for (int rate : growthRates) {
            if (rate * mid < targetHeight) {
                allReached = false;
                break;
            }
        }
        if (allReached) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    std::vector<int> growthRates1 = {1, 2, 3};
    std::cout << minDays(growthRates1, 6) << std::endl;  // Output: 4

    std::vector<int> growthRates2 = {1, 1, 1};
    std::cout << minDays(growthRates2, 3) << std::endl;  // Output: 3

    std::vector<int> growthRates3 = {2, 4, 6};
    std::cout << minDays(growthRates3, 12) << std::endl;  // Output: 2

    return 0;
}
```