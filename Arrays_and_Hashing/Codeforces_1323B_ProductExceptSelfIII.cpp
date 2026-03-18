```cpp
// Codeforces_1323B_ProductExceptSelfIII
// https://codeforces.com/contest/1323/problem/B
// Given an array of integers, calculate the product of all numbers except the number at each index.

#include <iostream>
#include <vector>

// Brute force approach with O(n^2) complexity
std::vector<long long> productExceptSelfBruteForce(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<long long> result(n);
    for (int i = 0; i < n; ++i) {
        long long product = 1;
        for (int j = 0; j < n; ++j) {
            if (i!= j) {
                product *= nums[j];
            }
        }
        result[i] = product;
    }
    return result;
}

// Optimal solution with O(n) complexity
std::vector<long long> productExceptSelfOptimal(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<long long> result(n, 1);
    // Calculate prefix products
    for (int i = 1; i < n; ++i) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    // Calculate suffix products and multiply with prefix products
    long long suffixProduct = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= suffixProduct;
        suffixProduct *= nums[i];
    }
    return result;
}

int main() {
    // Test case 1
    std::vector<int> nums1 = {1, 2, 3, 4};
    std::vector<long long> result1 = productExceptSelfOptimal(nums1);
    for (long long num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 2
    std::vector<int> nums2 = {2, 3, 4, 5};
    std::vector<long long> result2 = productExceptSelfOptimal(nums2);
    for (long long num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 3
    std::vector<int> nums3 = {10, 20, 30, 40};
    std::vector<long long> result3 = productExceptSelfOptimal(nums3);
    for (long long num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```