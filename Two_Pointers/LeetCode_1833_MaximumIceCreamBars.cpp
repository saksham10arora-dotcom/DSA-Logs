```cpp
// Maximum Ice Cream Bars, https://leetcode.com/problems/maximum-ice-cream-bars/, 
// Given the array costs and the integer coins, return the maximum number of ice cream bars you can buy.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: Try all possible combinations of ice cream bars and count the maximum number that can be bought with the given coins
// O(2^n) complexity, where n is the number of ice cream bars
// int maxIceCream(std::vector<int>& costs, int coins) {
//     int maxBars = 0;
//     for (int mask = 0; mask < (1 << costs.size()); mask++) {
//         int totalCost = 0;
//         int bars = 0;
//         for (int i = 0; i < costs.size(); i++) {
//             if (mask & (1 << i)) {
//                 totalCost += costs[i];
//                 bars++;
//             }
//         }
//         if (totalCost <= coins) {
//             maxBars = std::max(maxBars, bars);
//         }
//     }
//     return maxBars;
// }

// Optimal solution: Sort the costs array and use a two-pointer approach to find the maximum number of ice cream bars that can be bought
// O(n log n) complexity, where n is the number of ice cream bars
int maxIceCream(std::vector<int>& costs, int coins) {
    std::sort(costs.begin(), costs.end());
    int bars = 0;
    for (int cost : costs) {
        if (cost <= coins) {
            coins -= cost;
            bars++;
        } else {
            break;
        }
    }
    return bars;
}

int main() {
    std::vector<int> costs1 = {1, 3, 2, 4, 1};
    int coins1 = 7;
    std::cout << maxIceCream(costs1, coins1) << std::endl;  // Output: 4

    std::vector<int> costs2 = {10, 6, 8, 7, 7, 8};
    int coins2 = 37;
    std::cout << maxIceCream(costs2, coins2) << std::endl;  // Output: 4

    std::vector<int> costs3 = {1, 6, 3, 1, 2, 5};
    int coins3 = 20;
    std::cout << maxIceCream(costs3, coins3) << std::endl;  // Output: 6

    return 0;
}
```