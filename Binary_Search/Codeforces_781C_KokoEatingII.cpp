```cpp
// Codeforces_781C_KokoEatingII, https://codeforces.com/contest/781/problem/C
// Koko loves to eat bananas. There are n piles of bananas, the i-th pile has piles[i] bananas.
// The guards have gone and will come back in h hours. Koko can decide her banana eating speed.
// Given the number of piles (n), the number of hours (h), and the piles of bananas,
// determine the minimum integer speed Koko can have to eat all the bananas within h hours.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n * max(piles)) complexity
// int minEatingSpeed(int n, int h, std::vector<int>& piles) {
//     int maxPile = *std::max_element(piles.begin(), piles.end());
//     for (int speed = 1; speed <= maxPile; ++speed) {
//         int time = 0;
//         for (int pile : piles) {
//             time += (pile + speed - 1) / speed;
//         }
//         if (time <= h) {
//             return speed;
//         }
//     }
//     return -1; // should not reach here
// }

// Optimal solution with O(n * log(max(piles))) complexity
int minEatingSpeed(int n, int h, std::vector<int>& piles) {
    int left = 1, right = *std::max_element(piles.begin(), piles.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        int time = 0;
        for (int pile : piles) {
            time += (pile + mid - 1) / mid;
        }
        if (time <= h) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    std::vector<int> test1 = {3, 6, 7, 11};
    std::cout << minEatingSpeed(4, 8, test1) << std::endl; // 4

    std::vector<int> test2 = {30, 11, 23, 4, 20};
    std::cout << minEatingSpeed(5, 5, test2) << std::endl; // 30

    std::vector<int> test3 = {30, 11, 23, 4, 20};
    std::cout << minEatingSpeed(5, 6, test3) << std::endl; // 23

    return 0;
}
```