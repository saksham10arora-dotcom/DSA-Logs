```cpp
// Problem: Lemonade Change I I
// Link: https://cses.fi/problemset/task/1784
// Description: Determine the minimum number of lemons needed to make change for a given amount of money.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(2^n) complexity
// int minLemons(int n, std::vector<int>& prices) {
//     std::vector<int> dp(n + 1, 1e9);
//     dp[0] = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j < prices.size(); j++) {
//             if (i >= prices[j]) {
//                 dp[i] = std::min(dp[i], dp[i - prices[j]] + 1);
//             }
//         }
//     }
//     return dp[n] == 1e9 ? -1 : dp[n];
// }

// Optimal solution with O(n) complexity
int minLemons(int n, std::vector<int>& prices) {
    int count5 = 0, count10 = 0;
    for (int price : prices) {
        if (price == 5) {
            count5++;
        } else if (price == 10) {
            if (count5 == 0) {
                return -1;
            }
            count5--;
            count10++;
        } else if (price == 20) {
            if (count10 >&& count5 > 0) {
                count10--;
                count5--;
            } else if (count5 >= 3) {
                count5 -= 3;
            } else {
                return -1;
            }
        }
    }
    return prices.size();
}

int main() {
    std::vector<int> prices1 = {5, 5, 10, 20};
    std::cout << minLemons(20, prices1) << std::endl;  // Output: 4

    std::vector<int> prices2 = {5, 5, 10};
    std::cout << minLemons(15, prices2) << std::endl;  // Output: 3

    std::vector<int> prices3 = {10, 10, 10};
    std::cout << minLemons(30, prices3) << std::endl;  // Output: -1

    return 0;
}
```