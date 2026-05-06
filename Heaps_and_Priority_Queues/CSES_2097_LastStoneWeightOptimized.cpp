```cpp
// Last Stone Weight Optimized, https://cses.fi/problemset/task/2097, 
// Given a list of stones with different weights, remove stones in pairs of the two heaviest stones until only one or no stones are left.

#include <iostream>
#include <queue>
#include <vector>

// Brute force approach with O(n^2) complexity
// std::vector<int> lastStoneWeight(std::vector<int>& stones) {
//     while (stones.size() > 1) {
//         int max1 = 0, max2 = 0, max1Index = 0, max2Index = 0;
//         for (int i = 0; i < stones.size(); i++) {
//             if (stones[i] > max1) {
//                 max2 = max1;
//                 max2Index = max1Index;
//                 max1 = stones[i];
//                 max1Index = i;
//             } else if (stones[i] > max2) {
//                 max2 = stones[i];
//                 max2Index = i;
//             }
//         }
//         stones.erase(stones.begin() + max1Index);
//         stones.erase(stones.begin() + max2Index - (max1Index < max2Index));
//         if (max1 != max2) {
//             stones.push_back(max1 - max2);
//         }
//     }
//     return stones;
// }

// Optimal solution with O(n log n) complexity
std::vector<int> lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int> pq;
    for (int stone : stones) {
        pq.push(stone);
    }
    while (pq.size() > 1) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if (x != y) {
            pq.push(x - y);
        }
    }
    std::vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}

int main() {
    std::vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    std::vector<int> result1 = lastStoneWeight(stones1);
    for (int stone : result1) {
        std::cout << stone << " ";
    }
    std::cout << std::endl;

    std::vector<int> stones2 = {1, 2};
    std::vector<int> result2 = lastStoneWeight(stones2);
    for (int stone : result2) {
        std::cout << stone << " ";
    }
    std::cout << std::endl;

    std::vector<int> stones3 = {1, 1, 1, 1};
    std::vector<int> result3 = lastStoneWeight(stones3);
    for (int stone : result3) {
        std::cout << stone << " ";
    }
    std::cout << std::endl;

    return 0;
}
```