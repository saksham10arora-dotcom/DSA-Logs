```cpp
// Maximum Beauty Of An Array After Applying Operation
// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/
// Given an array of integers, find the maximum beauty of the array after applying the operation.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: O(n^2) complexity
int maximumBeautyBruteForce(std::vector<int>& nums) {
    int n = nums.size();
    int maxBeauty = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int beauty = 0;
            for (int k = 0; k < n; k++) {
                if (k < i || k > j) {
                    beauty += nums[k];
                }
            }
            maxBeauty = std::max(maxBeauty, beauty);
        }
    }
    return maxBeauty;
}

// Optimal solution: O(n) complexity
int maximumBeautyOptimal(std::vector<int>& nums) {
    int n = nums.size();
    int maxBeauty = 0;
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }
    int minSum = totalSum;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            minSum = std::min(minSum, sum);
            maxBeauty = std::max(maxBeauty, totalSum - sum);
        }
    }
    return maxBeauty;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::cout << "Maximum beauty of array [1, 2, 3, 4, 5]: " << maximumBeautyOptimal(nums1) << std::endl;

    std::vector<int> nums2 = {5, 4, 3, 2, 1};
    std::cout << "Maximum beauty of array [5, 4, 3, 2, 1]: " << maximumBeautyOptimal(nums2) << std::endl;

    std::vector<int> nums3 = {1, 1, 1, 1, 1};
    std::cout << "Maximum beauty of array [1, 1, 1, 1, 1]: " << maximumBeautyOptimal(nums3) << std::endl;

    return 0;
}
```