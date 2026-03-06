```cpp
// LeetCode problem 774: Bulb Switcher II
// https://leetcode.com/problems/bulb-switcher-ii/
// There are n bulbs, each represented by a number from 0 to n-1.
// Each bulb has four adjacent bulbs, which are the bulbs directly above, below, to the left, and to the right.
// If the i-th bulb is on, then the i-th bulb can be toggled on and off.
// If the i-th bulb is off, then 3 other bulbs which are all adjacent can be toggled on.
// Return the number of ways to turn on exactly k bulbs.

#include <iostream>
#include <vector>

// Brute force approach with O(4^n) complexity
class Solution_BruteForce {
public:
    int flipLights(int n, int k) {
        int result = 0;
        for (int i = 0; i < (1 << (2 * n)); i++) {
            int count = 0;
            std::vector<int> bulbs(n, 0);
            for (int j = 0; j < n; j++) {
                bulbs[j] = (i >> (2 * j)) & 3;
                count += (bulbs[j] > 0);
            }
            if (count == k) {
                result++;
            }
        }
        return result;
    }
};

// Optimal solution with O(1) complexity
class Solution {
public:
    int flipLights(int n, int k) {
        if (n == 0 || k == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return (k == 1) ? 3 : 4;
        if (k == 1) return 4;
        if (k == 2) return 7;
        return 8;
    }
};

int main() {
    Solution solution;
    std::cout << solution.flipLights(1, 1) << std::endl;  // Output: 1
    std::cout << solution.flipLights(2, 1) << std::endl;  // Output: 3
    std::cout << solution.flipLights(3, 1) << std::endl;  // Output: 4
    return 0;
}
```