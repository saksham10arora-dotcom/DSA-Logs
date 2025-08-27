```cpp
// Product of Array Except Self II, https://leetcode.com/problems/product-of-array-except-self/
// Given an array of integers, return an array of the same length where each element at index i is the product of all the numbers in the original array except the one at i.

#include <vector>
#include <numeric>

// Brute force approach with O(n^2) complexity
std::vector<int> productExceptSelfBruteForce(std::vector<int>& nums) {
    std::vector<int> result(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i != j) {
                result[i] *= nums[j];
            }
        }
    }
    return result;
}

// Optimal solution with O(n) complexity
std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, 1);
    // Calculate prefix product
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    // Calculate suffix product and multiply with prefix product
    int suffixProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffixProduct;
        suffixProduct *= nums[i];
    }
    return result;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4};
    std::vector<int> result1 = productExceptSelf(nums1);
    // Expected output: [24, 12, 8, 6]

    std::vector<int> nums2 = {2, 3, 4, 5};
    std::vector<int> result2 = productExceptSelf(nums2);
    // Expected output: [60, 40, 30, 24]

    std::vector<int> nums3 = {10, 20, 30, 40};
    std::vector<int> result3 = productExceptSelf(nums3);
    // Expected output: [24000, 12000, 8000, 6000]

    return 0;
}
```