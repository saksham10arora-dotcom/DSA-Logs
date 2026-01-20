```cpp
// Max Sliding Window Advanced, https://cses.fi/problemset/task/1323, 
// Given an array of n integers and an integer k, find the maximum value in each k-sized subarray.

#include <iostream>
#include <deque>
#include <vector>

// Brute force approach with O(n*k) complexity
std::vector<int> maxSlidingWindowBruteForce(const std::vector<int>& arr, int k) {
    std::vector<int> result;
    for (int i = 0; i <= arr.size() - k; i++) {
        int maxVal = arr[i];
        for (int j = 1; j < k; j++) {
            maxVal = std::max(maxVal, arr[i + j]);
        }
        result.push_back(maxVal);
    }
    return result;
}

// Optimal solution with O(n) complexity
std::vector<int> maxSlidingWindowOptimal(const std::vector<int>& arr, int k) {
    std::vector<int> result;
    std::deque<int> dq;
    for (int i = 0; i < arr.size(); i++) {
        // Remove elements out of the current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        // Remove elements smaller than the current element
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        // Add the maximum element of the current window to the result
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 3;
    std::vector<int> result1 = maxSlidingWindowOptimal(arr1, k1);
    for (int val : result1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = {5, 4, 3, 2, 1};
    int k2 = 2;
    std::vector<int> result2 = maxSlidingWindowOptimal(arr2, k2);
    for (int val : result2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr3 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k3 = 3;
    std::vector<int> result3 = maxSlidingWindowOptimal(arr3, k3);
    for (int val : result3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```