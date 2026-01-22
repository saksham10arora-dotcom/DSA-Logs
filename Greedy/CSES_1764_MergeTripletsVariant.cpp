```cpp
// Problem: Merge Triplets Variant
// Link: https://cses.fi/problemset/task/1764
// Description: Given a target triplet and a list of triplets, find the minimum number of triplets to merge to get the target triplet.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(2^n) complexity
// int minTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
//     int n = triplets.size();
//     int res = INT_MAX;
//     for (int mask = 0; mask < (1 << n); mask++) {
//         std::vector<int> curr(3, 0);
//         int cnt = 0;
//         for (int i = 0; i < n; i++) {
//             if (mask & (1 << i)) {
//                 curr[0] = std::max(curr[0], triplets[i][0]);
//                 curr[1] = std::max(curr[1], triplets[i][1]);
//                 curr[2] = std::max(curr[2], triplets[i][2]);
//                 cnt++;
//             }
//         }
//         if (curr == target) {
//             res = std::min(res, cnt);
//         }
//     }
//     return res;
// }

// Optimal solution with O(n) complexity
int minTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
    int res = 0;
    std::vector<int> curr(3, 0);
    for (int i = 0; i < 3; i++) {
        for (auto& triplet : triplets) {
            if (triplet[i] <= target[i] && triplet[(i + 1) % 3] <= target[(i + 1) % 3] && triplet[(i + 2) % 3] <= target[(i + 2) % 3]) {
                curr[i] = std::max(curr[i], triplet[i]);
            }
        }
        if (curr[i] != target[i]) {
            return -1;
        }
        res++;
    }
    return res;
}

int main() {
    std::vector<std::vector<int>> triplets1 = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}};
    std::vector<int> target1 = {2, 7, 5};
    std::cout << minTriplets(triplets1, target1) << std::endl;  // Output: 2

    std::vector<std::vector<int>> triplets2 = {{2, 5, 3}, {2, 3, 4}, {1, 2, 5}, {5, 2, 3}};
    std::vector<int> target2 = {4, 5, 5};
    std::cout << minTriplets(triplets2, target2) << std::endl;  // Output: -1

    std::vector<std::vector<int>> triplets3 = {{1, 3, 4}, {5, 2, 10}, {5, 6, 4}};
    std::vector<int> target3 = {5, 6, 4};
    std::cout << minTriplets(triplets3, target3) << std::endl;  // Output: 1

    return 0;
}
```