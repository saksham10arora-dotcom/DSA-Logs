```cpp
// LeetCode problem 3513: Number Of Unique Xor Triplets I
// https://leetcode.com/problems/number-of-unique-xor-triplets-i/
// Given an array of integers, find the number of unique triplets (a, b, c) such that a ^ b ^ c = 0.

#include <iostream>
#include <vector>
#include <unordered_set>

// Brute force approach with O(n^3) complexity
int xorTripletsBruteForce(std::vector<int>& arr) {
    std::unordered_set<int> triplets;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            for (int k = j + 1; k < arr.size(); k++) {
                int xorResult = arr[i] ^ arr[j] ^ arr[k];
                if (xorResult == 0) {
                    std::vector<int> triplet = {arr[i], arr[j], arr[k]};
                    std::sort(triplet.begin(), triplet.end());
                    triplets.insert(std::hash<std::vector<int>>{}(triplet));
                }
            }
        }
    }
    return triplets.size();
}

// Optimal solution with O(n^2) complexity
int xorTripletsOptimal(std::vector<int>& arr) {
    std::unordered_set<int> triplets;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            int xorResult = arr[i] ^ arr[j];
            for (int k = j + 1; k < arr.size(); k++) {
                if ((xorResult ^ arr[k]) == 0) {
                    std::vector<int> triplet = {arr[i], arr[j], arr[k]};
                    std::sort(triplet.begin(), triplet.end());
                    triplets.insert(std::hash<std::vector<int>>{}(triplet));
                }
            }
        }
    }
    return triplets.size();
}

int main() {
    std::vector<int> arr1 = {2, 3, 1, 6, 7};
    std::vector<int> arr2 = {1, 1, 2, 2, 3};
    std::vector<int> arr3 = {1, 2, 3, 4, 5};

    std::cout << "Number of unique XOR triplets in arr1 (brute force): " << xorTripletsBruteForce(arr1) << std::endl;
    std::cout << "Number of unique XOR triplets in arr2 (brute force): " << xorTripletsBruteForce(arr2) << std::endl;
    std::cout << "Number of unique XOR triplets in arr3 (brute force): " << xorTripletsBruteForce(arr3) << std::endl;

    std::cout << "Number of unique XOR triplets in arr1 (optimal): " << xorTripletsOptimal(arr1) << std::endl;
    std::cout << "Number of unique XOR triplets in arr2 (optimal): " << xorTripletsOptimal(arr2) << std::endl;
    std::cout << "Number of unique XOR triplets in arr3 (optimal): " << xorTripletsOptimal(arr3) << std::endl;

    return 0;
}
```