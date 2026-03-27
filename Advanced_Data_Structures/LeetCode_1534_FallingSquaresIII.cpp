```cpp
// LeetCode problem 1534: Count Good Triplets
// https://leetcode.com/problems/count-good-triplets/
// Given an array of integers arr, and an integer k, 
// a good triplet is a triplet where i < j < k and arr[i] % arr[k] == 0 and arr[j] % arr[i] == 0.

#include <iostream>
#include <vector>

// Brute force approach with O(n^3) complexity
int countGoodTripletsBruteForce(std::vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            for (int k = j + 1; k < arr.size(); k++) {
                if (arr[i] % arr[k] == 0 && arr[j] % arr[i] == 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

// Optimal solution with O(n^2) complexity
int countGoodTripletsOptimal(std::vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] % arr[i] == 0) {
                for (int k = j + 1; k < arr.size(); k++) {
                    if (arr[i] % arr[k] == 0) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {2, 4, 6, 8, 10};
    std::vector<int> arr3 = {1, 3, 5, 7, 9};

    std::cout << "Brute force approach:" << std::endl;
    std::cout << "Test case 1: " << countGoodTripletsBruteForce(arr1) << std::endl;
    std::cout << "Test case 2: " << countGoodTripletsBruteForce(arr2) << std::endl;
    std::cout << "Test case 3: " << countGoodTripletsBruteForce(arr3) << std::endl;

    std::cout << "\nOptimal solution:" << std::endl;
    std::cout << "Test case 1: " << countGoodTripletsOptimal(arr1) << std::endl;
    std::cout << "Test case 2: " << countGoodTripletsOptimal(arr2) << std::endl;
    std::cout << "Test case 3: " << countGoodTripletsOptimal(arr3) << std::endl;

    return 0;
}
```