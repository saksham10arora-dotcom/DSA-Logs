```cpp
// Maximum Number Of Integers To Choose From A Range I, https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
// Given an array of integers nums and an integer k, return the maximum number of integers in the range [1, k] that can be chosen.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n*k) complexity
int maxIntegersBruteForce(std::vector<int>& nums, int k) {
    int count = 0;
    for (int i = 1; i <= k; i++) {
        bool found = false;
        for (int num : nums) {
            if (num % i == 0) {
                found = true;
                break;
            }
        }
        if (!found) count++;
    }
    return count;
}

// Optimal solution with O(n + k) complexity
int maxIntegersOptimal(std::vector<int>& nums, int k) {
    std::vector<bool> seen(k + 1, false);
    for (int num : nums) {
        if (num <= k) seen[num] = true;
    }
    for (int i = 2; i <= k; i++) {
        if (seen[i]) {
            for (int j = i; j <= k; j += i) {
                seen[j] = true;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= k; i++) {
        if (!seen[i]) count++;
    }
    return count;
}

int main() {
    std::vector<int> nums1 = {2, 3, 5};
    int k1 = 10;
    std::cout << "Test case 1: " << maxIntegersOptimal(nums1, k1) << std::endl;

    std::vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 5;
    std::cout << "Test case 2: " << maxIntegersOptimal(nums2, k2) << std::endl;

    std::vector<int> nums3 = {1};
    int k3 = 1;
    std::cout << "Test case 3: " << maxIntegersOptimal(nums3, k3) << std::endl;

    return 0;
}
```